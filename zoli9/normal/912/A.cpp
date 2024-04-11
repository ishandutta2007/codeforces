#include <bits/stdc++.h>
using namespace std;
long long A, B, y, g, b;
int main()
{
    ios::sync_with_stdio(false);
    cin>>A>>B;
    cin>>y>>g>>b;
    long long a1, b1;
    a1=2*y+g;
    b1=3*b+g;
    long long ans=max(0ll, a1-A)+max(0ll, b1-B);
    cout<<ans<<endl;
    return 0;
}