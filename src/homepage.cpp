#include "homepage.h"
#include <QDebug>
#include <QListWidgetItem>

/**
*@brief Constructeur par défaut de HomePage
*/
HomePage::HomePage(QWidget *parent) : QWidget(parent)
{

}

/**
*@brief Constructeur de HomePage qui prend en argument un élément GestionContact
*/
HomePage::HomePage(GestionContact gc)
{
    //Les Layouts
    mainLayout = new QVBoxLayout();
    layoutLabelBarreRecherche = new QVBoxLayout();
    layoutRecherche = new QHBoxLayout();
    layoutResultatEtBouton = new QVBoxLayout();

    //Les Labels
    recherche = new QLabel();
    recherche->setText("Recherche");

    //Les LineEdits
    QLErecherche = new QLineEdit();

    //La ListView
    resultat = new QListWidget();

    //Les Boutons
    bRecherche = new QPushButton();
    bNouveauContact = new QPushButton("Nouveau Contact");

    //Image bouton de recherche
    bRecherche->setIcon(QIcon("C:/Users/dbars/Desktop/Cours/L3/CDAA/Projet/images/loupe.png"));
    bRecherche->setIconSize(QSize(22, 22));
    bRecherche->setFixedSize(QSize(22, 22));

    //Ajout dans les layouts
    layoutRecherche->addWidget(QLErecherche);
    layoutRecherche->addWidget(bRecherche);

    layoutLabelBarreRecherche->addWidget(recherche);
    layoutLabelBarreRecherche->addLayout(layoutRecherche);

    //layoutResultatEtBouton->addWidget(resultat);
    layoutResultatEtBouton->addWidget(resultat);
    layoutResultatEtBouton->addWidget(bNouveauContact);

    mainLayout->addLayout(layoutLabelBarreRecherche);
    mainLayout->addLayout(layoutResultatEtBouton);

    //Mise en place du layout principal
    setLayout(mainLayout);

    majQLW(gc);
}

/**
 * @brief Fonction permettant de mettre à jour la QListWidget des contacts
 */
void HomePage::majQLW(GestionContact gc)
{
    //On parcourt la liste de contacts
    for(auto it : gc.getListeContacts())
    {
        //On met le Nom et le Prénom dans un QString
        QString s = QString::fromStdString(it.getNom() + " " + it.getPrenom());

        //On crée un item à partir de ce QString
        QListWidgetItem* item = new QListWidgetItem(s);

        //On crée un QVariant contenant l'id du contact
        QVariant variant;
        variant.setValue(it.getId());
        item->setData(Qt::UserRole, variant);

        //On ajoute l'item à la QListWidget
        resultat->addItem(item);
    }
}
