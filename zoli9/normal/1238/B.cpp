#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int test;
ll n, r;
vi v, w;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>r;
        v.resize(n);
        for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(), v.end());
        w.clear();
        w.push_back(v[0]);
        for(int i=1; i<n; i++)
        {
            if(v[i]>v[i-1]) w.push_back(v[i]);
        }
        int kezd=0;
        int ans=0;
        while(w.size()>0 && w.back()>kezd)
        {
            ans++;
            w.pop_back();
            kezd+=r;
        }
        cout<<ans<<endl;
    }


    return 0;
}