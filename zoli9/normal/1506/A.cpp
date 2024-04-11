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
        ll n, m, x;
        cin>>n>>m>>x;
        x--;
        ll col=x/n;
        ll row=x%n;
        //cout<<col<<" * "<<row<<endl;
        ll y=row*m+col+1;
        cout<<y<<'\n';
    }
    return 0;
}