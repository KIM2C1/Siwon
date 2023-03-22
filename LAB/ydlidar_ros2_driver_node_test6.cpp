/*
 *  YDLIDAR SYSTEM
 *  YDLIDAR ROS 2 Node
 *
 *  Copyright 2017 - 2020 EAI TEAM
 *  http://www.eaibot.com
 *
 */

#ifdef _MSC_VER
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#endif

#include "src/CYdLidar.h"
#include <math.h>
#include <chrono>
#include <iostream>
#include <memory>

#include "rclcpp/clock.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time_source.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_srvs/srv/empty.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <signal.h>

#include <wiringPi.h>
#include <softPwm.h>

#define ROS2Verision "1.0.1"

//siwon include
#include <stdio.h>
using namespace std;

// FL-MOTER
#define EN_FL 23
#define IN_FL_1 22
#define IN_FL_2 21
int OUT_FL_1 = LOW;
int OUT_FL_2 = LOW;

// BL-MOTER
#define EN_BL 29
#define IN_BL_1 28
#define IN_BL_2 27
int OUT_BL_1 = LOW;
int OUT_BL_2 = LOW;

// FR-MOTER
#define EN_FR 4
#define IN_FR_1 5
#define IN_FR_2 6
int OUT_FR_1 = LOW;
int OUT_FR_2 = LOW;

// BR-MOTER
#define EN_BR 3
#define IN_BR_1 2
#define IN_BR_2 0
int OUT_BR_1 = LOW;
int OUT_BR_2 = LOW;


