#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nouveaucontact.h"
#include "feuillecontact.h"
#include <iostream>
#include <QDebug>
#include <QStringListModel>
#include <QModelIndex>

/**
*@brief Constructeur par défaut de MainWindow
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Création des Widgets
    nouveauContact = new NouveauContact();
    homePage = new HomePage(gc);
    feuilleContact = new FeuilleContact();
    ajoutInteraction = new AjoutInteraction();
    ajoutTodo = new AjoutTodo();

    //db = new DataBase();

    //Connect
    connect(this->homePage->bNouveauContact, SIGNAL(clicked()), this, SLOT(switchFromHomePageToNewContact()));
    connect(this->homePage->bRecherche, SIGNAL(clicked()), this, SLOT(recherche()));

    this->setCentralWidget(homePage);
}

/**
*@brief Destructeur de MainWindow
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/**
*@brief Slot permettant de passer du widget principal au widget d'ajout de contact
*/
void MainWindow::switchFromHomePageToNewContact()
{
    nouveauContact = new NouveauContact();
    connect(this->nouveauContact->bRetour, SIGNAL(clicked()), this, SLOT(switchFromNewContactToHomePage()));
    connect(this->nouveauContact->bAjout, SIGNAL(clicked()), this, SLOT(ajoutContact()));
    this->setCentralWidget(nouveauContact);
}

/**
*@brief Slot permettant de passer du widget d'ajout de contact au widget principal
*/
void MainWindow::switchFromNewContactToHomePage()
{
    homePage = new HomePage(this->gc);
    connect(this->homePage->bNouveauContact, SIGNAL(clicked()), this, SLOT(switchFromHomePageToNewContact()));
    connect(this->homePage->resultat, SIGNAL(clicked(QModelIndex)), this, SLOT(clickedInQListWidgetItem(QModelIndex)));
    connect(this->homePage->bRecherche, SIGNAL(clicked()), this, SLOT(recherche()));
    this->setCentralWidget(homePage);
}

/**
*@brief Slot permettant d'ajouter un contact
*/
void MainWindow::ajoutContact()
{
    //On récupère les variables dans les QLineEdit
    std::string nom = this->nouveauContact->QLEnom->text().toStdString();
    std::string prenom = this->nouveauContact->QLEprenom->text().toStdString();
    std::string entreprise = this->nouveauContact->QLEentreprise->text().toStdString();
    std::string mail = this->nouveauContact->QLEmail->text().toStdString();
    std::string telephone = this->nouveauContact->QLEtelephone->text().toStdString();
    std::string photo = this->nouveauContact->QLEphoto->text().toStdString();

    //On crée la list d'int pour le téléphone
    std::list<int> tel;
    for(unsigned long long i=0; i<telephone.length(); i++)
    {
        char num = telephone[i];
        tel.push_back((int(num)-48));
    }

    //On crée le contact et on l'ajoute à GestionContact
    Contact c = Contact(gc.getId(), 0, nom, prenom, entreprise, mail, tel, photo, {});
    gc += c;
}

/**
*@brief Slot permettant de rechercher un contact
*/
void MainWindow::recherche()
{

}

/**
*@brief Slot permettant d'ouvrir le widget de modification d'un contact lors d'un clique dans la QListWidgetItem
*/
void MainWindow::clickedInQListWidgetItem(QModelIndex qmi)
{
    QList<QListWidgetItem*> selectedLigne = homePage->resultat->selectedItems();
    QVariant v = selectedLigne[0]->data(Qt::UserRole);
    int id = v.value<int>();

    delete feuilleContact;
    feuilleContact = new FeuilleContact(&gc, id);
    feuilleContact->setVisible(true);
    connect(feuilleContact->bEnregistrer, SIGNAL(clicked()), this, SLOT(enregistrerContact()));
    connect(feuilleContact->bSupprimer, SIGNAL(clicked()), this, SLOT(supprimerContact()));
    connect(feuilleContact->bAjoutInteraction, SIGNAL(clicked()), this, SLOT(nouvelleInteraction()));
    connect(feuilleContact->interactions, SIGNAL(clicked(QModelIndex)), this, SLOT(clickedInInteractionList(QModelIndex)));
    connect(this, SIGNAL(suppContact()), feuilleContact, SLOT(close()));

    qDebug() <<id <<qmi.data().toString();
}

