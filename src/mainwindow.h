#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nouveaucontact.h"
#include "homepage.h"
#include "gestioncontact.h"
#include "feuillecontact.h"
#include "ajoutinteraction.h"
#include "ajouttodo.h"
#include "database.h"

namespace Ui {
class MainWindow;
}

/**
*@class MainWindow
*@brief Fenêtre principale du programme possédant l'attribut GestionContact
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //C++
    GestionContact gc;

    //IHM
    HomePage* homePage;
    NouveauContact* nouveauContact;
    FeuilleContact* feuilleContact;
    AjoutInteraction* ajoutInteraction;
    AjoutTodo* ajoutTodo;

    //DataBase
    //DataBase* db;


private:
    Ui::MainWindow *ui;

public slots:
    void switchFromHomePageToNewContact();
    void switchFromNewContactToHomePage();
    void ajoutContact();
    void recherche();
    void clickedInQListWidgetItem(QModelIndex);

    void enregistrerContact();
    void supprimerContact();

    void nouvelleInteraction();
    void enregistrerInteraction();
    void supprimerInteraction();
    void clickedInInteractionList(QModelIndex);

    void nouveauTodo();
    void enregistrerTodo();
    void supprimerTodo();
    void clickedInTodoList(QModelIndex);

signals :
    void suppContact();
    void suppInteraction();
    void suppTodo();
};

#endif // MAINWINDOW_H
