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
        cin>>n>>k;
        vpii t(n);
        for(int i=0; i<n; i++)
        {
            cin>>t[i].F>>t[i].S;
        }
        bool okok=false;
        for(int i=0; i<n; i++)
        {
            bool ok=true;
            for(int j=0; j<n; j++)
            {
                if(abs(t[i].F-t[j].F)+abs(t[i].S-t[j].S)>k)
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                okok=true;
                cout<<1<<'\n';
                break;
            }
        }
        if(!okok) cout<<-1<<'\n';
    }
    return 0;
}