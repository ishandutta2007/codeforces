#include <iostream>
#include <fstream>
using namespace std;

int mcd(int a, int b)
{
        if(b<a)
            return mcd(b,a);
        if(a==0)
            return b;

        return mcd(b%a,a);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int dd=0;

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        if(i==0)
        {
            dd=a-1;
            while(dd%2==0)
                dd/=2;
        }
        else
            dd=mcd(dd,a-1);
    }

    long long ans=0;
    for(int i=1; i*i<=dd; i++)
    if(dd%i==0)
    {
        int k=i;
        while(k<m)
        {
            ans+=m-k;
            k*=2;
        }
        if(dd!=i*i)
        {
            k=dd/i;
            while(k<m)
            {
                ans+=m-k;
                k*=2;
            }

        }
    }

    cout << ans << endl;
}