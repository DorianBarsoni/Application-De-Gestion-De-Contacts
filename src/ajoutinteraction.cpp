#include "ajoutinteraction.h"

/**
*@brief Constructeur par défaut de AjoutInteraction
*/
AjoutInteraction::AjoutInteraction(QWidget *parent) : QWidget(parent)
{

}

/**
*@brief Constructeur de AjoutInteraction prenant une interaction en paramètre
*/
AjoutInteraction::AjoutInteraction(Interaction interaction)
{
    id = interaction.getId();

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
    ltodo = new QLabel("Todo :");

    //Les QLineEdits
    QLEcontenu = new QLineEdit();
    QLEjj = new QLineEdit();
    QLEjj->setFixedSize(QSize(30, 22));
    QLEmm = new QLineEdit();
    QLEmm->setFixedSize(QSize(30, 22));
    QLEaa = new QLineEdit();
    QLEaa->setFixedSize(QSize(30, 22));

    //La QListWidget
    todo = new QListWidget();
    majTodo(interaction);

    //Les boutons
    bAjoutTodo = new QPushButton("Ajouter un Todo");
    bEnregistrer = new QPushButton("Enregistrer l'intéraction");
    bSupprimer = new QPushButton("Supprimer l'intéraction");
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
    mainLayout->addWidget(ltodo);
    mainLayout->addWidget(todo);
    mainLayout->addWidget(bAjoutTodo);
    mainLayout->addLayout(layoutBoutons);

    setLayout(mainLayout);

    //Connect
    connect(bFermer, SIGNAL(clicked()), this, SLOT(close()));

    //Ajout des infos de l'interaction dans les QLineEdit
    QLEcontenu->setText(QString::fromStdString(interaction.getContenu()));
    QLEjj->setText(QString::fromStdString(to_string(interaction.getDate().getJour())));
    QLEmm->setText(QString::fromStdString(to_string(interaction.getDate().getMois())));
    QLEaa->setText(QString::fromStdString(to_string(interaction.getDate().getAnnee())));
}

/**
*@brief Fonction permettant de mettre à jour la QListWidget des Todos
*/
void AjoutInteraction::majTodo(Interaction inte)
{
    //On parcours la liste des todos
    for(auto it : inte.getTodo())
    {
        //On crée un QString
        QString s;

        //On range les Todo dans un QString
        s = QString::fromStdString(it.getContenu() + " " + to_string(it.getDate().getJour()) +"/"+ to_string(it.getDate().getMois()) +"/"+ to_string(it.getDate().getAnnee()) );

        //On crée un item à partir de ce QString
        QListWidgetItem* item = new QListWidgetItem(s);

        //On crée un QVariant contenant l'id du contact
        QVariant variant;
        variant.setValue(it.getId());
        item->setData(Qt::UserRole, variant);

        //On ajoute l'item à la QListWidget
        todo->addItem(item);
    }
}
