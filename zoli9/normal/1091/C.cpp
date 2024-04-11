#include <bits/stdc++.h>
using namespace std;
long long n;
set<long long> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(long long d=1; d*d<=n; d++)
    {
        if(n%d==0)
        {
            long long d2=n/d;
            long long sum=d2*(d2-1);
            sum/=2;
            sum*=d;
            s.insert(d2+sum);
            long long sum2=d*(d-1);
            sum2/=2;
            sum2*=d2;
            s.insert(d+sum2);
        }
    }
    for(long long x: s) cout<<x<<" ";
    cout<<endl;
    return 0;
}