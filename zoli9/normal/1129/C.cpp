#include <bits/stdc++.h>
using namespace std;
int m;
long long MOD=1000000007;
long long a[3009];
long long dp[3009][3009];
int cur_j;
long long ans=0;

class Trie
{
    public:
    Trie(){};
    Trie* children[2]={};
    void berak(int ind)
    {
        if(ind==0)
        {
            return;
        }
        if(children[a[ind]]==NULL)
        {
           children[a[ind]]=new Trie();
           ans=(ans+dp[ind][cur_j])%MOD;
        }
        children[a[ind]]->berak(ind-1);
    }
};
Trie gyoker;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<=m; i++)
    {
        dp[i+1][i]=1;
    }
    for(int vege=1; vege<=m; vege++)
    {
        for(int eleje=1; eleje<=vege; eleje++)
        {
            dp[eleje][vege]=0;

            dp[eleje][vege]+=dp[eleje][vege-1];
            dp[eleje][vege]%=MOD;
            if(eleje+1<=vege)
            {
                dp[eleje][vege]+=dp[eleje][vege-2];
                dp[eleje][vege]%=MOD;
            }
            if(eleje+2<=vege)
            {
                dp[eleje][vege]+=dp[eleje][vege-3];
                dp[eleje][vege]%=MOD;
            }
            if(eleje+3<=vege)
            {
                bool ok=true;
                if(a[vege-3]==0 && a[vege-2]==0 && a[vege-1]==1 && a[vege]==1) ok=false;
                if(a[vege-3]==0 && a[vege-2]==1 && a[vege-1]==0 && a[vege]==1) ok=false;
                if(a[vege-3]==1 && a[vege-2]==1 && a[vege-1]==1 && a[vege]==0) ok=false;
                if(a[vege-3]==1 && a[vege-2]==1 && a[vege-1]==1 && a[vege]==1) ok=false;
                if(ok)
                {
                    dp[eleje][vege]+=dp[eleje][vege-4];
                    dp[eleje][vege]%=MOD;
                }
            }
        }
        cur_j=vege;
        gyoker.berak(vege);
        cout<<ans<<endl;
    }
    return 0;
}