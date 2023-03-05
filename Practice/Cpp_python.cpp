#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

extern "C" int add(int a, int b) {
    return a+b;
}
