#include <string>
#include <list>
#include <ostream>

#include "date.h"
#include "interaction.h"

using namespace std;

//CONSTRUCTEURS & DESTRUCTEURS

/**
*@brief Constructeur par défaut de la classe Interaction
*/
Interaction::Interaction()
{
    this->id = -1;
    this->id_todo = 0;
    this->contenu = "";
    this->date = Date();
    this->todo = {};
}

/**
*@brief Constructeur prennant un id en paramètre
*/
Interaction::Interaction(int id)
{
    this->id = id;
    this->id_todo = 0;
    this->contenu = "";
    this->date = Date();
    this->todo = {};
}

/**
*@brief Constructeur prenant un id et un contenu en paramètre
*/
Interaction::Interaction(int id, const string& contenu)
{
    this->id = id;
    this->id_todo = 0;
    this->contenu = contenu;
    this->date = Date();
    this->todo = {};
}

/**
*@brief Constructeur prenant un id, un contenu et une date en paramètre
*/
Interaction::Interaction(int id, const string& contenu, const Date& date)
{
    this->id = id;
    this->id_todo = 0;
    this->contenu = contenu;
    this->date = date;
    this->todo = {};
}

/**
*@brief Constructeur prenant un id, un contenu, une date et une liste de Todo en paramètre
*/
Interaction::Interaction(int id, const string& contenu, const Date&, list<Todo> todo)
{
    this->id = id;
    this->id_todo = 0;
    this->contenu = contenu;
    this->date = date;
    this->todo = todo;
}

/**
*@brief Destructeur de la classe Interaction
*/
Interaction::~Interaction()
{
    this->todo.clear();
}
    

//GETTERS & SETTERS

/**
*@brief Fonction permettant d'obtenir l'id de l'interaction
*@return Retourne l'id de l'interaction
*/
int Interaction::getId() const
{
    return this->id;
}

/**
*@brief Fonction permettant d'obtenir le prochain id des todo
*@return Retourne le prochain id des todo
*/
int Interaction::getIdTodo() const
{
    return this->id_todo;
}

/**
*@brief Fonction permettant d'obtenir le contenu d'une interaction
*@return Retourne le contenu d'une interaction (string)
*/
string Interaction::getContenu() const
{
    return this->contenu;
}

/**
*@brief Fonction permettant d'obtenir la date d'une interaction
*@return Retourne la date de l'interaction (Date)
*/
Date Interaction::getDate() const
{
    return this->date;
}

/**
*@brief Fonction permettant d'obtenir la liste des Todo d'une interaction
*@return Retourne la liste des Todo de l'interaction (list<Todo>)
*/
list<Todo> Interaction::getTodo() const
{
    return this->todo;
}

/**
*@brief Fonction remplaçant l'id de l'interaction
*/
void Interaction::setId(int id)
{
    this->id = id;
}

/**
*@brief Fonction remplaçant le prochain id des todo
*/
void Interaction::setIdTodo(int id_todo)
{
    this->id_todo = id_todo;
}

/**
*@brief Fonction remplaçant le contenu de l'interaction par un contenu fournit en paramètre 
*/
void Interaction::setContenu(string& contenu)
{
    this->contenu = contenu;
}

/**
*@brief Fonction remplaçant la date de l'interaction par une date fournit en paramètre 
*/
void Interaction::setDate(Date& date)
{
    this->date = date;
}

/**
*@brief Fonction remplaçant la liste de Todo de l'interaction par une liste de Todo fournit en paramètre 
*/
void Interaction::setTodo(list<Todo> todo)
{
    this->todo = todo;
}

//SURCHARGE OPERATOR<<

/**
*@brief Surcharge de l'opérateur << permettant d'afficher une interaction
*@return Retourne une référence sur un flux de sorti (ostream&)
*/
ostream& operator<<(ostream& s, const Interaction& i)
{
    //On affiche le contenu
    s <<i.getContenu()<<" "<<i.getDate();

    //Puis on récupère la liste de todo qu'on trie
    //Pour les afficher de la date la plus proche
    //A la date la plus lointaine
    auto todo = i.getTodo();
    todo.sort();
    for(auto todo : todo) s<<todo;

    return s;
}

//SURCHARGE OPERATOR==

/**
*@brief Surcharge de l'opérateur == permettant de vérifier l'égalité entre 2 interactions
*@return Retourne un booléen (bool)
*/
bool Interaction::operator==(const Interaction& i)
{
    //Si le contenu et la date de 2 interactions sont égales
    //On renvoie vrai
    if(this->getContenu() == i.getContenu() &&
       this->getDate() == i.getDate() ) return true;

    //Sinon on renvoie faux
    else return false;
}

//SURCHARGE OPERATOR<

/**
*@brief Surcharge de l'opérateur < permettant de vérifier l'antériorité d'une Interaction par rapport à une autre
*@return Retourne un booléen (bool)
*/
bool Interaction::operator<(const Interaction& i)
{
    //Si la date d'une interaction est inférieure
    //A la date de la seconde on renvoie vrai
    if(this->getDate() < i.getDate()) return true;

    //Sinon on renvoie faux
    else return false;
}

//AUTRES
//Ajoute un todo à la liste de todo

/**
*@brief Fonction permettant d'ajouter un Todo à la liste de Todo de l'interaction
*/
void Interaction::addTodo(Todo todo)
{
    this->todo.push_back(todo);
    this->id_todo++;
}
