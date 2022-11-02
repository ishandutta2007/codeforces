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
string p;
string h;
int db[109][26];
int dbp[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>p;
        cin>>h;
        if(p.size()>h.size())
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0; i<26; i++)
        {
            dbp[i]=0;
        }
        for(int i=0; i<p.size(); i++)
        {
            dbp[p[i]-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<h.size(); j++)
            {
                db[j+1][i]=db[j][i];
                if(h[j]-'a'==i) db[j+1][i]++;
            }
        }
        bool talalt=false;
        for(int st=0; st<=h.size()-p.size(); st++)
        {
            bool ok=true;
            for(int i=0; i<26; i++)
            {
                if(db[st+p.size()][i]-db[st][i]!=dbp[i])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                talalt=true;
                break;
            }
        }
        if(talalt) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}