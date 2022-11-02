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
        ll answer=-1;
        ll a, b;
        cin>>a>>b;
        ll ans=0;
        if(b==1)
        {
            b++;
            ans++;
        }
        for(int i=0; i<5; i++)
        {
            ll bb=b;
            ll cans=ans;
            for(int j=1; j<=i; j++)
            {
                cans++;
                bb++;
            }
            ll aa=a;
            while(aa>0)
            {
                aa/=bb;
                cans++;
            }
            if(answer==-1 || cans<answer) answer=cans;
        }

        cout<<answer<<'\n';
    }
    return 0;
}