/**
*@brief Slot permettant d'enregistrer les modifications d'un contact
*/
void MainWindow::enregistrerContact()
{
    //On récupère les infos dans les QLineEdit
    std::string nom = this->feuilleContact->QLEnom->text().toStdString();
    std::string prenom = this->feuilleContact->QLEprenom->text().toStdString();
    std::string entreprise = this->feuilleContact->QLEentreprise->text().toStdString();
    std::string mail = this->feuilleContact->QLEmail->text().toStdString();
    std::string telephone = this->feuilleContact->QLEtelephone->text().toStdString();
    std::string photo = this->feuilleContact->QLEphoto->text().toStdString();

    //On parcourt gc à la recherche du contact modifié
    int id = feuilleContact->id;
    //On crée la list d'int pour le téléphone
    std::list<int> tel;
    for(auto it : gc.getListeContacts())
    {
        //Quand on trouve le contact
        if(id == it.getId())
        {
            //On le retire de la liste de contacts
            gc -= it;

            //On apporte les modifications à l'itérateur
            if(nom != it.getNom()) it.setNom(nom);
            if(prenom != it.getPrenom()) it.setPrenom(prenom);
            if(entreprise != it.getEntreprise()) it.setEntreprise(entreprise);
            if(mail != it.getMail()) it.setMail(mail);
            for(unsigned long long i=0; i<telephone.length(); i++)
            {
                char num = telephone[i];
                tel.push_back((int(num)-48));
            }
            if(tel != it.getTelephone()) it.setTelephone(tel);
            if(photo != it.getPhoto()) it.setPhoto(photo);

            //On rajoute le contact dans la liste de contacts
            gc += it;
        }
    }
    homePage->resultat->clear();
    homePage->majQLW(gc);
    feuilleContact->interactions->clear();
    feuilleContact->majInteractions(&gc, id);
    qDebug() << "Modification enregistrée";
}

/**
*@brief Slot permettant de supprimer un contact
*/
void MainWindow::supprimerContact()
{
    int id = feuilleContact->id;
    for(auto it : gc.getListeContacts())
    {
        if(id == it.getId())
        {
            gc -= it;
        }
    }
    homePage->resultat->clear();
    homePage->majQLW(gc);
    emit suppContact();
    qDebug() <<"Contact supprimé";
}

/**
*@brief Slot permettant d'ouvrir le widget permettant la création/modification d'une interaction
*/
void MainWindow::nouvelleInteraction()
{
    delete ajoutInteraction;
    ajoutInteraction = new AjoutInteraction(Interaction());
    ajoutInteraction->setVisible(true);

    connect(ajoutInteraction->bEnregistrer, SIGNAL(clicked()), this, SLOT(enregistrerInteraction()));
    connect(ajoutInteraction->bSupprimer, SIGNAL(clicked()), this, SLOT(supprimerInteraction()));
    connect(this, SIGNAL(suppInteraction()), ajoutInteraction, SLOT(close()));
    connect(ajoutInteraction->bAjoutTodo, SIGNAL(clicked()), this, SLOT(nouveauTodo()));
}

/**
*@brief Slot permettant d'enregistrer une interaction
*/
void MainWindow::enregistrerInteraction()
{
    std::string contenu = ajoutInteraction->QLEcontenu->text().toStdString();
    std::string jj = ajoutInteraction->QLEjj->text().toStdString();
    std::string mm = ajoutInteraction->QLEmm->text().toStdString();
    std::string aa = ajoutInteraction->QLEaa->text().toStdString();
    Date d;

    if(jj == "" || mm == "" || aa == "") d = Date();
    else d = Date(stoi(jj), stoi(mm), stoi(aa));

    for(auto it : gc.getListeContacts())
    {
        if(it.getId() == feuilleContact->id)
        {
            gc -= it;
            Contact c = it;
            list<Interaction> linte = it.getInteractions();
            int id = -1;
            for(auto it2 : c.getInteractions())
            {
                if(it2.getId() == ajoutInteraction->id)
                {
                    id = ajoutInteraction->id;
                    linte.remove(it2);
                }
            }
            if(id == -1)
            {
                c.setInteractions(linte);
                Interaction inte = Interaction(c.getIdInte(), contenu, d);
                ajoutInteraction->id = c.getIdInte();
                c.addInteraction(inte);
            }
            else
            {
                linte.push_back(Interaction(id, contenu, d));
                c.setInteractions(linte);
            }

            gc += c;

            feuilleContact->interactions->clear();
            feuilleContact->majInteractions(&gc, feuilleContact->id);
        }
    }
    qDebug() <<"Nouvelle interaction enregistrée";
}

