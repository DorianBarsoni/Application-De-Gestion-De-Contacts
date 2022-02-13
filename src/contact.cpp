#include <iostream>
#include <string>
#include <list>

#include "contact.h"
#include "date.h"
#include "interaction.h"

//CONSTRUCTEURS

/**
*@brief Constructeur par défaut de Contact
*/
Contact::Contact()
{
    this->id = -1;
    this->id_inte = 0;
    this->nom = "";
    this->prenom = "";
    this->entreprise = "";
    this->mail = "";
    this->telephone = {};
    this->photo = "";
    this->dateCreation = Date();
}

/**
*@brief Constructeur de Contact prenant en paramètre l'id, le nom, le prénom, l'entreprise, le mail, le téléphone, la photo et la liste d'interactions
*/
Contact::Contact(int id, int id_inte, string nom, string prenom, string entreprise, string mail, list<int> telephone, string photo, list<Interaction> interactions)
{
    this->id = id;
    this->id_inte = id_inte;
    this->nom = nom;
    this->prenom = prenom;
    this->entreprise = entreprise;
    this->mail = mail;
    this->telephone = telephone;
    this->photo = photo;
    this->dateCreation = Date();
    this->dateModification = Date();
    this->interactions = interactions;
}

/**
*@brief Destructeur de la clasee Contact
*/
Contact::~Contact()
{
    this->telephone.clear();
    this->interactions.clear();
}


//GETTERS

/**
*@brief Fonction permettant de retourner l'id d'un Contact
*@return Retourne l'id d'un Contact
*/
int Contact::getId() const
{
    return this->id;
}

/**
*@brief Fonction permettant de retourner la prochaine id  des interactions
*@return Retourne la prochaine id des interaction
*/
int Contact::getIdInte() const
{
    return this->id_inte;
}

/**
*@brief Fonction permettant d'obtenir le Nom d'un Contact
*@return Retourne le Nom d'un contact (string)
*/
string Contact::getNom() const
{
    return this->nom;
}

/**
*@brief Fonction permettant d'obtenir le Prénom d'un Contact
*@return Retourne le prénom d'un Contact (string)
*/
string Contact::getPrenom() const
{
    return this->prenom;
}

/**
*@brief Fonction permettant d'obtenir l'Entreprise d'un Contact
*@return Retourne l'Entreprise d'un Contact (string)
*/
string Contact::getEntreprise() const
{
    return this->entreprise;
}

/**
*@brief Fonction permettant de retourner le Mail d'un Contact
*@return Retourne le Mail d'un Contact (string)
*/
string Contact::getMail() const
{
    return this->mail;
}

/**
*@brief Fonction permettant de retourner le numéro de Téléphone d'un Contact
*@return Retourne le numéro de téléphone d'une Contact (list<int>)
*/
list<int> Contact::getTelephone() const
{
    return this->telephone;
}

/**
*@brief Fonction permettant de retourner l'adresse URI de la Photo d'un Contact
*@return Retourne l'adresse URI de la photo d'un Contact (string)
*/
string Contact::getPhoto() const
{
    return this->photo;
}

/**
*@brief Fonction permettant de retourner la Date de Création d'un Contact
*@return Retourne la Date de Création d'un Contact (Date)
*/
Date Contact::getDateCreation() const
{
    return this->dateCreation;
}

/**
*@brief Fonction permettant de retourner la Date de Modification d'un Contact
*@return Retourne la Date de Modification d'un Contact (Date)
*/
Date Contact::getDateModification() const
{
    return this->dateModification;
}

/**
*@brief Fonction permettant de retourner la Liste d'Interactions d'un Contact
*@return Retourne la Liste d'Interaction d'un Contact (list<Interaction>)
*/
list<Interaction> Contact::getInteractions() const
{
    return this->interactions;
}

//SETTERS

/**
*@brief Fonction permettant de modifier l'id d'un Contact
*/
void Contact::setId(int id)
{
    this->id = id;
    updateContact("Modification de l'id");
}

/**
*@brief Fonction permettant de modifier la prochaine id des interactions d'un contact
*/
void Contact::setIdInte(int id_inte)
{
    this->id_inte = id_inte;
    updateContact("Modification de l'id des interactions");
}

/**
*@brief Fonction permettant de modifier le Nom d'un Contact
*/
void Contact::setNom(string nom)
{
    this->nom = nom;
    updateContact("Modification du Nom");
}

