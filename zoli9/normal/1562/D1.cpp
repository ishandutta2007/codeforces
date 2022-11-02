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
int n, q;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>q;
        cin>>s;
        vector<int> px(n+1, 0);
        for(int i=1; i<=n; i++)
        {
            int x=1;
            if(i%2==0) x*=-1;
            if(s[i-1]=='-') x*=-1;
            px[i]=px[i-1]+x;
        }
        for(int i=1; i<=q; i++)
        {
            int a, b;
            cin>>a>>b;
            if(a%2==b%2)
            {
                cout<<1<<'\n';
            }
            else if(px[b]==px[a-1])
            {
                cout<<0<<'\n';
            }
            else
            {
                cout<<2<<'\n';
            }
        }
    }
    return 0;
}