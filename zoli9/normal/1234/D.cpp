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
set<int> H[26];
int q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        H[s[i]-'a'].insert(i+1);
    }
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        int tip, le, ri, pos;
        char cc;
        cin>>tip;
        if(tip==1)
        {
            cin>>pos;
            cin>>cc;
            H[s[pos-1]-'a'].erase(pos);
            s[pos-1]=cc;
            H[cc-'a'].insert(pos);
        }
        else
        {
            cin>>le>>ri;
            int ans=0;
            for(int i=0; i<26; i++)
            {
                auto it=H[i].lower_bound(le);
                if(it!=H[i].end())
                {
                    if(*it <= ri) ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}