/**
*@brief Fonction permettant de modifier le Prénom d'un Contact
*/
void Contact::setPrenom(string prenom)
{
    this->prenom = prenom;
    updateContact("Modification du Prenom");
}

/**
*@brief Fonction permettant de modifier l'Entreprise d'un Contact
*/
void Contact::setEntreprise(string entreprise)
{
    this->entreprise = entreprise;
    updateContact("Modification de l'Entreprise");
}

/**
*@brief Fonction permettant de modifier le Mail d'un Contact
*/
void Contact::setMail(string mail)
{
    this->mail = mail;
    updateContact("Modification du Mail");
}

/**
*@brief Fonction permettant de modifier le numéro de Téléphone d'un Contact
*/
void Contact::setTelephone(list<int> telephone)
{
    this->telephone = telephone;
    updateContact("Modification du Telephone");
}

/**
*@brief Fonction permettant de modifier l'adresse URI de la Photo d'un Contact
*/
void Contact::setPhoto(string photo)
{
    this->photo = photo;
    updateContact("Modification de la Photo");
}

/**
*@brief Fonction permettant de modifier la Date de Création d'un Contact
*/
void Contact::setDateCreation(Date dateCreation)
{
    this->dateCreation = dateCreation;
    updateContact("Modification de la Date de Creation");
}

/**
*@brief Fonction permettant de modifier la Date de Modification d'un Contact
*/
void Contact::setDateModification(Date dateModification)
{
    this->dateModification = dateModification;
}

/**
*@brief Fonction permettant de changer la Liste d'Interaction d'un Contact
*/
void Contact::setInteractions(list<Interaction> interactions)
{
    this->interactions = interactions;
    updateContact("Modification de la Liste d'Interactions");
}


//SURCHARGE OPERATEUR<<

/**
*@brief Surcharge de l'opérateur << permettant d'afficher un contact
*@return Retourne une référence sur un flux de sorti (ostream&)
*/
ostream& operator<<(ostream& s, const Contact& c)
{
    s <<"Nom : "<<c.getNom()<<endl;
    s <<"Prenom : "<<c.getPrenom()<<endl;
    s <<"Entreprise : "<<c.getEntreprise()<<endl;
    s <<"Mail : "<<c.getMail()<<endl;
    s <<"Telephone : ";

    //Pour l'affichage du numéro de téléphone, on déclare i=0
    //On affiche un point entre les numéros chaque fois que
    //i%2=0 sauf si i==0
    int i = 0;
    for(int n : c.getTelephone())
    {
        if(i!=0 && i%2==0) s<<".";
        s <<n;
        i++;
    }
    s <<endl;
    
    s <<"Photo : "<<c.getPhoto()<<endl;
    s <<"Date de creation : "<<c.getDateCreation();
    s <<"Date de modification : "<<c.getDateModification();

    //On récuère la liste d'interaction qu'on trie
    //Pour les afficher de la date la plus proche
    //A la date la plus lointaine
    list<Interaction> inte = c.getInteractions();
    inte.sort();
    for(auto it : inte)
    {
        s <<"Interaction : "<<it;
    }

    s <<endl;

    return s;
}

//SURCHARGE OPERATOR==

/**
*@brief Surcharge de l'opérateur == permettant de tester l'égalité entre 2 Contacts
*@return Retourne un booléen (bool)
*/
bool Contact::operator==(const Contact& c)
{
    if(this->getNom() == c.getNom() &&
       this->getPrenom() == c.getPrenom() &&
       this->getEntreprise() == c.getEntreprise() &&
       this->getMail() == c.getMail() &&
       this->getTelephone() == c.getTelephone() &&
       this->getPhoto() == c.getPhoto() &&
       this->getDateCreation() == c.getDateCreation() &&
       this->getDateModification() == c.getDateModification() /*&&
       this->getInteractions() == c.getInteractions()*/ ) return true;

    else return false;
}

//AUTRES

//Ajoute une interaction dans la liste d'interactions du contact
/**
*@brief Fonction permettant d'ajouter une Interaction à la Liste d'Interaction d'un Contact
*/
void Contact::addInteraction(Interaction interaction)
{
    this->interactions.push_back(interaction);
    this->id_inte++;
}

//Met à jour la date de modification du contact et ajoute
//Une interaction qui horodate la modification effectuée
/**
*@brief Fonction permettant de mettre à jour un Contact lorsque toute modification lui est appliquée
*/
void Contact::updateContact(string contenu)
{
    this->setDateModification(Date());
    this->addInteraction(Interaction(id_inte, contenu));
}
