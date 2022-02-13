#ifndef AJOUTINTERACTION_H
#define AJOUTINTERACTION_H

#include "gestioncontact.h"
#include "interaction.h"

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

/**
*@class AjoutInteraction
*@brief Widget permettant d'ajouter une interaction
*/
class AjoutInteraction : public QWidget
{
    Q_OBJECT

public:

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
    QLabel* ltodo;

    //Les QLineEdits
    QLineEdit* QLEcontenu;
    QLineEdit* QLEjj;
    QLineEdit* QLEmm;
    QLineEdit* QLEaa;

    //La QListWidget
    QListWidget* todo;

    //Les boutons
    QPushButton* bAjoutTodo;
    QPushButton* bEnregistrer;
    QPushButton* bSupprimer;
    QPushButton* bFermer;

    //Fonctions
    void majTodo(Interaction inte);


public:
    explicit AjoutInteraction(QWidget *parent = nullptr);
    AjoutInteraction(Interaction interaction);

signals:

};

#endif // AJOUTINTERACTION_H
