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

bool g(int x)
{
    if(x%3==0 || x%10==3) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    vi ans;
    int i=1;
    while(ans.size() < 1000)
    {
        if(g(i)) ans.push_back(i);
        i++;
    }
    while(test--)
    {
        int k;
        cin>>k;
        cout<<ans[k-1]<<'\n';
    }
    return 0;
}