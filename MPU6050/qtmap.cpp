#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 1000*1000 맵 생성
    const int mapSize = 1000;
    QVector<QVector<int>> map(mapSize, QVector<int>(mapSize, 0));

    // 랜덤으로 사물 배치
    qsrand(QTime::currentTime().msec());
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            int randomValue = qrand() % 5; // 0부터 4까지의 랜덤값 생성
            if (randomValue == 4) {
                map[i][j] = 3; // 4일 때만 벽으로 설정
            }
        }
    }

    // 맵 출력
    QWidget window;
    window.resize(1000, 1000); // 윈도우 크기 설정

    QLabel label(&window);
    QImage image(mapSize, mapSize, QImage::Format_RGB32);

    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            QRgb color = 0;
            switch (map[i][j]) {
            case 0: // 이동 가능한 공간
                color = qRgb(255, 255, 255); // 흰색
                break;
            case 3: // 벽
                color = qRgb(0, 0, 0); // 검은색
                break;
            default:
                break;
            }
            image.setPixel(i, j, color);
        }
    }
    label.setPixmap(QPixmap::fromImage(image));
    window.show();

    return app.exec();
}
