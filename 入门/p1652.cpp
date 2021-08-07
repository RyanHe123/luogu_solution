/*
P1652 圆

思路：两个点都不在圆内和两个点都在圆内，不会提供边界，
只有一个在圆内一个在圆外，会提供一个边界。

注意：不能直接计算两个(x-x0)^2+(y-y0)^2-r^2然后直接相乘判断正负，
因为会超int范围
*/
#include<iostream>
using namespace std;
bool is_in_circle(int x,int y,int x0,int y0,int r)
{
    return (x-x0)*(x-x0)+(y-y0)*(y-y0)-r*r < 0;
}

int main()
{
    int n;
    cin >> n;
    int **circle;
    circle = new int *[n];
    for(int i=0;i<n;i++)
        *(circle + i) = new int[3];
    for(int i=0;i<n;i++)
        cin >> circle[i][0];
    for(int i=0;i<n;i++)
        cin >> circle[i][1];
    for(int i=0;i<n;i++)
        cin >> circle[i][2];
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int p = 0;
    for(int i=0;i<n;i++)
    {
        int x,y,r;
        x = circle[i][0];
        y = circle[i][1];
        r = circle[i][2];
        if((is_in_circle(x1,y1,x,y,r)&& !is_in_circle(x2,y2,x,y,r)) | \
        (!is_in_circle(x1,y1,x,y,r)&& is_in_circle(x2,y2,x,y,r)))
            p += 1;
    }
    cout << p;

}