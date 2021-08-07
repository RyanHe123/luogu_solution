/*
P1739 表达式括号匹配

思路：变量储存括号数量
*/

#include<iostream>
using namespace std;
int main()
{
    char * exp;
    cin >> exp;
    int left = 0;
    for(int i=0;exp[i];i++)
    {
        if(exp[i]=='@')
            break;
        if(exp[i]=='(')
            left += 1;
        if(exp[i]==')')
            left -= 1;
            if(left < 0)
                break;
    }
    if(left==0)
        cout << "YES";
    else
        cout << "NO";
}