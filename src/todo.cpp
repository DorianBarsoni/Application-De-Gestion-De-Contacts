#include <string>
#include <ostream>

#include "todo.h"
#include "date.h"

//CONSTRUCTEURS

/**
*@brief Constructeur par défaut de Todo
*/
Todo::Todo()
{
    this->id = -1;
    this->contenu = "";
    this->date = Date();
}

/**
*@brief Constructeur de Todo prenant en paramètre un id
*/
Todo::Todo(int id)
{
    this->id = id;
    this->contenu = "";
    this->date = Date();
}

/**
*@brief Constructeur de Todo prenant en paramètre un id et un contenu
*/
Todo::Todo(int id, const string& contenu)
{
    this->id = id;
    this->contenu = contenu;
    this->date = Date();
}

/**
*@brief Constructeur de Todo prenant en paramètre un id, un contenu et une date
*/
Todo::Todo(int id, const string& contenu, const Date& date)
{
    this->id = id;
    this->contenu = contenu;
    this->date = date;
}


//GETTERS & SETTERS

/**
*@brief Fonction permettant d'obtenir l'id du Todo
*@return Retourne l'id du Todo
*/
int Todo::getId() const
{
    return this->id;
}

/**
*@brief Fonction permettant d'obtenir le contenu d'un Todo
*@return Retourne le contenu d'un Todo (string)
*/
string Todo::getContenu() const
{
    return this->contenu;
}

/**
*@brief Fonction permettant d'obtenir la date d'un Todo
*@return Retourne la date d'un Todo (Date)
*/
Date Todo::getDate() const
{
    return this->date;
}

/**
*@brief Fonction permettant de modifier l'id d'un Todo
*/
void Todo::setId(int id)
{
   this->id = id;
}

/**
*@brief Fonction permettant de modifier le contenu d'un Todo
*/
void Todo::setContenu(string contenu)
{
    this->contenu = contenu;
}

/**
*@brief Fonction permettant de modifier la date d'un Todo
*/
void Todo::setDate(Date date)
{
    this->date = date;
}


//SURCHARGE OPERATOR<<

/**
*@brief Surcharge de l'opérateur << permettant d'afficher un Todo
*@return Retourne une référence sur un flux de sorti (ostream&)
*/
ostream& operator<<(ostream& s, const Todo& todo)
{
    //On affiche le contenu
    s <<"@todo "<<todo.getContenu();

    //Si la date est -1/-1/-1 on ne l'affiche pas
    if(todo.getDate() != Date(-1, -1, -1))
    {
        s <<" @date "<<todo.getDate();
    }

    return s;
}


//SRUCHARGE OPERATOR<

/**
*@brief Surcharge de l'opérateur < permettant de vérifier l'antériorité d'un Todo par rapport à un autre
*@return Retourne un booléen (bool)
*/
bool Todo::operator<(const Todo& todo)
{
    //Si une date est inférieure à une seconde
    //On renvoie vrai
    if(this->getDate() < todo.getDate()) return true;

    //Sinon on renvoie faux
    else return false;
}

/**
*@brief Surcharge de l'opérateur == permettant de vérifier qu'un todo est égale à un autre
*@return Retourne un booléen (bool)
*/
//SURCHARGE OPERATOR==
bool Todo::operator==(const Todo& todo)
{
   if((this->getDate() == todo.getDate()) && (this->getContenu() == todo.getContenu()) && (this->getId() == todo.getId())) return true;
   return false;
}
