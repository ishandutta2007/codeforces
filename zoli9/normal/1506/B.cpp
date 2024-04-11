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
        int n, k;
        string s;
        cin>>n>>k;
        cin>>s;
        vi pos;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='*') pos.push_back(i);
        }
        int ans=0;
        int last=pos.back();
        pos.pop_back();
        ans++;
        if(pos.empty())
        {
            cout<<ans<<'\n';
            continue;
        }
        while(pos.size()>1)
        {
            int x=pos.back();
            pos.pop_back();
            if(pos.back()+k<last)
            {
                last=x;
                ans++;
            }
        }
        ans++;
        cout<<ans<<'\n';
    }
    return 0;
}