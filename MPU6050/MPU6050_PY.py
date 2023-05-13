'''
        Read Gyro and Accelerometer by Interfacing Raspberry Pi with MPU6050 using Python
	http://www.electronicwings.com
'''
import smbus			#import SMBus module of I2C
import time         #import
import math

#some MPU6050 Registers and their Address
PWR_MGMT_1   = 0x6B
SMPLRT_DIV   = 0x19
CONFIG       = 0x1A
GYRO_CONFIG  = 0x1B
INT_ENABLE   = 0x38

ACCEL_XOUT_H = 0x3B
ACCEL_YOUT_H = 0x3D
ACCEL_ZOUT_H = 0x3F

GYRO_XOUT_H  = 0x43
GYRO_YOUT_H  = 0x45
GYRO_ZOUT_H  = 0x47

start_time = time.time()

def MPU_Init():
	#write to sample rate register
	bus.write_byte_data(Device_Address, SMPLRT_DIV, 7)
	
	#Write to power management register
	bus.write_byte_data(Device_Address, PWR_MGMT_1, 1)
	
	#Write to Configuration register
	bus.write_byte_data(Device_Address, CONFIG, 0)
	
	#Write to Gyro configuration register
	bus.write_byte_data(Device_Address, GYRO_CONFIG, 24)
	
	#Write to interrupt enable register
	bus.write_byte_data(Device_Address, INT_ENABLE, 1)

def read_raw_data(addr):
	#Accelero and Gyro value are 16-bit
        high = bus.read_byte_data(Device_Address, addr)
        low = bus.read_byte_data(Device_Address, addr+1)
    
        #concatenate higher and lower value
        value = ((high << 8) | low)
        
        #to get signed value from mpu6050
        if(value > 32768):
                value = value - 65536
        return value

def getDT():
	global start_time
	end_time = time.time()
	dt = end_time - start_time
	start_time = end_time
	return dt


bus = smbus.SMBus(1) 	# or bus = smbus.SMBus(0) for older version boards
Device_Address = 0x68   # MPU6050 device address

MPU_Init()

print (" Reading Data of Gyroscope and Accelerometer")

while (True) :
        #Read Accelerometer raw value
		acc_x = read_raw_data(ACCEL_XOUT_H)
		acc_y = read_raw_data(ACCEL_YOUT_H)
		acc_z = read_raw_data(ACCEL_ZOUT_H)
	
		#Read Gyroscope raw value
		gyro_x = read_raw_data(GYRO_XOUT_H)
		gyro_y = read_raw_data(GYRO_YOUT_H)
		gyro_z = read_raw_data(GYRO_ZOUT_H)
	
		#Full scale range +/- 250 degree/C as per sensitivity scale factor
		Ax = acc_x/16384.0 
		Ay = acc_y/16384.0 
		Az = acc_z/16384.0 
	
		Gx = gyro_x/131.0
		Gy = gyro_y/131.0
		Gz = gyro_z/131.0

		#Accelerometer -> delta degree
		if acc_x != 0 and acc_y != 0 and acc_z != 0:
			angleAcY = math.atan(-acc_x / math.sqrt(math.pow(acc_y, 2) + math.pow(acc_z, 2))) * (180 / 3.14159)
			angleAcX = math.atan(-acc_y / math.sqrt(math.pow(acc_x, 2) + math.pow(acc_z, 2))) * (180 / 3.14159)
			#print ("angleAcY=%.5f" %angleAcY, u'\u00b0', "angleAcX=%.5f" %angleAcX, u'\u00b0')
			#time.sleep(0.2)
	
		Gx_angle = float(getDT()) * gyro_x * (180 / 3.14158)
		Gy_angle = float(getDT()) * gyro_y * (180 / 3.14158)
		Gz_angle = float(getDT()) * gyro_z * (180 / 3.14158)
		print ("Gy_x=%.5f" %Gx_angle, u'\u00b0', "Gy_y=%.5f" %Gy_angle, u'\u00b0', "Gy_z=%.5f" %Gz_angle, u'\u00b0')
		time.sleep(0.1)
		

		
	
	#print ("Gx=%.2f" %Gx, u'\u00b0'+ "/s", "\tGy=%.2f" %Gy, u'\u00b0'+ "/s", "\tGz=%.2f" %Gz, u'\u00b0'+ "/s", "\tAx=%.2f g" %Ax, "\tAy=%.2f g" %Ay, "\tAz=%.2f g" %Az) 	
	#sleep(1)