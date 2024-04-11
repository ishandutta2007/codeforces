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
map<string, int> m;
string s;
string pr[109];
int darab[109][26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cout<<"? "<<1<<" "<<n<<endl;
    for(int i=1; i<=(n*(n+1))/2; i++)
    {
        cin>>s;
        sort(s.begin(), s.end());
        m[s]++;
    }
    if(n==1)
    {
        cout<<"! "<<s<<endl;
        return 0;
    }
    cout<<"? "<<2<<" "<<n<<endl;
    for(int i=1; i<=(n*(n-1))/2; i++)
    {
        cin>>s;
        sort(s.begin(), s.end());
        m[s]--;
    }
    auto it=m.begin();
    while(it!=m.end())
    {
        if(it->second > 0)
        {
            pr[(it->first).size()]=(it->first);
        }
        it++;
    }
    for(int i=n; i>=1; i--)
    {
        for(int j=0; j<i; j++)
        {
            darab[i][pr[i][j]-'a']++;
        }
    }
    string ans="";
    for(int i=1; i<=n; i++)
    {
        int kul=0;
        for(int j=0; j<26; j++)
        {
            if(darab[i][j]!=darab[i-1][j])
            {
                kul=j;
                break;
            }
        }
        ans+=((char)('a'+kul));
    }
    cout<<"! "<<ans<<endl;
    return 0;
}