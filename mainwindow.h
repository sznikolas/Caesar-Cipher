#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString encrypt(const QString str, const int eltolas) const;
    QString decrypt(const QString str, const int eltolas) const;



private slots:
    //titkositasra kattintas
    void on_encrypt_clicked();
    //visszafejtesre kattintas
    void on_decrypt_clicked();
    //eltolás
    void on_keyValue_valueChanged();
    //realis idoben valo forditasa
    void on_nyers_textChanged();
    //megnyitás
    void on_megnyitas_triggered();
    //mentés
    void on_mentes_triggered();


private:
    Ui::MainWindow *ui;

   QString nagybetuk;
   QString kisbetuk;

};
#endif // MAINWINDOW_H
