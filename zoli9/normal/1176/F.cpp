#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
bool valtas[200009];
ll dp[200009][10];
ll e11[200009];
ll e12[200009];
ll e13[200009];
ll e2[200009];
ll e3[200009];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int sum=0;
    valtas[0]=true;
    for(int i=1; i<=n; i++)
    {
        int nn;
        cin>>nn;
        for(int j=1; j<=nn; j++)
        {
            int c;
            ll d;
            cin>>c>>d;
            if(c==1)
            {
                if(d>e11[i])
                {
                    e13[i]=e12[i];
                    e12[i]=e11[i];
                    e11[i]=d;
                }
                else if(d>e12[i])
                {
                    e13[i]=e12[i];
                    e12[i]=d;
                }
                else if(d>e13[i])
                {
                    e13[i]=d;
                }
            }
            else if(c==2)
            {
                if(d>e2[i])
                {
                    e2[i]=d;
                }
            }
            else
            {
                if(d>e3[i])
                {
                    e3[i]=d;
                }
            }
        }
    }
    for(int i=n; i>=1; i--)
    {
        for(int p=0; p<10; p++)
        {
            dp[i][p]=dp[i+1][p];
            ll op1=e11[i]+e12[i]+e13[i];
            if(p+3>9) op1+=e11[i];
            if(e13[i]>0)
            {dp[i][p]=max(dp[i][p], op1+dp[i+1][(p+3)%10]);}

            op1=e11[i]+e12[i];
            if(p+2>9) op1+=e11[i];
            if(e12[i]>0)
            {dp[i][p]=max(dp[i][p], op1+dp[i+1][(p+2)%10]);}

            ll maxi=max(e11[i], max(e2[i], e3[i]));
            if(p+1>9) maxi+=maxi;
            dp[i][p]=max(dp[i][p], maxi+dp[i+1][(p+1)%10]);

            op1=e11[i]+e2[i];
            if(p+2>9) op1+=(max(e11[i], e2[i]));
            if(e11[i]>0 && e2[i]>0)
            {
                dp[i][p]=max(dp[i][p], op1+dp[i+1][(p+2)%10]);
            }
        }
    }
    cout<<dp[1][0]<<endl;


    return 0;
}