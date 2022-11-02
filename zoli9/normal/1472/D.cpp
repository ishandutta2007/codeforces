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
        int n;
        cin>>n;
        vll a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        int turn=1;
        ll alice=0;
        ll bob=0;
        for(int i=n-1; i>=0; i--)
        {
            if(turn==1)
            {
                if(a[i]%2==0) alice+=a[i];
            }
            else
            {
                if(a[i]%2==1) bob+=a[i];
            }
            turn=1-turn;
        }
        if(bob>alice) cout<<"Bob"<<'\n';
        else if(bob==alice) cout<<"Tie"<<'\n';
        else cout<<"Alice"<<'\n';
    }
    return 0;
}