/*
P1024 一元三次方程求解

思路：零点存在定理，（二分法）
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
float a,b,c,d;

float f(float x)
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

float two_decimal(float x) // 保留两位小数
{
    return float(int(x*100))/100;
}

float binary_search(float a,float b)
{
    float left_value,right_value,mid_value;
    left_value = f(a);
    right_value = f(b);
    float mid = two_decimal((a+b)/2);
    if(mid == a ||mid == b) // 区间长度小于等于0.01
    {
        mid_value = f(a + 0.005);
        if(mid_value == 0)
            return b;
        if(left_value * mid_value < 0)
            return a;
        else
            return b;
    } 
    mid_value = f(mid);
    if(mid_value == 0)
        return mid;
    if(left_value * mid_value < 0)
        return binary_search(a, mid); // 迭代
    else
        return binary_search(mid, b);
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
            x[n] = binary_search(i-1,i);
            n++;
        }
        last_value = value;
    }
    printf("%.2f %.2f %.2f",x[0],x[1],x[2]);
}