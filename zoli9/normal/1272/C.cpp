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
int n, k;
bool b[26];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>s;
    for(int i=1; i<=k; i++)
    {
        char ccc;
        cin>>ccc;
        b[ccc-'a']=true;
    }
    ll ans=0;
    ll db=0;
    for(int i=0; i<n; i++)
    {
        if(!b[s[i]-'a'])
        {
            ll pl=db*(db+1)/2;
            ans+=pl;
            db=0;
        }
        else db++;
    }
    ll pl=db*(db+1)/2;
    ans+=pl;
    cout<<ans<<endl;
    return 0;
}