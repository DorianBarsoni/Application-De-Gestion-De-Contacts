#ifndef INTERACTION
#define INTERACTION

#include <string>
#include <list>
#include <ostream>

#include "date.h"
#include "todo.h"

/**
*@namespace std
*/
using namespace std;

/**
*@class Interaction
*@brief Classe représentant une Interaction
*/
class Interaction
{
    private :
        int id;
        int id_todo;
        string contenu;
        Date date;
        list<Todo> todo;

    public :

        //CONSTRUCTEURS & DESTRUCTEURS
        Interaction();
        Interaction(int id);
        Interaction(int id, const string&);
        Interaction(int id, const string&, const Date&);
        Interaction(int id, const string&, const Date&, list<Todo>);
        ~Interaction();

        //GETTERS & SETTERS
        int getId() const;
        int getIdTodo() const;
        string getContenu() const;
        Date getDate() const;
        list<Todo> getTodo() const;

        void setId(int);
        void setIdTodo(int);
        void setContenu(string&);
        void setDate(Date&);
        void setTodo(list<Todo>);

        //SURCHARGE OPERATOR<<
        friend ostream& operator<<(ostream&, const Interaction&);

        //SURCHARGE OPERATOR==
        bool operator==(const Interaction&);

        //SURCHARGE OPERATOR<
        bool operator<(const Interaction&);

        //AUTRES
        void addTodo(Todo);
};

#endif
