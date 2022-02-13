#ifndef FEUILLECONTACT_H
#define FEUILLECONTACT_H

#include <gestioncontact.h>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QListWidget>

/**
*@class FeuilleContact
*@brief Widget permettant de modifier ou de supprimer un contact
*/
class FeuilleContact : public QWidget
{
    Q_OBJECT
public:
    explicit FeuilleContact(QWidget *parent = nullptr);
    FeuilleContact(GestionContact*, int);

    //Id du Contact
    int id;

    //Les QString
    QString nom;
    QString prenom;
    QString entreprise;
    QString mail;
    QString telephone;
    QString photo;

    //Les Layouts
    QVBoxLayout* mainLayout;
    QHBoxLayout* layoutLabelQLE;
    QVBoxLayout* layoutLabel;
    QVBoxLayout* layoutQLE;
    QVBoxLayout* layoutInteractions;
    QHBoxLayout* layoutBoutons;

    //Les Labels
    QLabel* lnom;
    QLabel* lprenom;
    QLabel* lentreprise;
    QLabel* lmail;
    QLabel* ltelephone;
    QLabel* lphoto;
    QLabel* linteractions;

    //Les LineEdits
    QLineEdit* QLEnom;
    QLineEdit* QLEprenom;
    QLineEdit* QLEentreprise;
    QLineEdit* QLEmail;
    QLineEdit* QLEtelephone;
    QLineEdit* QLEphoto;

    //Le QListWidget
    QListWidget* interactions;

    //Les Boutons
    QPushButton* bAjoutInteraction;
    QPushButton* bEnregistrer;
    QPushButton* bSupprimer;
    QPushButton* bFermer;

    //Fonctions
    void majInteractions(GestionContact* gc, int id);

signals:

public slots :

};

#endif // FEUILLECONTACT_H
