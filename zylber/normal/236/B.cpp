#include <iostream>
#include <cstring>
using namespace std;

long long div[1000001];

long long cantdiv(int n)
{
    if(div[n]!=-1) return div[n];
    
    long long &ans=div[n];
    
    ans=0;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            ans++;
            if(i*i!=n) ans++;
        }
    }
    return ans;
}

int main()
{
    memset(div, -1, sizeof(div));
    
    long long a, b, c;
    cin >> a >> b >> c;
    
    long long ans=0;
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            for(int k=1; k<=c; k++)
            {
                ans+=cantdiv(i*j*k);
                ans%=(1LL<<30LL);
            }
    cout << ans << endl;
}