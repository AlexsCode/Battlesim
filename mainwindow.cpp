#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(":/textvalues/textvalues/shipconfigs.txt");
    QTextStream in(&file);
    file.open(QFile::ReadOnly |QFile::Text);
    QString datain= in.readAll();
    QStringList comp = datain.split("\n");


  //trying to find how many substrings.
    QString maxsubstring;
    maxsubstring.setNum(comp.size());

    //ui->comboBox_comp->addItem(maxsubstring,1); - Checker
    for(int i=0; i<(comp.size());i++)
    {
        ui->comboBox_comp->addItem(comp[i],1);
    }


    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{//when the new button is pressed.

}

void MainWindow::on_SimulateRun_triggered()
{//constructor for the run simulate.

}

void MainWindow::on_comboBox_comp_activated(const QString &arg1)
{
  QString compcurrent = ui->comboBox_comp->currentText();
  //ui->comboBox_shiptype->addItem(compcurrent,1);
}

void MainWindow::on_comboBox_comp_currentTextChanged(const QString &arg1)
{
    QString compcurrent = ui->comboBox_comp->currentText();

    if ( compcurrent== "Fossa")
    {   ui->comboBox_shiptype->clear();

        QFile fossafile(":/textvalues/textvalues/fossa.txt");
        QTextStream fossain(&fossafile);
        fossafile.open(QFile::ReadOnly |QFile::Text);
        QString fossadatain= fossain.readAll();
        QStringList fossacomp = fossadatain.split("\n");
        QString fossamaxsubstring;
        fossamaxsubstring.setNum(fossacomp.size());

        for(int i=0; i<(fossacomp.size());i++)
            {
                ui->comboBox_shiptype->addItem(fossacomp[i],1);
            }
        fossafile.close();
    }
    else if ( compcurrent== "Lightbringer")
    {   ui->comboBox_shiptype->clear();

        QFile lightbringerfile(":/textvalues/textvalues/lightbringer.txt");
        QTextStream lightbringerin(&lightbringerfile);
        lightbringerfile.open(QFile::ReadOnly |QFile::Text);
        QString lightbringerdatain= lightbringerin.readAll();
        QStringList lightbringercomp = lightbringerdatain.split("\n");
        QString lightbringermaxsubstring;
        lightbringermaxsubstring.setNum(lightbringercomp.size());

        for(int i=0; i<(lightbringercomp.size());i++)
            {
                ui->comboBox_shiptype->addItem(lightbringercomp[i],1);
            }
        lightbringerfile.close();
    }


    else
    {   ui->comboBox_shiptype->clear();
        QString compcurrent;
        ui->comboBox_shiptype->setItemText(0,compcurrent);
    }
    //notes:
    //for calculations get all values, press calc. write a text log creating with name::timestamp.
    //then run calculations via this and give output text log::timestamp.
    //that way - Calculate previous uses textlog timestamp-current time= Closest 2.

}
