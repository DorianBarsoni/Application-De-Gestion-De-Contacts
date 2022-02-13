#include <time.h>
#include <iostream>
#include "date.h"

/**
*@namespace std
*/
using namespace std;

//CONSTRUCTEUR

/**
*@brief Constructeur par défaut de Date
*/
Date::Date()
{
    //Initialisation de la date locale avec
    //La structure tm
    time_t timestamp = time(NULL);
    tm* date = localtime(&timestamp);
    this->annee = date->tm_year + 1900;
    this->mois = date->tm_mon + 1;
    this->jour = date->tm_mday;
}

/**
*@brief Constructeur de Date prenant en paramètre le jour, le mois et l'année
*/
Date::Date(int jour, int mois, int annee)
{
    this->jour = jour;
    this->mois = mois;
    this->annee = annee;
}

//GETTERS & SETTERS

/**
*@brief Fonction permettant d'obtenir l'année d'une Date
*@return Retourne l'année d'une date (int)
*/
int Date::getAnnee() const
{
    return this->annee;
}

/**
*@brief Fonction permettant d'obtenir le mois d'une Date
*@return Retourne le mois d'une Date (int)
*/
int Date::getMois() const
{
    return this->mois;
}

/**
*@brief Fonction permettant d'obtenir 
*@return Retourne le jour d'une Date
*/
int Date::getJour() const
{
    return this->jour;
}

/**
*@brief Fonction permettant de modifier l'année d'une Date
*/
void Date::setAnnee(int annee)
{
    this->annee = annee;
}

/**
*@brief Fonction permettant de modifier le mois d'une Date
*/
void Date::setMois(int mois)
{
    this->mois = mois;
}

/**
*@brief Fonction permettant de modifier le jour d'une Date
*/
void Date::setJour(int jour)
{
    this->jour = jour;
}


//SURCHARGE OPERATOR<<

/**
*@brief Surcharge de l'opérateur << permettant d'afficher une Date
*@return Retourne une référence sur un flux de sorti (ostream&)
*/
ostream& operator<<(ostream& s, const Date& d)
{
    //Les conditions servent à mettre un 0 devant le jour et le mois s'il est inférieur à 10
    if(d.getJour() < 10) s <<"0"<<d.getJour()<<"/";
    else s <<d.getJour()<<"/";

    if(d.getMois() < 10) s <<"0"<<d.getMois()<<"/";
    else s <<d.getMois()<<"/";

    s <<d.getAnnee()<<endl;
    return s;
}


//SURCHARGE OPERATOR!=

/**
*@brief Surcharge de l'opérateur != permettant de tester la différence de 2 Dates
*@return Retourne une booléen (bool)
*/
bool Date::operator!=(const Date& d)
{
    //Il faut que le jour, le mois et l'année de 2 dates
    //Soient égaux pour que les 2 dates soient égales
    if(this->getAnnee() != d.getAnnee()) return true;
    else if (this->getMois() != d.getMois()) return true;
    else if (this->getJour() != d.getJour()) return true;

    return false;
}


//SURCHARGE OPERATOR==

/**
*@brief Surcharge de l'opérateur == permettant de tester l'égalité de 2 Dates
*@return Retourne un booléen (bool)
*/
bool Date::operator==(const Date& d)
{
    //Il faut que le jour, le mois et l'année de 2 dates
    //Soient égaux pour que les 2 dates soient égales
    if(this->getAnnee() == d.getAnnee() &&
       this->getMois() == d.getMois() &&
       this->getJour() == d.getJour() ) return true;

    return false;
}


//SURCHARGE OPERATOR<
/**
*@brief Surcharge de l'opérateur < permettant de vérifier l'antériorité d'une Date par rapport à une autre
*@return Retourne un booléen (bool)
*/
bool Date::operator<(const Date& date)
{
    //On test 3 cas :
    //Si l'année de la première date est inférieur à la seconde on envoie vrai
    if(this->getAnnee() < date.getAnnee())
    {
        return true;
    }

    //Sinon s'il est égale
    else if(this->getAnnee() == date.getAnnee())
    {
        //Si le mois de la première date est inférieur à la seconde on envoie vrai
        if(this->getMois() < date.getMois())
        {
            return true;
        }

        //Sinon s'il est égal
        else if(this->getMois() == date.getMois())
        {
            //Si le jour  de la première date est inférieur à la seconde on envoie vrai
            if(this->getJour() < date.getJour())
            {
                return true;
            }

            //Sinon on renvoie faux
            else return false;
        }

        //Sinon on renvoie faux
        else return false;

    }

    //Sinon on renvoie faux
    else return false;
}
