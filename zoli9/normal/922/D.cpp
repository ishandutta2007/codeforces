#include <bits/stdc++.h>
using namespace std;

struct szo
{
    long long hk,sk;
};

string s[100007];
vector<szo> g;

bool rendez(szo x, szo y)
{
    if(x.sk*y.hk>x.hk*y.sk) return true;
    return false;
}

int main()
{
    //freopen("teszt2.txt", "r", stdin);
    ios::sync_with_stdio(false);
    long long n,oh=0,os=0;
    long long z=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        long long h=0;
        for(int j=0;j<s[i].length();j++)
        {
            if(s[i][j]=='h') h++;
        }
        g.push_back({h,s[i].length()-h});
        oh+=h;
        os+=g[i].sk;
        for(int j=0;j<s[i].length();j++)
        {
            if(s[i][j]=='h') h--;
            else z+=h;
        }
    }
    sort(g.begin(),g.end(),rendez);
    for(int i=0;i<n;i++)
    {
        oh-=g[i].hk;
        os-=g[i].sk;
        z+=g[i].sk*oh;
    }
    cout<<z;
}