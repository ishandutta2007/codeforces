#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        vector<int> db(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            db[s[i]-'a']++;
        }
        int ans=0, ans2=0;
        for(int i=0; i<26; i++)
        {
            if(db[i]>=2) ans++;
            else ans2+=db[i];
        }
        cout<<ans+ans2/2<<'\n';
    }
    return 0;
}