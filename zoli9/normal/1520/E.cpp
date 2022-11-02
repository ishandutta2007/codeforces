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

vll distances(string& s)
{
    vll res;
    int last=-1;
    int steps=0;
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        if(s[i]=='*')
        {
            if(last!=-1)
            {
                res.push_back(steps);
            }
            last=i;
            steps=0;
        }
        else
        {
            steps++;
        }
    }
    return res;
}

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
        string s;
        cin>>s;
        vll d=distances(s);
        int ds=d.size();
        ll ans=0;
        int mid=ds/2;
        for(int i=0; i<mid; i++)
        {
            ans+=(d[i]*(i+1));
        }
        int cnt=1;
        for(int i=ds-1; i>=mid; i--)
        {
            ans+=(d[i]*cnt);
            cnt++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}