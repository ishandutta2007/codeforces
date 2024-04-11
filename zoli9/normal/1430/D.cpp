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
vector<char> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        s.resize(n);
        for(int i=0; i<n; i++) cin>>s[i];
        vi w;
        int cnt=1;
        for(int i=1; i<n; i++)
        {
            if(s[i]==s[i-1]) cnt++;
            else
            {
                w.push_back(cnt);
                cnt=1;
            }
        }
        w.push_back(cnt);
        int singles=0;
        for(int i=0; i<w.size(); i++)
        {
            singles+=(w[i]-1);
            singles=min(singles, i+1);
        }
        int ws=w.size();
        if(singles>=ws)
        {
            cout<<ws<<'\n';
            continue;
        }
        int ans=singles;
        int rem=ws-singles;
        if(rem%2==0) ans+=(rem/2);
        else ans+=((rem+1)/2);
        cout<<ans<<'\n';
    }
    return 0;
}