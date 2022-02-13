#ifndef NOUVEAUCONTACT_H
#define NOUVEAUCONTACT_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

/**
*@class NouveauContact
*@brief Widget permettant de créer un nouveau contact
*/
class NouveauContact : public QWidget
{
    Q_OBJECT
public:
    explicit NouveauContact(QWidget *parent = nullptr);

    //Les Layouts
    QVBoxLayout* mainLayout;
    QVBoxLayout* layoutInfos;
    QHBoxLayout* layoutBoutons;

    //Les Labels
    QLabel* nom;
    QLabel* prenom;
    QLabel* entreprise;
    QLabel* mail;
    QLabel* telephone;
    QLabel* photo;

    //Les LineEdits
    QLineEdit* QLEnom;
    QLineEdit* QLEprenom;
    QLineEdit* QLEentreprise;
    QLineEdit* QLEmail;
    QLineEdit* QLEtelephone;
    QLineEdit* QLEphoto;

    //Les Boutons
    QPushButton* bRetour;
    QPushButton* bAjout;

signals:

public slots:
};

#endif // NOUVEAUCONTACT_H
