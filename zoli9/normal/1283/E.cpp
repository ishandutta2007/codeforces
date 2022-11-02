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
int n;
vi v;
bool w[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        w[v[i]]=true;
    }
    sort(v.begin(), v.end());
    int maxi=0;
    int last=-1;
    for(int i=0; i<n; i++)
    {
        if(v[i]-1>last)
        {
            last=v[i]-1;
            maxi++;
        }
        else if(v[i]>last)
        {
            last=v[i];
            maxi++;
        }
        else if(v[i]+1>last)
        {
            last=v[i]+1;
            maxi++;
        }
    }
    int mini=0;
    for(int i=1; i<=n; i++)
    {
        if(w[i])
        {
            mini++;
            i+=2;
        }
    }
    cout<<mini<<" "<<maxi<<endl;

    return 0;
}