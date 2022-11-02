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
        int n, m, k;
        cin>>n>>m>>k;
        if(n%2==0 && m%2==0)
        {
            if(k%2==0) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        else if(n%2==1)
        {
            int mini=m/2;
            if(k>=mini && k%2==mini%2) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        else
        {
            int k2=n*m/2-k;
            int mini=n/2;
            if(k2>=mini && k2%2==mini%2) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
    return 0;
}