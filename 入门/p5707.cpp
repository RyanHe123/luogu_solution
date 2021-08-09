/*
P5707: 上学迟到

思路：计算所需分钟（最迟，所以所需时间应该向上进位），从8点往回倒，
超过8小时则回到前一天。
*/

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int s,v;
    cin >> s >> v;
    int min_sum = s/v;
    if (s % v != 0)
        min_sum ++;
    min_sum += 10;
    int hour = min_sum / 60;
    int min = min_sum % 60;
    int time_min = 60 - min;
    int time_hour = (8 + 24 - hour - 1) % 24;
    printf("%02d:%02d",time_hour,time_min);
}