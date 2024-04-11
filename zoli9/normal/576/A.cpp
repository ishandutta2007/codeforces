#include <bits/stdc++.h>
using namespace std;
long long n;
long long db;
bool jo[1109];
int main()
{
    cin>>n;
    long long cnt=2;
    while(cnt<=1005)
    {
        while(jo[cnt])
        {
            cnt++;
        }
        for(long long i=2*cnt; i<=1100; i+=cnt)
        {
            jo[i]=true;
        }
        cnt++;
    }
    db=0;
    for(long long i=2; i<=n; i++)
    {
        if(!jo[i])
        {
            long long m=i;
            long long w=0;
            while(m<=n)
            {
                m*=i;
                w++;
            }
            db+=w;
        }
    }
    cout<<db<<endl;
    for(long long i=2; i<=n; i++)
    {
        if(!jo[i])
        {
            long long m=i;
            while(m<=n)
            {
                cout<<m<<" ";
                m*=i;
            }
        }
    }
    return 0;
}