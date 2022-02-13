#include "nouveaucontact.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

/**
*@brief Constructeur par défaut de NouveauContact
*/
NouveauContact::NouveauContact(QWidget *parent) : QWidget(parent)
{
    //Les Layouts
    mainLayout = new QVBoxLayout();
    layoutInfos = new QVBoxLayout();
    layoutBoutons = new QHBoxLayout();

    //Les Labels
    nom = new QLabel();
    nom->setText("Nom :");
    prenom = new QLabel();
    prenom->setText("Prénom :");
    entreprise = new QLabel();
    entreprise->setText("Entreprise :");
    mail = new QLabel();
    mail->setText("Mail :");
    telephone = new QLabel();
    telephone->setText("Téléphone :");
    photo = new QLabel();
    photo->setText("Photo :");

    //Les LineEdits
    QLEnom = new QLineEdit();
    QLEprenom = new QLineEdit();
    QLEentreprise = new QLineEdit();
    QLEmail = new QLineEdit();
    QLEtelephone = new QLineEdit();
    QLEphoto = new QLineEdit();

    //Les Boutons
    bRetour = new QPushButton("Retour");
    bAjout = new QPushButton("Ajouter");

    //Ajout dans les layouts
    layoutInfos->addWidget(nom);
    layoutInfos->addWidget(QLEnom);
    layoutInfos->addWidget(prenom);
    layoutInfos->addWidget(QLEprenom);
    layoutInfos->addWidget(entreprise);
    layoutInfos->addWidget(QLEentreprise);
    layoutInfos->addWidget(mail);
    layoutInfos->addWidget(QLEmail);
    layoutInfos->addWidget(telephone);
    layoutInfos->addWidget(QLEtelephone);
    layoutInfos->addWidget(photo);
    layoutInfos->addWidget(QLEphoto);

    layoutBoutons->addWidget(bRetour);
    layoutBoutons->addWidget(bAjout);

    mainLayout->addLayout(layoutInfos);
    mainLayout->addLayout(layoutBoutons);

    //Mise en place du layout principal
    this->setLayout(mainLayout);
}
