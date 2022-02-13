#include <list>
#include <ostream>

#include "gestioncontact.h"
#include "contact.h"
#include "date.h"

//CONSTRUCTEURS

/**
*@brief Constructeur par défaut de GestionContact
*/
GestionContact::GestionContact()
{
    this->listeContacts = {};

    //Par défaut la date de destruction est -1/-1/-1
    //Ce qui permet de ne pas l'afficher
    this->dateDestruction = Date(-1, -1, -1);

    this->id = 0;
}

/**
*@brief Constructeur de GestionContact prenant en paramètre une liste de Contacts
*/
GestionContact::GestionContact(list<Contact> listeContacts)
{
    this->listeContacts = listeContacts;

    //Par défaut la date de destruction est -1/-1/-1
    //Ce qui permet de ne pas l'afficher
    this->dateDestruction = Date(-1, -1, -1);

    this->id = 0;
}

/**
*@brief Destructeur de la classe GestionContact
*/
GestionContact::~GestionContact()
{
    this->listeContacts.clear();
}

//GETTERS & SETTERS

/**
*@brief Fonction permettant d'obtenir la Liste de Contacts de la classe GestionContact
*@return Retourne la Liste de Contacts de GestionContact (list<Contact>)
*/
list<Contact> GestionContact::getListeContacts() const
{
    return this->listeContacts;
}

/**
*@brief Fonction permettant d'obtenir la dernière Date de Destruction de GestionContact
*@return Retourne la Date de Destruction de GestionContact (Date)
*/
Date GestionContact::getDateDestruction() const
{
    return this->dateDestruction;
}

/**
*@brief Fonction permettant d'obtenir l'id de GestionContact
*@return Retourne l'id de GestionContact
*/
int GestionContact::getId() const
{
    return this->id;
}

/**
*@brief Fonction permettant de changer la Liste de Contacts de GestionContact
*/
void GestionContact::setListeContacts(list<Contact> listeContacts)
{
    this->listeContacts = listeContacts;
}

/**
*@brief Fonction permettant de modifier la Date de Destruction de GestionContact
*/
void GestionContact::setDateDestruction(Date dateDestruction)
{
    this->dateDestruction = dateDestruction;
}

/**
*@brief Fonction permettant de modifier l'id de GestionContact
*/
void GestionContact::setId(int id)
{
    this->id = id;
}


//SURCHARGE OPERATOR<<

/**
*@brief Surcharge de l'opérateur << permettant d'afficher une instense de GestionContact
*@return Retourne une référence sur un flux de sorti (ostream&)
*/
ostream& operator<<(ostream& s, const GestionContact& gestionContact)
{
    for(auto i : gestionContact.getListeContacts())
    {
        s <<i;
    }

    //Si la date est -1/-1/-1 on ne l'affiche pas
    if(gestionContact.getDateDestruction() != Date(-1, -1, -1))
    {
        s <<"Date de destruction : ";
        s <<gestionContact.getDateDestruction();
    }

    s<<"Id : "<<gestionContact.getId();

    return s;
}


//SURCHARGE OPERATOR+

/**
*@brief Surcharge de l'opérateur + permettant d'ajouter un Contact à la Liste de Contacts d'une instance de GestionContact
*@return Retourne une instance de GestionContact (GestionContact)
*/
GestionContact GestionContact::operator+(const Contact& c)
{
    listeContacts.push_back(c);
    id++;
    return *this;
}

//SURCHARGE OPERATOR+=

/**
*@brief Surcharge de l'opérateur += permettant d'ajouter un Contact à la Liste de Contacts d'une instance de GestionContact
*@return Retourne une instance de GestionContact (GestionContact)
*/
GestionContact GestionContact::operator+=(const Contact& c)
{
    listeContacts.push_back(c);
    id++;
    return *this;
}


//SURCHARGE OPERATOR-

/**
*@brief Surcharge de l'opérateur - permettant de supprimer un Contact de la Liste de Contacts d'une instance de GestionContact
*@return Retourne une instance de GestionContact (GestionContact)
*/
GestionContact GestionContact::operator-(const Contact& c)
{
    auto it = listeContacts.begin();
    bool trouve = false;

    //On traverse tout la liste de contacts, si on trouve
    //le contact qu'on recherche alors on le supprime de la liste
    while( (it != listeContacts.end()) && !trouve)
    {
        if(*it == c)
        {
            listeContacts.erase(it);
            trouve = true;
        }
        else ++it;
    }

    //On modifie la date de destruction avec la date actuelle
    this->setDateDestruction(Date());

    return *this;
}


//SURCHARGE OPERATOR-=

/**
*@brief Surcharge de l'opérateur -= permettant de supprimer un Contact de la Liste de Contacts d'une instance de GestionContact
*@return Retourne une instance de GestionContact (GestionContact)
*/
GestionContact GestionContact::operator-=(const Contact& c)
{
    auto it = listeContacts.begin();
    bool trouve = false;

    //On traverse tout la liste de contacts, si on trouve
    //le contact qu'on recherche alors on le supprime de la liste
    while( (it != listeContacts.end()) && !trouve)
    {
        if(*it == c)
        {
            listeContacts.erase(it);
            trouve = true;
        }
        else ++it;
    }

    //On modifie la date de destruction avec la date actuelle
    this->setDateDestruction(Date());

    return *this;
}
