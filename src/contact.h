#ifndef CONTACT
#define CONTACT

#include <string>
#include <list>
#include <ostream>

#include "date.h"
#include "interaction.h"

/**
*@namespace std
*/
using namespace std;

/**
*@class Contact
*@brief Classe représentant un Contact
*/

class Contact
{
    private :
        int id;
        int id_inte;
        string nom;
        string prenom;
        string entreprise;
        string mail;
        list<int> telephone;
        string photo;
        Date dateCreation;
        Date dateModification;
        list<Interaction> interactions;

    public :
        
        //CONSTRUCTEURS & DESTRUCTEURS
        Contact();
        Contact(int id, int id_inte, string nom, string prenom, string entreprise, string mail, list<int> telephone, string photo, list<Interaction>);
        ~Contact();

        //GETTERS & SETTERS
        int getId() const;
        int getIdInte() const;
        string getNom() const;
        string getPrenom() const;
        string getEntreprise() const;
        string getMail() const;
        list<int> getTelephone() const;
        string getPhoto() const;
        Date getDateCreation() const;
        Date getDateModification() const;
        list<Interaction> getInteractions() const;

        void setId(int);
        void setIdInte(int);
        void setNom(string);
        void setPrenom(string);
        void setEntreprise(string);
        void setMail(string);
        void setTelephone(list<int>);
        void setPhoto(string);
        void setDateCreation(Date);
        void setDateModification(Date);
        void setInteractions(list<Interaction>);

        //SURCHAGE OPERATOR<<
        friend ostream& operator<<(ostream&, const Contact&);

        //SURCHARGE OPERATOR==
        bool operator==(const Contact&);

        //AUTRES
        void addInteraction(Interaction);
        void updateContact(string);
};

#endif
