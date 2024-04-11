#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        cout<<(a+b+c)/2<<endl;
    }
    return 0;
}