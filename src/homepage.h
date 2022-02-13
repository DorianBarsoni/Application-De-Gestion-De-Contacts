#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QWidget>
#include "gestioncontact.h"

/**
*@class HomePage
*@brief Widget principale permettant de visualiser les contacts
*/
class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr);
    HomePage(GestionContact);

    //Les Layouts
    QVBoxLayout* mainLayout;
    QVBoxLayout* layoutLabelBarreRecherche;
    QHBoxLayout* layoutRecherche;
    QVBoxLayout* layoutResultatEtBouton;

    //Les Labels
    QLabel* recherche;

    //Les LineEdits
    QLineEdit* QLErecherche;

    //La ListView
    QListWidget* resultat;

    //Les Boutons
    QPushButton* bRecherche;
    QPushButton* bNouveauContact;

    //Fonctions
    void majQLW(GestionContact);

signals:

public slots:
};

#endif // HOMEPAGE_H
