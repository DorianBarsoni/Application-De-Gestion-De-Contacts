#include "ajouttodo.h"

/**
*@brief Constructeur par défaut de AjoutTodo
*/
AjoutTodo::AjoutTodo(QWidget *parent) : QWidget(parent)
{

}

/**
*@brief Constructeur de AjoutTodo prenant un Todo en paramètre
*/
AjoutTodo::AjoutTodo(Todo todo)
{
    this->id = todo.getId();

    //Les layouts
    mainLayout = new QVBoxLayout();
    layoutDate = new QHBoxLayout();
    layoutBoutons = new QHBoxLayout();

    //Les QLabels
    lcontenu = new QLabel("Contenu :");
    ldate = new QLabel("Date :");
    ljj = new QLabel("JJ");
    lmm = new QLabel("MM");
    laa = new QLabel("AAAA");

    //Les QLineEdits
    QLEcontenu = new QLineEdit();
    QLEjj = new QLineEdit();
    QLEjj->setFixedSize(QSize(30, 22));
    QLEmm = new QLineEdit();
    QLEmm->setFixedSize(QSize(30, 22));
    QLEaa = new QLineEdit();
    QLEaa->setFixedSize(QSize(30, 22));

    //Les boutons
    bEnregistrer = new QPushButton("Enregistrer le Todo");
    bSupprimer = new QPushButton("Supprimer le Todo");
    bFermer = new QPushButton("Fermer");

    //Position dans les layout
    layoutDate->addWidget(QLEjj);
    layoutDate->addWidget(ljj);
    layoutDate->addWidget(QLEmm);
    layoutDate->addWidget(lmm);
    layoutDate->addWidget(QLEaa);
    layoutDate->addWidget(laa);

    layoutBoutons->addWidget(bEnregistrer);
    layoutBoutons->addWidget(bSupprimer);
    layoutBoutons->addWidget(bFermer);

    mainLayout->addWidget(lcontenu);
    mainLayout->addWidget(QLEcontenu);
    mainLayout->addWidget(ldate);
    mainLayout->addLayout(layoutDate);
    mainLayout->addLayout(layoutBoutons);

    setLayout(mainLayout);

    //Connect
    connect(bFermer, SIGNAL(clicked()), this, SLOT(close()));

    //Ajout de la date dans les QLineEdit
    QLEcontenu->setText(QString::fromStdString(todo.getContenu()));
    QLEjj->setText(QString::fromStdString(to_string(todo.getDate().getJour())));
    QLEmm->setText(QString::fromStdString(to_string(todo.getDate().getMois())));
    QLEaa->setText(QString::fromStdString(to_string(todo.getDate().getAnnee())));
}
