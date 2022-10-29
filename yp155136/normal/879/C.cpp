#include <bits/stdc++.h>
using namespace std;

const int N = 500006;
const int C = 10;

string cmd[N];
int a[N][C];

int main ()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >>n;
    for (int i=0;n>i;i++)
    {
        cin >> cmd[i];
        int x;
        cin >>x;
        for (int j=0;C>j;j++)
        {
            if (((1<<j)&x) != 0) a[i][j] = 1;
        }
    }
    int num1=0,num2=0,num3=0;
    //^ | ^
    for (int j=0;C>j;j++)
    {
        int _0=0,_1=1;
        for (int i=0;n>i;i++)
        {
            if (cmd[i] == "|")
            {
                _0 |= a[i][j];
                _1 |= a[i][j];
            }
            else if (cmd[i] == "&")
            {
                _0 &= a[i][j];
                _1 &= a[i][j];
            }
            else if (cmd[i] == "^")
            {
                _0 ^= a[i][j];
                _1 ^= a[i][j];
            }
        }
        if (_0 == 0 && _1 == 0)
        {
            num1 |= (1<<j);
            num2 |= (1<<j);
            num3 |= (1<<j);
        }
        else if (_0 == 0 && _1==0)
        {
            ;
        }
        else if (_0 == 1 && _1==0)
        {
            num3 |= (1<<j);
        }
        else if (_0 == 1 && _1==1)
        {
            num2 |= (1<<j);
        }
    }
    cout << 3 <<endl;
    cout << "^ "<<num1<<endl;
    cout << "| "<<num2<<endl;
    cout << "^ "<<num3<<endl;
}