#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ossz1, ossz2;
int mindif, dif;
int kell1, kell2;
long long hany[2009][2009];
const long long MOD=1000000007;
long long ans=0;
string s;
int main()
{
    for(long long i=0; i<=2005; i++)
    {
        hany[i][0]=1;
    }
    for(long long j=1; j<=2005; j++)
    {
        for(long long i=j; i<=2005; i++)
        {
            hany[i][j]=hany[i-1][j]+hany[i][j-1];
            hany[i][j]%=MOD;
        }
    }
    cin>>n>>m;
    cin>>s;
    mindif=0;
    dif=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            ossz1++;
            dif++;
        }
        else
        {
            ossz2++;
            dif--;
            mindif=min(mindif, dif);
        }
    }
    if((dif+n-m)%2==1)
    {
        cout<<0;
        return 0;
    }
    kell2=(dif+n-m)/2;
    kell1=(n-m)-kell2;
    if(kell1<0 || kell2<0)
    {
        cout<<0;
        return 0;
    }
    //cout<<kell1<<" "<<kell2<<endl;
    for(long long k1=0; k1<=kell1; k1++)
    {
        for(long long k2=0; k2<=kell2; k2++)
        {
            if(k1-k2+mindif>=0)
            {
                if(k1>=k2 && (kell2-k2)>=(kell1-k1))
                {
                    //cout<<":)"<<k1<<" "<<k2<<endl;
                    //cout<<hany[k1][k2]<<" "<<hany[kell2-k2][kell1-k1]<<endl;
                    long long meg=hany[k1][k2]*hany[kell2-k2][kell1-k1];
                    meg%=MOD;
                    //cout<<meg<<endl;
                    ans+=meg;
                    ans%=MOD;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}