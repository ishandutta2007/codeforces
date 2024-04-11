#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c, d;
    vi v;
    v.resize(3);
    cin>>v[0]>>v[1]>>v[2]>>d;
    sort(v.begin(), v.end());
    ll kell1=0;
    ll kell2=0;
    if(v[1]-v[0]<d) kell1=d-(v[1]-v[0]);
    if(v[2]-v[1]<d) kell2=d-(v[2]-v[1]);
    cout<<kell1+kell2<<endl;


    return 0;
}