/*
P1024 一元三次方程求解

思路：零点存在定理，枚举
*/


#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
float a,b,c,d;
float judge_root(int i)
{
    float res = i;
    float last_value = 0;
    float value = 0;
    while(res >= i - 1) // 以0.01为间距进行查找
    {
        value = a * pow(res, 3) + b * pow(res, 2) + c * res + d;
        if(value == 0)
            return res;
        if(last_value * value < 0)
        {
            float mid_value = a * pow(res+0.005, 3) + b * pow(res+0.005, 2) + c * (res+0.005) + d;
            if(mid_value * value < 0)
                return res;
            else
                return res+0.01;
        }
        res -= 0.01;
        last_value = value;
    }
}
int main()
{

    cin >> a >> b >> c >> d;
    float x[3];
    int n=0;
    float last_value = 0;
    for(int i = -100;i <= 100;i++)
    {
        if(n == 3)
            break;
        float value = a * pow(i, 3) + b * pow(i, 2) + c * i + d;

        if(value == 0)
        {
            x[n] = i;
            n++;
        }
        if(value * last_value < 0)
        {
            x[n] = judge_root(i);
            n++;
        }
        last_value = value;
    }
    printf("%.2f %.2f %.2f",x[0],x[1],x[2]);
}