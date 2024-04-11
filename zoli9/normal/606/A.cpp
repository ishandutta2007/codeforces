#include <bits/stdc++.h>
using namespace std;

long long a, b, c, x, y, z;
bool meg(long long d, long long e, long long f)
{
    if(d+e+f<x+y+z) return false;
    if(d>=x && e>=y && f>=z) return true;
    long long plusz=0;
    long long minusz=0;
    if(d>=x) plusz+=(d-x)/2;
    else minusz+=(x-d);
        if(e>=y) plusz+=(e-y)/2;
    else minusz+=(y-e);
        if(f>=z) plusz+=(f-z)/2;
    else minusz+=(z-f);
    if(plusz>=minusz) return true;
    return false;
}
int main()
{
    cin>>a>>b>>c>>x>>y>>z;
    if(meg(a, b, c)) cout<<"Yes";
    else cout<<"No";
    return 0;
}