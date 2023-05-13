#include <MPU6050_tockn.h>
#include <Wire.h>

using namespace std;

wire.begin();
mpu6050.begin();
mpu6050.calcGyroOffsets(true);

while (true) {
    mpu6050.update(); 
    cout << mpu6050.getAngleX() << endl;
    cout << mpu6050.getAngleY() << endl;
    cout << mpu6050.getAngleZ() << endl;
}