/**
*@brief Slot permettant de supprimer une interaction
*/
void MainWindow::supprimerInteraction()
{
    for(auto it : gc.getListeContacts())
    {
        if(it.getId() == feuilleContact->id)
        {
            gc -= it;
            Contact c = it;

            for(auto it2 : it.getInteractions())
            {
                if(it2.getId() == ajoutInteraction->id)
                {
                    list<Interaction> linte = c.getInteractions();
                    linte.remove(it2);
                    c.setInteractions(linte);
                }
            }

            gc += c;
            feuilleContact->interactions->clear();
            feuilleContact->majInteractions(&gc, feuilleContact->id);
            emit suppInteraction();
        }
    }
    qDebug() <<"Interaction Supprimée";
}

/**
*@brief Slot permettant d'ouvrir un widget AjoutInteraction quand on clique dans la QListWidget Interaction
*/
void MainWindow::clickedInInteractionList(QModelIndex qmi)
{
    QList<QListWidgetItem*> selectedLigne = feuilleContact->interactions->selectedItems();
    QVariant v = selectedLigne[0]->data(Qt::UserRole);
    int id = v.value<int>();

    qDebug() << id << " " << qmi.data().toString();

    for(auto it : gc.getListeContacts())
    {
        if(it.getId() == feuilleContact->id)
        {
            for(auto it2 : it.getInteractions())
            {
                if(id == it2.getId())
                {
                    delete ajoutInteraction;
                    ajoutInteraction = new AjoutInteraction(it2);
                    ajoutInteraction->setVisible(true);

                    connect(ajoutInteraction->bEnregistrer, SIGNAL(clicked()), this, SLOT(enregistrerInteraction()));
                    connect(ajoutInteraction->bSupprimer, SIGNAL(clicked()), this, SLOT(supprimerInteraction()));
                    connect(this, SIGNAL(suppInteraction()), ajoutInteraction, SLOT(close()));
                    connect(ajoutInteraction->bAjoutTodo, SIGNAL(clicked()), this, SLOT(nouveauTodo()));
                    connect(ajoutInteraction->todo, SIGNAL(clicked(QModelIndex)), this, SLOT(clickedInTodoList(QModelIndex)));
                }
            }
        }
    }
}

/**
*@brief Slot permettant d'ouvrir un widget AjoutTodo pour ajouter un Todo à une interaction
*/
void MainWindow::nouveauTodo()
{
    for(auto it : gc.getListeContacts())
    {
        if(it.getId() == feuilleContact->id)
        {
            for(auto it2 : it.getInteractions())
            {
                //qDebug() << ajoutInteraction->id;
                if(it2.getId() == ajoutInteraction->id)
                {
                    delete ajoutTodo;
                    ajoutTodo = new AjoutTodo(it2.getIdTodo());
                    ajoutTodo->setVisible(true);

                    connect(ajoutTodo->bEnregistrer, SIGNAL(clicked()), this, SLOT(enregistrerTodo()));
                    connect(ajoutTodo->bSupprimer, SIGNAL(clicked()), this, SLOT(supprimerTodo()));
                    connect(this, SIGNAL(suppTodo()), ajoutTodo, SLOT(close()));
                }
            }
        }
    }
}

