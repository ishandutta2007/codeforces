#include <bits/stdc++.h>
using namespace std;
int len;
vector<char> v;
int dp[509][509];
int calc(int x, int y)
{
    if(y<x) return 0;
    if(x==y) return 1;
    if(dp[x][y]>0) return dp[x][y];
    int mini=1+calc(x+1, y);
    for(int i=x+1; i<=y; i++)
    {
        if(v[x] == v[i])
        {
            mini=min(mini, calc(x+1, i-1)+calc(i, y));
        }
    }
    dp[x][y]=mini;
    return mini;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>len;
    for(int i=0; i<len; i++)
    {
        char ccc;
        cin>>ccc;
        if(v.size()==0 || ccc!=v.back())
        {
            v.push_back(ccc);
        }
    }
    cout<<calc(0, v.size()-1)<<endl;

    return 0;
}