/*
P1146:硬币翻转

思路：一共N个硬币，翻转N-1个硬币，就相当于每次保留一个硬币不动。
硬币分为两类：正面和反面
所以动作也分为两个：保留一个正面，保留一个反面
设有m个正面 n个反面，设保留一个正面动作为P，保留一个反面动作为N。
经过一个P动作，正 ：反 = n+1 : m-1
经过一个N动作，正 ：反 = n-1 ：m+1
如果进行PP或者NN会发现回到了原地，所以讨论PN和NP
PN, 正 : 反 = m-2 : n+2
NP, 正 : 反 = m+2 : n-2
所以我们会发现最短的操作序列就是N/2次的PN操作

字典序最小：即0靠左 1靠右，也就是说从左侧选取符合操作的硬币不翻转
*/

#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    cout << N << endl;
    int * coins;
    coins = new int [N];
    for(int i=0;i<N;i++)
        coins[i] = 0;
    for(int i=0;i<N;i++) // 一共N次操作
    {
        if(i != 0)
            cout << endl;
        int state = 0;
        if(i % 2 == 0)// P操作
        {
            for(int i=0;i<N;i++)
            {
                if(coins[i] == 0 && state == 0)
                    state = 1;
                else
                    coins[i] = (coins[i] + 1) % 2;
                cout << coins[i];
            }
        }
        else
        {
            for(int i=0;i<N;i++)
            {
                if(coins[i] == 1 && state == 0)
                    state = 1;
                else
                    coins[i] = (coins[i] + 1) % 2;
                cout << coins[i];
            }
        }
    }
}