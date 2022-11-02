#include <bits/stdc++.h>
using namespace std;
long long d[3009][3009];
string s;
int n;
long long ans;
int main()
{
    //freopen("be.txt", "r", stdin);
    cin>>s;
    n=s.length()/2+1;
    for(int i=0; i<n; i++)
    {
        d[i][i]=s[2*i]-'0';
        for(int j=i+1; j<n; j++)
        {
            int k=j;
            d[i][j]=s[2*k]-'0';
            while(k>i and s[2*k-1]=='*')
            {
                k--;
                d[i][j]*=(s[2*k]-'0');
            }
            if(k>i) d[i][j]+=d[i][k-1];
        }
    }
    ans=d[0][n-1];
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            long long akt=d[i][j];
            int a1, a2;
            a1=i-1;
            a2=j+1;
            while(0<=a1 and s[2*a1+1]=='*')
            {
                akt*=s[2*a1]-'0';
                a1--;
            }
            while(n>a2 and s[2*a2-1]=='*')
            {
                akt*=s[2*a2]-'0';
                a2++;
            }
            if(a1>=0)
            {
                akt+=d[0][a1];
            }
            if(a2<n)
            {
                akt+=d[a2][n-1];
            }
            ans=max(ans, akt);
        }
    }
    cout<<ans;
    return 0;
}