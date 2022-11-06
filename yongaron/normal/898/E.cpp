#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
vector<long long> a, d;
vector<long long> sq;
int main()
{
    cin>>n;
    for(long long i = 0; i < n; i++)
    {
        long long b;
        cin>>b;
        a.push_back(b);
    }
    for(long long i = 0; i <= 32000; i++)
        sq.push_back(i*i);
    long long s = 0;
    long long z = 0;
    for(long long i = 0; i < n; i++)
    {
        long long x = a[i];
        long long l = 0;
        long long p = 32000;
        while(l < p)
        {
            //cout<<l<<" "<<p<<endl;
            long long m = (l+p)/2;
            if(sq[m] <= x && sq[m+1] > x)
                l = p = m;
            else if(sq[m] <= x)
                l = m;
            else if(sq[m] > x)
                p = m;
        }
        //cout<<x<<" "<<l<<" "<<x-sq[l]<<" "<<sq[l+1]-x<<endl;
        long long diff = min(x-sq[l], sq[l+1]-x);
        if(diff == 0)
            s++;
        else
            d.push_back(diff);
        if(x == 0)
            z++;
    }
    sort(d.begin(), d.end());
    n /= 2;
    long long ans = 0;
    if(s >= n)
    {
        if(z <= n)
        {
            ans = s-n;
        }
        else
        {
            ans = s+z-2*n;
        }
    }
    else
    {
        for(long long i = 0; i < n-s; i++)
        {
            ans += d[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}