#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define SZ(x) ((int)(x).size())

string to_s(int x)
{
    string ret="";
    while (x)
    {
        ret.push_back((x%10)+'0');
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int to_int(string s,int p)
{
    long long ret=0;
    for (char i:s)
    {
        ret *= 10;
        ret += (i-'0');
        ret %= p;
    }
    return ret;
}

int main ()
{
    int k,p;
    cin >> k >> p;
    int ans=0;
    for (int i=1;k>=i;i++)
    {
        string s=to_s(i);
        string t=s;
        reverse(s.begin(),s.end());
        ans += to_int(t + s,p);
        ans %= p;
    }
    cout << ans << endl;
}