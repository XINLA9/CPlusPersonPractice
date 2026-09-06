// 传感器解包.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int parse_register_value(int packet) {
    // write code here

    if ((packet & 1) == 0) {
        return -1;
    }

    int id = (packet >> 1) & 0b11;

    int type = (packet >> 3) & 0b1;

    int xiuzheng = (packet >> 4) & 0b11111111;

    int length = (packet >> 12) & 0b1111;
    if (type == 0) {
        length = 15;
    }

    int date = packet << 1;
    date = date >> 17;
    if (type == 1) {
        if (length == 0) {
            return -3;
        }
        int d = 0;
        // cout << d << endl;
        for (int i = 0; i < length; i++) {
            d = i << 1;
            d += 1;
        }
        date &= d;
    }

    int even = packet >> 31;
    int vaild = even;
    for (int i = 0; i < length; i++) {
        vaild += (date >> i) & 1;
    }
    if (even % 2 == 1) {
        return -2;
    }

    if (id == 0) {
        date &= xiuzheng;
        return date & 0x0FFFFFFF;
    }
    else if (id == 1) {
        date |= xiuzheng;
        return date & 0x0FFFFFFF;
    }
    else if (id == 2) {
        date ^= xiuzheng;
        return date & 0x0FFFFFFF;
    }
    else {
        int d1 = date & xiuzheng;
        int d2 = (~date) & (~xiuzheng);
        int d3 = d1 | d2;
        return d3 & 0x0FFFFFFF;
    }
}


int main()
{
    std::cout << "Hello World!\n";
}


