#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
int dp[259][259][259];
char descr[4][259];
int nextp[100009][26];
int h;
int si[4];
void calc(int a1, int a2, int a3)
{
    dp[a1][a2][a3]=h;
    if(a1>0 && dp[a1-1][a2][a3]<h)
    {
        dp[a1][a2][a3]=min(dp[a1][a2][a3], nextp[dp[a1-1][a2][a3]][descr[1][a1]-'a']);
    }
    if(a2>0 && dp[a1][a2-1][a3]<h)
    {
        dp[a1][a2][a3]=min(dp[a1][a2][a3], nextp[dp[a1][a2-1][a3]][descr[2][a2]-'a']);
    }
    if(a3>0 && dp[a1][a2][a3-1]<h)
    {
        dp[a1][a2][a3]=min(dp[a1][a2][a3], nextp[dp[a1][a2][a3-1]][descr[3][a3]-'a']);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>q;
    cin>>s;
    s="."+s;
    h++;
    for(int k=0; k<26; k++)
    {
        nextp[h-1][k]=h;
        for(int j=h-2; j>=0; j--)
        {
            if(s[j+1]-'a'==k) nextp[j][k]=j+1;
            else nextp[j][k]=nextp[j+1][k];
        }
    }
    for(int tt=1; tt<=q; tt++)
    {
        char qtp;
        int ind;
        cin>>qtp>>ind;
        if(qtp=='+')
        {
            char nextch;
            cin>>nextch;
            si[ind]++;
            descr[ind][si[ind]]=nextch;
            if(ind==1)
            {
                for(int u=0; u<=si[2]; u++)
                {
                    for(int v=0; v<=si[3]; v++)
                    {
                        calc(si[1], u, v);
                    }
                }
            }
            else if(ind==2)
            {
                for(int u=0; u<=si[1]; u++)
                {
                    for(int v=0; v<=si[3]; v++)
                    {
                        calc(u, si[2], v);
                    }
                }
            }
            else
            {
                for(int u=0; u<=si[1]; u++)
                {
                    for(int v=0; v<=si[2]; v++)
                    {
                        calc(u, v, si[3]);
                    }
                }
            }
            if(dp[si[1]][si[2]][si[3]]<h) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            si[ind]--;
            if(dp[si[1]][si[2]][si[3]]<h) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}