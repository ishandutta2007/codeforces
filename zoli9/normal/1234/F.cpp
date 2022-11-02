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
string s;
int best[1200009];
int rem[1200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        int mask=0;
        for(int j=i; j<n; j++)
        {
            int bi=s[j]-'a';
            if((mask | (1<<bi)) == mask) break;
            mask |= (1<<bi);
            best[mask]=(j-i+1);
        }
    }

    for(int i=0; i<(1<<20); i++)
    {
        rem[i]=best[i];
    }
    for(int i=0; i<20; i++)
    {
        for(int mask=0; mask<(1<<20); mask++)
        {
            if(mask & (1<<i))
            {
                rem[mask]=max(rem[mask], rem[mask-(1<<i)]);
            }
        }
    }
    int ans=0;
    for(int i=0; i<(1<<20); i++)
    {
        int newans=best[i]+rem[(1<<20)-1-i];
        ans=max(ans, newans);
    }
    cout<<ans<<endl;

    return 0;
}