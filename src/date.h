#ifndef DATE
#define DATE

#include <ostream>

/**
*@namespace std
*/
using namespace std;

/**
*@class Date
*@brief Classe représentant une date
*/
class Date
{
    private :

        int annee;
        int mois;
        int jour;

    public :

        //CONSTRUCTEUR
        Date();
        Date(int, int, int);

        //GETTERS & SETTERS
        int getAnnee() const;
        int getMois() const;
        int getJour() const;

        void setAnnee(int annee);
        void setMois(int mois);
        void setJour(int jour);

        //SURCHARGE OPERATOR<<
        friend ostream& operator<<(ostream&, const Date&);

        //SURCHARGE OPERATOR!=
        bool operator!=(const Date&);

        //SURCHARGE OPERATOR==
        bool operator==(const Date&);

        //SURCHARGE OPERATOR<
        bool operator<(const Date&);
};

#endif