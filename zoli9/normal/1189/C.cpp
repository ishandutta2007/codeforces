#include<bits/stdc++.h>
using namespace std;
int n, q;
int t[100009];
int kum[100009];
int dp[100009][18];
bool volt[100009][18];
int loga2[100009];
int kerdez(int a1, int l2)
{
    if(l2==0) return 0;
    if(volt[a1][l2]) return dp[a1][l2];
    dp[a1][l2]=kerdez(a1, l2-1)+kerdez(a1+(1<<(l2-1)), l2-1);
    int o1=(kum[a1+(1<<(l2-1))-1]-kum[a1-1]+10)%10;
    int o2=(kum[a1+(1<<(l2))-1]-kum[a1+(1<<(l2-1))-1]+10)%10;
    if(o1+o2>=10) dp[a1][l2]++;
    volt[a1][l2]=true;
    //cout<<a1<<" : "<<l2<<" is "<<dp[a1][l2]<<endl;
    return dp[a1][l2];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    loga2[1]=0;
    for(int i=2; i<=n; i++)
    {
        loga2[i]=1+loga2[i/2];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        kum[i]=(t[i]+kum[i-1])%10;
    }
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int a1, a2;
        cin>>a1>>a2;
        int lo=loga2[a2-a1+1];
        cout<<kerdez(a1, lo)<<endl;
    }
    return 0;
}