int main(int argc, char *argv[]) {

  // wiringPi 초기화
  wiringPiSetup();
  
  // FL-MOTER
  pinMode(EN_FL, OUTPUT);
  pinMode(IN_FL_1, OUTPUT);
  pinMode(IN_FL_2, OUTPUT);
  softPwmCreate(EN_FL, 0, 100);
  softPwmWrite(EN_FL, 0);

  // BL-MOTER
  pinMode(EN_BL, OUTPUT);
  pinMode(IN_BL_1, OUTPUT);
  pinMode(IN_BL_2, OUTPUT);
  softPwmCreate(EN_BL, 0, 100);
  softPwmWrite(EN_BL, 0);

  // FR-MOTER
  pinMode(EN_FR, OUTPUT);
  pinMode(IN_FR_1, OUTPUT);
  pinMode(IN_FR_2, OUTPUT);
  softPwmCreate(EN_FR, 0, 100);
  softPwmWrite(EN_FR, 0);

  // BR-MOTER
  pinMode(EN_BR, OUTPUT);
  pinMode(IN_BR_1, OUTPUT);
  pinMode(IN_BR_2, OUTPUT);
  softPwmCreate(EN_BR, 0, 100);
  softPwmWrite(EN_BR, 0);

  char input;


  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("ydlidar_ros2_driver_node");

  RCLCPP_INFO(node->get_logger(), "[YDLIDAR INFO] Current ROS Driver Version: %s\n", ((std::string)ROS2Verision).c_str());

  CYdLidar laser;
  std::string str_optvalue = "/dev/ydlidar";
  node->declare_parameter("port");
  node->get_parameter("port", str_optvalue);
  ///lidar port
  laser.setlidaropt(LidarPropSerialPort, str_optvalue.c_str(), str_optvalue.size());

  ///ignore array
  str_optvalue = "";
  node->declare_parameter("ignore_array");
  node->get_parameter("ignore_array", str_optvalue);
  laser.setlidaropt(LidarPropIgnoreArray, str_optvalue.c_str(), str_optvalue.size());

  std::string frame_id = "laser_frame";
  node->declare_parameter("frame_id");
  node->get_parameter("frame_id", frame_id);

  //////////////////////int property/////////////////
  /// lidar baudrate
  int optval = 230400;
  node->declare_parameter("baudrate");
  node->get_parameter("baudrate", optval);
  laser.setlidaropt(LidarPropSerialBaudrate, &optval, sizeof(int));
  /// tof lidar
  optval = TYPE_TRIANGLE;
  node->declare_parameter("lidar_type");
  node->get_parameter("lidar_type", optval);
  laser.setlidaropt(LidarPropLidarType, &optval, sizeof(int));
  /// device type
  optval = YDLIDAR_TYPE_SERIAL;
  node->declare_parameter("device_type");
  node->get_parameter("device_type", optval);
  laser.setlidaropt(LidarPropDeviceType, &optval, sizeof(int));
  /// sample rate
  optval = 5;
  node->declare_parameter("sample_rate");
  node->get_parameter("sample_rate", optval);
  laser.setlidaropt(LidarPropSampleRate, &optval, sizeof(int));
  /// abnormal count
  optval = 4;
  node->declare_parameter("abnormal_check_count");
  node->get_parameter("abnormal_check_count", optval);
  laser.setlidaropt(LidarPropAbnormalCheckCount, &optval, sizeof(int));
     

  //////////////////////bool property/////////////////
  /// fixed angle resolution
  bool b_optvalue = false;
  node->declare_parameter("fixed_resolution");
  node->get_parameter("fixed_resolution", b_optvalue);
  laser.setlidaropt(LidarPropFixedResolution, &b_optvalue, sizeof(bool));
  /// rotate 180
  b_optvalue = true;
  node->declare_parameter("reversion");
  node->get_parameter("reversion", b_optvalue);
  laser.setlidaropt(LidarPropReversion, &b_optvalue, sizeof(bool));
  /// Counterclockwise
  b_optvalue = true;
  node->declare_parameter("inverted");
  node->get_parameter("inverted", b_optvalue);
  laser.setlidaropt(LidarPropInverted, &b_optvalue, sizeof(bool));
  b_optvalue = true;
  node->declare_parameter("auto_reconnect");
  node->get_parameter("auto_reconnect", b_optvalue);
  laser.setlidaropt(LidarPropAutoReconnect, &b_optvalue, sizeof(bool));
  /// one-way communication
  b_optvalue = false;
  node->declare_parameter("isSingleChannel");
  node->get_parameter("isSingleChannel", b_optvalue);
  laser.setlidaropt(LidarPropSingleChannel, &b_optvalue, sizeof(bool));
  /// intensity
  b_optvalue = false;
  node->declare_parameter("intensity");
  node->get_parameter("intensity", b_optvalue);
  laser.setlidaropt(LidarPropIntenstiy, &b_optvalue, sizeof(bool));
  /// Motor DTR
  b_optvalue = false;
  node->declare_parameter("support_motor_dtr");
  node->get_parameter("support_motor_dtr", b_optvalue);
  laser.setlidaropt(LidarPropSupportMotorDtrCtrl, &b_optvalue, sizeof(bool));

  //////////////////////float property/////////////////
  /// unit: °
  float f_optvalue = 180.0f;
  node->declare_parameter("angle_max");
  node->get_parameter("angle_max", f_optvalue);
  laser.setlidaropt(LidarPropMaxAngle, &f_optvalue, sizeof(float));
  f_optvalue = -180.0f;
  node->declare_parameter("angle_min");
  node->get_parameter("angle_min", f_optvalue);
  laser.setlidaropt(LidarPropMinAngle, &f_optvalue, sizeof(float));
  /// unit: m
  f_optvalue = 64.f;
  node->declare_parameter("range_max");
  node->get_parameter("range_max", f_optvalue);
  laser.setlidaropt(LidarPropMaxRange, &f_optvalue, sizeof(float));
  f_optvalue = 0.1f;
  node->declare_parameter("range_min");
  node->get_parameter("range_min", f_optvalue);
  laser.setlidaropt(LidarPropMinRange, &f_optvalue, sizeof(float));
  /// unit: Hz
  f_optvalue = 5.f;
  node->declare_parameter("frequency");
  node->get_parameter("frequency", f_optvalue);
  laser.setlidaropt(LidarPropScanFrequency, &f_optvalue, sizeof(float));

  bool invalid_range_is_inf = false;
  node->declare_parameter("invalid_range_is_inf");
  node->get_parameter("invalid_range_is_inf", invalid_range_is_inf);


  bool ret = laser.initialize();
  if (ret) {
    ret = laser.turnOn();
  } else {
    RCLCPP_ERROR(node->get_logger(), "%s\n", laser.DescribeError());
  }
  
  auto laser_pub = node->create_publisher<sensor_msgs::msg::LaserScan>("scan", rclcpp::SensorDataQoS());

  auto stop_scan_service =
    [&laser](const std::shared_ptr<rmw_request_id_t> request_header,
  const std::shared_ptr<std_srvs::srv::Empty::Request> req,
  std::shared_ptr<std_srvs::srv::Empty::Response> response) -> bool
  {
    return laser.turnOff();
  };

  auto stop_service = node->create_service<std_srvs::srv::Empty>("stop_scan",stop_scan_service);

  auto start_scan_service =
    [&laser](const std::shared_ptr<rmw_request_id_t> request_header,
  const std::shared_ptr<std_srvs::srv::Empty::Request> req,
  std::shared_ptr<std_srvs::srv::Empty::Response> response) -> bool
  {
    return laser.turnOn();
  };

  auto start_service = node->create_service<std_srvs::srv::Empty>("start_scan",start_scan_service);

  rclcpp::WallRate loop_rate(20);


  while (ret && rclcpp::ok()) {
    
    LaserScan scan;//

    if (laser.doProcessSimple(scan)) {

      auto scan_msg = std::make_shared<sensor_msgs::msg::LaserScan>();

      scan_msg->header.stamp.sec = RCL_NS_TO_S(scan.stamp);
      scan_msg->header.stamp.nanosec =  scan.stamp - RCL_S_TO_NS(scan_msg->header.stamp.sec);
      scan_msg->header.frame_id = frame_id;
      scan_msg->angle_min = scan.config.min_angle;
      scan_msg->angle_max = scan.config.max_angle;
      scan_msg->angle_increment = scan.config.angle_increment;
      scan_msg->scan_time = scan.config.scan_time;
      scan_msg->time_increment = scan.config.time_increment;
      scan_msg->range_min = scan.config.min_range;
      scan_msg->range_max = scan.config.max_range;

      float range_data[1050] = {0};
      
      int size = (scan.config.max_angle - scan.config.min_angle)/ scan.config.angle_increment + 1;
      scan_msg->ranges.resize(size);
      scan_msg->intensities.resize(size);
      for(size_t i=0; i < scan.points.size(); i++) {
        int index = std::ceil((scan.points[i].angle - scan.config.min_angle)/scan.config.angle_increment);
        if(index >=0 && index < size) {
          scan_msg->ranges[index] = scan.points[i].range;
          scan_msg->intensities[index] = scan.points[i].intensity;
          
          //code start
          range_data[i] = scan.points[i].range;
        }
      }

      const int num_arrays = 360;
      int points = scan.points.size();

      int arr_size = sizeof(range_data) / sizeof(range_data[0]);
      vector<float> data(range_data, range_data + arr_size);
      vector<vector<float>> arrays(num_arrays);

      int index = 0;
      
      for (int j = 0; j < num_arrays; j++) {
        int num_elements = points / num_arrays;
        if (j < points % num_arrays) {
          num_elements++;
        }
        for (int k = 0; k < num_elements; k++) {
          arrays[j].push_back(data[index]);
          index++;
        }
      }

      float arr_sum = 0;
      float col_sum = 0;

      for (int a = 0; a < 5; a++) {
        for (long unsigned int b = 0; b < arrays[a].size(); b++) {
          col_sum += arrays[a][b];
          arr_sum = col_sum / arrays[a].size();
        }
      }
      
      /*
      //Show 0~360 Arrays
      for (int i = 0; i < 360; i++) {
        for (int n = 0; n < arrays[i].size(); n++) {
          cout << i << ":" << arrays[i][n];
        }
      }
      cout << "--------------------------------------" << endl;
      */
      
      /******************mapping******************/
      #define MAP_SIZE_X 60
      #define MAP_SIZE_Y 60
      #define MY_POINT_X 30
      #define MY_POINT_Y 30
      
      int x, y;

      int map_inf[MAP_SIZE_X][MAP_SIZE_Y] = { 0 };
      map_inf[MY_POINT_X][MY_POINT_Y] = 2; //My position

      auto print_map = [&](){
        system("clear");
        for (int m = 0; m < MAP_SIZE_X; m++) {
          for (int n = 0; n < MAP_SIZE_Y; n++) {
            if(map_inf[m][n] == 1) {
              cout << "■";
            }
            else if (map_inf[m][n] == 2) {
              cout << "★"; //require repair
            }
            else {
              cout << "0";
            }
          }
          cout << endl;
        }
      };
      
      //input resource in map_inf
      for (int angle = 0; angle < 360; angle++) {
        for (int distance = 0; distance < arrays[angle].size(); distance++) {
          // 각도와 거리값으로 x, y 계산
          double rad = angle * M_PI / 180.0;
          x = arrays[angle][distance] * 100 * cos(rad) + MY_POINT_X;
          y = arrays[angle][distance] * 100 * sin(rad) + MY_POINT_Y;
          if(x >= 0 && x < MAP_SIZE_X && y >= 0 && y < MAP_SIZE_Y) {
              map_inf[x][y] = 1;
          }
        }
      }

      print_map();  // 배열 출력
      /****************mapping_end****************/
      

      /*
      float avg = arr_sum / 5;

      if (avg < 1) {
        cout << "CLOSE" << endl;
        digitalWrite(IN_FL_1, LOW);
        digitalWrite(IN_FL_2, LOW);
        digitalWrite(IN_BL_1, LOW);
        digitalWrite(IN_BL_2, LOW);
        digitalWrite(IN_FR_1, LOW);
        digitalWrite(IN_FR_2, LOW);
        digitalWrite(IN_BR_1, LOW);
        digitalWrite(IN_BR_2, LOW);
        softPwmWrite(EN_FL, 0);
        softPwmWrite(EN_BL, 0);
        softPwmWrite(EN_FR, 0);
        softPwmWrite(EN_BR, 0);
        }
      else {
        cout << "ok" << endl;
        // FL-MOTER 전진
        OUT_FL_1 = LOW;
        OUT_FL_2 = HIGH;
        digitalWrite(IN_FL_1, OUT_FL_1);
        digitalWrite(IN_FL_2, OUT_FL_2);
        softPwmWrite(EN_FL, 30);
      
        // BL-MOTER 전진
        OUT_BL_1 = LOW;
        OUT_BL_2 = HIGH;
        digitalWrite(IN_BL_1, OUT_BL_1);
        digitalWrite(IN_BL_2, OUT_BL_2);
        softPwmWrite(EN_BL, 30);
      
        // FR-MOTER 전진
        OUT_FR_1 = HIGH;
        OUT_FR_2 = LOW;
        digitalWrite(IN_FR_1, OUT_FR_1);
        digitalWrite(IN_FR_2, OUT_FR_2);
        softPwmWrite(EN_FR, 30);
      
        // BR-MOTER 전진
        OUT_BR_1 = HIGH;
        OUT_BR_2 = LOW;
        digitalWrite(IN_BR_1, OUT_BR_1);
        digitalWrite(IN_BR_2, OUT_BR_2);
        softPwmWrite(EN_BR, 30);
        }
        */

      laser_pub->publish(*scan_msg);
    } else {
      RCLCPP_ERROR(node->get_logger(), "Failed to get scan");
    }
    if(!rclcpp::ok()) {
      break;
    }
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }

  RCLCPP_INFO(node->get_logger(), "[YDLIDAR INFO] Now YDLIDAR is stopping .......");
  laser.turnOff();
  laser.disconnecting();
  rclcpp::shutdown();

  return 0;
}
