#ifndef AJOUTTODO_H
#define AJOUTTODO_H

#include "todo.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

/**
*@class AjoutTodo
*@brief Widget permettant d'ajouter un Todo
*/
class AjoutTodo : public QWidget
{
    Q_OBJECT
public:
    explicit AjoutTodo(QWidget *parent = nullptr);
    AjoutTodo(Todo todo);

    int id;

    //Les layouts
    QVBoxLayout* mainLayout;
    QHBoxLayout* layoutDate;
    QHBoxLayout* layoutBoutons;

    //Les QLabels
    QLabel* lcontenu;
    QLabel* ldate;
    QLabel* ljj;
    QLabel* lmm;
    QLabel* laa;

    //Les QLineEdits
    QLineEdit* QLEcontenu;
    QLineEdit* QLEjj;
    QLineEdit* QLEmm;
    QLineEdit* QLEaa;

    //Les boutons
    QPushButton* bEnregistrer;
    QPushButton* bSupprimer;
    QPushButton* bFermer;

signals:

};

#endif // AJOUTTODO_H
