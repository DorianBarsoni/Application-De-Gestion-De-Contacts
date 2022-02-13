#include "feuillecontact.h"
#include <QDebug>

/**
*@brief Constructeur par défaut de FeuilleContact
*/
FeuilleContact::FeuilleContact(QWidget *parent) : QWidget(parent)
{

}

/**
*@brief Constructeur de FeuilleContact qui prend en argument un élément GestionContact et un id
*/
FeuilleContact::FeuilleContact(GestionContact* gc, int id)
{
    //L'id
    this->id = id;

    //Les Layouts
    mainLayout = new QVBoxLayout();
    layoutLabelQLE = new QHBoxLayout();
    layoutLabel = new QVBoxLayout();
    layoutQLE = new QVBoxLayout();
    layoutInteractions = new QVBoxLayout();
    layoutBoutons = new QHBoxLayout();

    //Les Labels
    lnom = new QLabel("Nom :");
    lprenom = new QLabel("Prenom :");
    lentreprise = new QLabel("Entreprise :");
    lmail = new QLabel("Mail :");
    ltelephone = new QLabel("Telephone :");
    lphoto = new QLabel("Photo :");
    linteractions = new QLabel("Interactions :");

    //Récupération des infos du contact
    for(auto it : gc->getListeContacts())
    {
        if(it.getId() == id)
        {
            nom = QString::fromStdString(it.getNom());
            prenom = QString::fromStdString(it.getPrenom());
            entreprise = QString::fromStdString(it.getEntreprise());
            mail = QString::fromStdString(it.getMail());
            for(auto it2 : it.getTelephone())
            {
                telephone += QString::fromStdString(to_string(it2));
            }
            photo = QString::fromStdString(it.getPhoto());
        }
    }

    //Les LineEdits
    QLEnom = new QLineEdit(nom);
    QLEprenom = new QLineEdit(prenom);
    QLEentreprise = new QLineEdit(entreprise);
    QLEmail = new QLineEdit(mail);
    QLEtelephone = new QLineEdit(telephone);
    QLEphoto = new QLineEdit(photo);

    //Le QListWidget
    interactions = new QListWidget();
    majInteractions(gc, id);

    //Les Boutons
    bAjoutInteraction = new QPushButton("Ajouter une interaction");
    bEnregistrer = new QPushButton("Enregistrer le Contact");
    bSupprimer = new QPushButton("Supprimer le Contact");
    bFermer = new QPushButton("Fermer");

    //Position des widgets dans les layouts
    layoutLabel->addWidget(lnom);
    layoutQLE->addWidget(QLEnom);

    layoutLabel->addWidget(lprenom);
    layoutQLE->addWidget(QLEprenom);

    layoutLabel->addWidget(lentreprise);
    layoutQLE->addWidget(QLEentreprise);

    layoutLabel->addWidget(lmail);
    layoutQLE->addWidget(QLEmail);

    layoutLabel->addWidget(ltelephone);
    layoutQLE->addWidget(QLEtelephone);

    layoutLabel->addWidget(lphoto);
    layoutQLE->addWidget(QLEphoto);

    layoutBoutons->addWidget(bEnregistrer);
    layoutBoutons->addWidget(bSupprimer);
    layoutBoutons->addWidget(bFermer);

    layoutLabelQLE->addLayout(layoutLabel);
    layoutLabelQLE->addLayout(layoutQLE);

    layoutInteractions->addWidget(linteractions);
    layoutInteractions->addWidget(interactions);
    layoutInteractions->addWidget(bAjoutInteraction);

    mainLayout->addLayout(layoutLabelQLE);
    mainLayout->addLayout(layoutInteractions);
    mainLayout->addLayout(layoutBoutons);

    setLayout(mainLayout);

    //Connect
    connect(bFermer, SIGNAL(clicked()), this, SLOT(close()));
}

/**
 * @brief Fonction permettant de mettre à jour la QListWidget des interactions
 */
void FeuilleContact::majInteractions(GestionContact* gc, int id)
{
    //On parcourt la liste de contacts
    for(auto it : gc->getListeContacts())
    {
        //Quand on trouve le bon contact
        if(id == it.getId())
        {
            //On crée un QString et une on récupère la liste d'interactions du contact qu'on trie
            QString s;
            list<Interaction> inte = it.getInteractions();
            inte.sort();
            //On parcours les interactions
            for(auto it : inte)
            {
                //On les range dans un QString
                s = QString::fromStdString(it.getContenu() + " " + to_string(it.getDate().getJour()) +"/"+ to_string(it.getDate().getMois()) +"/"+ to_string(it.getDate().getAnnee()) );

                //On crée un item à partir de ce QString
                QListWidgetItem* item = new QListWidgetItem(s);

                //On crée un QVariant contenant l'id du contact
                QVariant variant;
                variant.setValue(it.getId());
                item->setData(Qt::UserRole, variant);

                //On ajoute l'item à la QListWidget
                interactions->addItem(item);
            }
        }
    }
}

