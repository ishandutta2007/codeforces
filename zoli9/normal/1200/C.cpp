#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll n, m;
int test;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>test;
    ll g=__gcd(n, m);
    ll n1=n/g;
    ll m1=m/g;
    int sx, ex;
    ll sy, ey;
    ll sec1, sec2;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>sx>>sy>>ex>>ey;
        if(sx==1) sec1=(sy-1)/n1;
        else sec1=(sy-1)/m1;
        if(ex==1) sec2=(ey-1)/n1;
        else sec2=(ey-1)/m1;

        //cout<<n1<<" : "<<m1<<endl;

        if(sec1==sec2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}