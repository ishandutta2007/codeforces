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
int n;
vpii ans;
void solve(int k, int v)
{
    int m=v-k+1;
    if(m==1) return;
    int mid=k+m/2;
    solve(k, mid-1);
    solve(mid, v);
    for(int i=0; i<m/2; i++)
    {
        ans.push_back({k+i, mid+i});
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x=1;
    while(2*x<n) x*=2;
    solve(1, x);
    solve(n-x+1, n);
    cout<<ans.size()<<'\n';
    for(pii P: ans)
    {
        cout<<P.F<<" "<<P.S<<'\n';
    }
    return 0;
}