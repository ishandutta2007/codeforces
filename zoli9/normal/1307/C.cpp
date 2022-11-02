#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
int h;
int db[100009][26];
ll dup[26][26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    h=s.size();
    for(int i=0; i<h; i++)
    {
        db[i][s[i]-'a']++;
    }
    for(int j=0; j<26; j++)
    {
        for(int i=h-2; i>=0; i--)
        {
            db[i][j]+=db[i+1][j];
        }
    }
    ll ans=0;
    for(int i=0; i<26; i++)
    {
        ans=max(ans, (ll)db[0][i]);
    }
    for(int i=0; i<h; i++)
    {
        int akt=s[i]-'a';
        for(int j=0; j<26; j++)
        {
            dup[akt][j]+=((ll)(db[i+1][j]));
        }
    }
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            ans=max(ans, dup[i][j]);
        }
    }
    cout<<ans<<endl;

    return 0;
}