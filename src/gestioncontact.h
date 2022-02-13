#ifndef GESTION_CONTACT
#define GESTION_CONTACT

#include <list>
#include <ostream>

#include "contact.h"
#include "date.h"

/**
*@namespace std
*/
using namespace std;

/**
*@class GestionContact
*@brief Classe permettant de regrouper et de gérer les Contacts
*/
class GestionContact
{
    private :
        list<Contact> listeContacts;
        Date dateDestruction;
        int id;

    public :
        //CONSTRUCTEURS
        GestionContact();
        GestionContact(list<Contact>);
        ~GestionContact();

        //GETTERS & SETTERS
        list<Contact> getListeContacts() const;
        Date getDateDestruction() const;
        int getId() const;

        void setListeContacts(list<Contact>);
        void setDateDestruction(Date);
        void setId(int id);

        //SURCHARGE OPERATOR<<
        friend ostream& operator<<(ostream&, const GestionContact&);

        //SURCHARGE OPERATOR+
        GestionContact operator+(const Contact&);

        //SURCHARGE OPERATOR+=
        GestionContact operator+=(const Contact&);

        //SURCHARGE OPERATOR-
        GestionContact operator-(const Contact&);

        //SURCHARGE OPERATOR-=
        GestionContact operator-=(const Contact&);
};

#endif
