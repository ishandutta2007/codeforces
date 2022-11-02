#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {

        ll a, b, n;
        cin>>a>>b>>n;
        if(n%3==0) cout<<a<<endl;
        else if(n%3==1) cout<<b<<endl;
        else cout<<(a^b)<<endl;
    }

    return 0;
}