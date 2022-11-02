#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    long long given=(n+k)*2;
    long long p=-3+sqrt(9+4*given);
    p/=2;
    cout<<n-p<<endl;

    return 0;
}