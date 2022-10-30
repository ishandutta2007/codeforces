#include <bits/stdc++.h>
using namespace std;
int test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    long long x, y;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>x>>y;
        cout<<x<<" "<<2*x<<endl;
    }
    return 0;
}