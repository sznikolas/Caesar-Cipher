#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setWindowTitle("Cezar titkositas");
    //eltolas merteke
    ui->keyValue->setMaximum(35);
    //encrypt legyen kipipalva
    ui->encrypt->setChecked(true);
    //a kodoltbol csak olvasni lehessen
    ui->kodolt->setReadOnly(true);

    nagybetuk = "AÁBCDEÉFGHIÍJKLMNOÓÖŐPQRSTUÚÜŰVWXYZ";//35 betu
    kisbetuk = "aábcdeéfghiíjklmnoóöőpqrstuúüűvwxyz"; //35 betu
}

MainWindow::~MainWindow()
{
    delete ui;

}

//Titkosítás
QString MainWindow::encrypt(const QString str, const int eltolas) const
{
    QString output;

    //irasjelek, szamok
    for (int i = 0;i<str.length();++i ) {
        if(str[i] == ' ')
        {
            output = output + ' ';
        }
        if(str[i] == '.')
        {
            output = output + '.';
        }
        if(str[i] == ',')
        {
            output = output + ',';
        }
        if(str[i] == '!')
        {
            output = output + '!';
        }
        if(str[i] == '?')
        {
            output = output + '?';
        }
        if(str[i] == ':')
        {
            output = output + ':';
        }
        if(str[i] == ';')
        {
            output = output + ';';
        }
        if(str[i] == '*')
        {
            output = output + '*';
        }
        if(str[i] == '/')
        {
            output = output + '/';
        }
        if(str[i] == '-')
        {
            output = output + '-';
        }
        if(str[i] == '_')
        {
            output = output + '_';
        }
        if(str[i] == '"')
        {
            output = output + '"';
        }
        if(str[i] == '0')
        {
            output = output + '0';
        }
        if(str[i] == '1')
        {
            output = output + '1';
        }
        if(str[i] == '2')
        {
            output = output + '2';
        }
        if(str[i] == '3')
        {
            output = output + '3';
        }
        if(str[i] == '4')
        {
            output = output + '4';
        }
        if(str[i] == '5')
        {
            output = output + '5';
        }
        if(str[i] == '6')
        {
            output = output + '6';
        }
        if(str[i] == '7')
        {
            output = output + '7';
        }
        if(str[i] == '8')
        {
            output = output + '8';
        }
        if(str[i] == '9')
        {
            output = output + '9';
        }


    //Nagybetűk
    for (int j = 0; j < nagybetuk.length(); ++j) {

        if (nagybetuk[j] == str[i])
        {
            if ((j + eltolas) > 34){
                output = output + nagybetuk[(j-35)+eltolas];
            }
            else { output = output + nagybetuk[j+eltolas];
        }
    }
}

    // Kisbetűk
    for (int j = 0; j < kisbetuk.length(); ++j) {

        if (kisbetuk[j] == str[i])
        {
            if ((j + eltolas) > 34){
                output = output + kisbetuk[(j-35)+eltolas];
            }
            else { output = output + kisbetuk[j+eltolas];
        }
    }
}
}
    return output;
}


