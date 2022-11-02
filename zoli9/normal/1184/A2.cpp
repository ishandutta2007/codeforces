#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool valasz[200009];
int sdb=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    sdb+=(s[0]-'0');
    for(int i=1; i<n; i++)
    {
        sdb+=(s[i]-'0');
        if(n%i==0)
        {
            valasz[i]=true;
            for(int kezd=0; kezd<i; kezd++)
            {
                int db=(s[kezd]-'0');
                int j=(kezd+i)%n;
                while(j!=kezd)
                {
                    db+=(s[j]-'0');
                    j=(j+i)%n;
                }
                if(db%2==1)
                {
                    valasz[i]=false;
                    break;
                }
            }
        }
    }
    int ans=0;
    if(sdb==0) ans++;
    for(int i=1; i<n; i++)
    {
        int lepes=__gcd(i, n);
        if(valasz[lepes]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}