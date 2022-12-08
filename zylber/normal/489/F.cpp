#include <iostream>
#include <map>
#include <cstring>
using namespace std;
typedef long long tint;

tint DP[512][512];
tint C[512];
tint MOD;

tint dp(tint a, tint b)
{
    if(DP[a][b]!=-1) return DP[a][b];
    
    tint &ans=DP[a][b];
    if(b>1)
    ans=(C[b]*dp(a+2,b-2))%MOD;
    else
    ans=0;
    
    if(a)
    {
        ans+=((a/2)*dp(a-2,b))%MOD; //Lo ato con si mismo
        ans%=MOD;
        
        ans+=(((C[a]-((a/2)%MOD)+MOD)%MOD)*dp(a-2,b))%MOD; //lo ato con otro cabo
        ans%=MOD;
        
        if(b)
        {
            ans+=(((a*b)%MOD)*dp(a,b-1))%MOD; //lo ato con uno suelto
            ans%=MOD;
        }
        return ans;
    }
    
    if(b<2)
    {
        ans=1-b;
        return ans;
    }
    
    return ans;
}

int cant[512];

/*tint fact(tint n)
{
    if(n) return (n*fact(n-1))%MOD;
    return 1;
}*/

int main()
{
    tint n, m;
    cin >> n >> m >> MOD;
    memset(DP,-1,sizeof(DP));

    for(int i=1; i<=n; i++)
    {
        C[i]=((i*(i-1))/2)%MOD;
    }

    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        for(int i=0; i<n; i++)
        {
            cant[i]+=s[i]-'0';
        }
    }
    
    int sa=0, sb=0;
    for(int i=0; i<n; i++)
    {
        if(cant[i]==0) sb++;
        if(cant[i]==1) sa++;
    }
    
    //cout << sa << " " << sb << endl;
    cout << dp(sa, sb) << endl;
    
    /*for(int i=0; i<=5; i+=2)
        for(int j=0; j+i<=5; j++)
            cout << i << " " << j << " " << dp(i,j) << endl;*/
}