#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int test;
int n, k1, k2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k1>>k2;
        bool elso=true;
        for(int i=1; i<=k1; i++)
        {
            int a;
            cin>>a;
        }
        for(int i=1; i<=k2; i++)
        {
            int a;
            cin>>a;
            if(a==n) elso=false;
        }
        if(elso) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}