#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("My App");
    window.resize(400, 300);
    window.show();
    return QApplication::exec();
}