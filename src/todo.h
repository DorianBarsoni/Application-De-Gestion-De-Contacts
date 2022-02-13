#ifndef TODO
#define TODO

#include <string>
#include <ostream>

#include "date.h"

/**
*@namespace std
*/
using namespace std;

/**
*@class Todo
*@brief Classe permettant représenter un Todo
*/
class Todo
{
    private :
        int id;
        string contenu;
        Date date;
    
    public :
        //CONSTRUCTEURS
        Todo();
        Todo(int id);
        Todo(int id, const string&);
        Todo(int id, const string&, const Date&);

        //GETTERS & SETTERS
        int getId() const;
        string getContenu() const;
        Date getDate() const;

        void setId(int);
        void setContenu(string);
        void setDate(Date);

        //SURCHARGE OPERATOR<<
        friend ostream& operator<<(ostream&, const Todo&);

        //SRUCHARGE OPERATOR<
        bool operator<(const Todo&);

        //SURCHARGE OPERATOR==
        bool operator==(const Todo&);
};

#endif
