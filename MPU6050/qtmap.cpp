#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QVector>
#include <random>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // create pixmap with white background
    QPixmap pixmap(100, 100);
    pixmap.fill(Qt::white);

    // create painter to draw on pixmap
    QPainter painter(&pixmap);

    // set pen for drawing lines
    QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap);

    // draw grid lines
    for (int x = 0; x <= 100; x += 10) {
        painter.setPen(pen);
        painter.drawLine(x, 0, x, 100);
        painter.drawLine(0, x, 100, x);
    }

    // create random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 99);

    // randomly place objects on map
    QVector<QPoint> objects;
    for (int i = 0; i < 10; ++i) {
        QPoint object(distr(gen), distr(gen));
        objects.append(object);
        painter.fillRect(QRect(object, QSize(10, 10)), Qt::black);
    }

    // create label to display pixmap
    QLabel label;
    label.setPixmap(pixmap);
    label.show();

    return app.exec();
}
