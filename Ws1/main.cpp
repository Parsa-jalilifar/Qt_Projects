#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton button("Hello BTH545",nullptr);
    button.resize(300,50);
    button.show();

    return a.exec();
}