//Visszafejtés
QString MainWindow::decrypt(const QString str, const int eltolas) const
{
    QString output;

    //irasjelek, szamok
    for (int i = 0;i<str.length();++i ) {
        if(str[i] == ' ')
        {
            output = output + ' ';
        }
        if(str[i] == '.')
        {
            output = output + '.';
        }
        if(str[i] == ',')
        {
            output = output + ',';
        }
        if(str[i] == '!')
        {
            output = output + '!';
        }
        if(str[i] == '?')
        {
            output = output + '?';
        }
        if(str[i] == ':')
        {
            output = output + ':';
        }
        if(str[i] == ';')
        {
            output = output + ';';
        }
        if(str[i] == '*')
        {
            output = output + '*';
        }
        if(str[i] == '/')
        {
            output = output + '/';
        }
        if(str[i] == '-')
        {
            output = output + '-';
        }
        if(str[i] == '_')
        {
            output = output + '_';
        }
        if(str[i] == '"')
        {
            output = output + '"';
        }
        if(str[i] == '0')
        {
            output = output + '0';
        }
        if(str[i] == '1')
        {
            output = output + '1';
        }
        if(str[i] == '2')
        {
            output = output + '2';
        }
        if(str[i] == '3')
        {
            output = output + '3';
        }
        if(str[i] == '4')
        {
            output = output + '4';
        }
        if(str[i] == '5')
        {
            output = output + '5';
        }
        if(str[i] == '6')
        {
            output = output + '6';
        }
        if(str[i] == '7')
        {
            output = output + '7';
        }
        if(str[i] == '8')
        {
            output = output + '8';
        }
        if(str[i] == '9')
        {
            output = output + '9';
        }


        //Nagy betűk
        for (int j = 0; j < nagybetuk.length(); ++j) {

            if (nagybetuk[j] == str[i])
            {
                if ((j - eltolas) < 0){
                    output = output + nagybetuk[(j+35)-eltolas];
                }
                else { output = output + nagybetuk[j-eltolas];
            }
        }
    }

        //Kis betűk
        for (int j = 0; j < kisbetuk.length(); ++j) {

            if (kisbetuk[j] == str[i])
            {
                if ((j - eltolas) < 0){
                    output = output + kisbetuk[(j+35)-eltolas];
                }
                else { output = output + kisbetuk[j-eltolas];
            }
        }
    }
}
    return output;
}

//kódolás megnyomására frissít
void MainWindow::on_encrypt_clicked()
{
    ui->decrypt->setChecked(false);

    ui->kodolt->setText(encrypt(ui->nyers->text(), ui->keyValue->value()));
}

//visszafejtés megnyomására frissít
void MainWindow::on_decrypt_clicked()
{
    ui->encrypt->setChecked(false);

    ui->kodolt->setText(decrypt(ui->nyers->text(), ui->keyValue->value()));
}

//Az eltolás értékváltoztatásával egyidőben frissít
void MainWindow::on_keyValue_valueChanged()
{
//ha a kodolas van kipipalva
    if (ui->encrypt->isChecked())
    {
         ui->kodolt->setText(encrypt(ui->nyers->text(), ui->keyValue->value()));
    }

//ha a visszafejtes van kipipalva
    else if (ui->decrypt->isChecked())
    {
         ui->kodolt->setText(decrypt(ui->nyers->text(), ui->keyValue->value()));            }
    }

//szöveg írása közben frissíti kódolást/dekódolást, attól függ mit pipálok ki
void MainWindow::on_nyers_textChanged()
{
    if (ui->encrypt->isChecked())
    {
        ui->kodolt->setText(encrypt(ui->nyers->text(), ui->keyValue->value()));
    }
    else if (ui->decrypt->isChecked())
    {
        ui->kodolt->setText(decrypt(ui->nyers->text(), ui->keyValue->value()));
    }
}

//megnyit egy elmentett fájlt
void MainWindow::on_megnyitas_triggered()
{
// Párbeszédpanelt hoz létre egy fájl megnyitásához
QString fileName = QFileDialog::getOpenFileName(this, "Megnyitás", "C:\\", "szöveges dokumentumok (*.txt)");

// Ellenőrzi a fájlnevet
if (!fileName.isEmpty())
{
    QFile file(fileName); // Nyissa meg a kapott fájlt

    // Az íráshoz vagy az olvasáshoz meg kell nyitnia a fájlt
    // QIODevice :: readOnly olvasás
    // QIODevice :: WriteOnly írás
    //-> ha nem tudja megnyitni
    if (!file.open(QIODevice::ReadOnly))
    {
        //hiba lép fel, és hibaüzenetet hívunk meg//
        QMessageBox::critical(this, "Hiba a fájl megnyitása közben", "A fájl megnyitása nem lehetséges");
    }
    //különben beolvassa a nyers reszbe
    QTextStream in(&file);
    ui->nyers->setText(in.readAll());
    file.close();
}
}

//elmenti egy fájbla a titkosítást
void MainWindow::on_mentes_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Mentés", "C:\\", "szöveges dokumentumként (*.txt)");

    if(!fileName.isEmpty())
    {
        QFile file(fileName);

        // Ellenőrizze a hibákat
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, "Hiba a mentés közben", "Adjon meg más mentési lehetőséget");
        }

        // Írás a fájlba a kodolt reszbol
        QTextStream out(&file);
        out << ui->kodolt->text();

    }
}