/**
*@brief Slot permettant d'enregistrer un Todo
*/
void MainWindow::enregistrerTodo()
{
    for(auto it : gc.getListeContacts())
    {
        if(it.getId() == feuilleContact->id)
        {
            for(auto it2 : it.getInteractions())
            {
                if(it2.getId() == ajoutInteraction->id)
                {
                    std::string contenu = ajoutTodo->QLEcontenu->text().toStdString();
                    std::string jj = ajoutTodo->QLEjj->text().toStdString();
                    std::string mm = ajoutTodo->QLEmm->text().toStdString();
                    std::string aa = ajoutTodo->QLEaa->text().toStdString();
                    Date d;

                    if(jj == "" || mm == "" || aa == "") d = Date();
                    else d = Date(stoi(jj), stoi(mm), stoi(aa));

                    int id = -1;
                    list<Todo> ltodo = it2.getTodo();
                    Interaction inte = it2;
                    list<Interaction> linte = it.getInteractions();

                    for(auto it3 : it2.getTodo())
                    {
                        if(it3.getId() == ajoutTodo->id)
                        {
                            id = ajoutTodo->id;
                            ltodo.remove(it3);
                        }
                    }

                    if(id == -1)
                    {
                        Todo todo = Todo(inte.getIdTodo(), contenu, d);
                        inte.addTodo(todo);
                    }
                    else
                    {
                        Todo todo = Todo(id, contenu, d);
                        ltodo.push_back(todo);
                        inte.setTodo(ltodo);
                    }

                    linte.remove(inte);
                    linte.push_back(inte);

                    Contact c = it;
                    gc -= c;
                    c.setInteractions(linte);
                    gc += c;
                    ajoutInteraction->todo->clear();
                    ajoutInteraction->majTodo(inte);
                }
            }
        }
    }
    qDebug() <<"Enregistrer Todo";
}

/**
*@brief Slot permettant de supprimer un Todo
*/
void MainWindow::supprimerTodo()
{
    for(auto it : gc.getListeContacts())
    {
        if(it.getId() == feuilleContact->id)
        {
            for(auto it2 : it.getInteractions())
            {
                if(it2.getId() == ajoutInteraction->id)
                {
                    for(auto it3 : it2.getTodo())
                    {
                        if(it3.getId() == ajoutTodo->id)
                        {
                            Todo todo = it3;
                            list<Todo> ltodo = it2.getTodo();
                            ltodo.remove(todo);

                            Interaction inte = it2;
                            list<Interaction> linte = it.getInteractions();
                            linte.remove(inte);
                            inte.setTodo(ltodo);
                            linte.push_back(inte);

                            Contact c = it;
                            gc -= c;
                            c.setInteractions(linte);
                            gc += c;

                            ajoutInteraction->todo->clear();
                            ajoutInteraction->majTodo(inte);

                            emit suppTodo();
                        }
                    }
                }
            }
        }
    }
}

/**
*@brief Slot permettant d'ouvrir un widget AjoutTodo du Todo sur lequel on clique
*/
void MainWindow::clickedInTodoList(QModelIndex qmi)
{
    QList<QListWidgetItem*> selectedLigne = ajoutInteraction->todo->selectedItems();
    QVariant v = selectedLigne[0]->data(Qt::UserRole);
    int id = v.value<int>();

    for(auto it : gc.getListeContacts())
    {
        if(it.getId() == feuilleContact->id)
        {
            for(auto it2 : it.getInteractions())
            {
                if(it2.getId() == ajoutInteraction->id)
                {
                    for(auto it3 : it2.getTodo())
                    {
                        if(it3.getId() == id)
                        {
                            delete ajoutTodo;
                            ajoutTodo = new AjoutTodo(it3);
                            ajoutTodo->setVisible(true);

                            connect(ajoutTodo->bEnregistrer, SIGNAL(clicked()), this, SLOT(enregistrerTodo()));
                            connect(ajoutTodo->bSupprimer, SIGNAL(clicked()), this, SLOT(supprimerTodo()));
                            connect(this, SIGNAL(suppTodo()), ajoutTodo, SLOT(close()));
                        }
                    }
                }
            }
        }
    }

    qDebug() << id << " " << qmi.data().toString();
}

