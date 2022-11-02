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
        if(n%2==0)
        {
            for(int i=1; i<=n; i++)
            {
                if(i%2==1) cout<<i+1<<" ";
                else cout<<i-1<<" ";
            }
            cout<<'\n';
        }
        else
        {
            cout<<"3 1 2 ";
            for(int i=4; i<=n; i++)
            {
                if(i%2==0) cout<<i+1<<" ";
                else cout<<i-1<<" ";
            }
        }
    }
    return 0;
}