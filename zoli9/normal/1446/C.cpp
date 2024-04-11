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

int bi[200009][30];

int solve(vi& v, int d)
{
    if(d==0) return 0;
    vi a0, a1;
    for(int x: v)
    {
        if(bi[x][d]==0) a0.push_back(x);
        else a1.push_back(x);
    }
    int s0=a0.size();
    int s1=a1.size();
    if(s0==0)
    {
        return solve(a1, d-1);
    }
    else if(s1==0)
    {
        return solve(a0, d-1);
    }
    int r0=solve(a0, d-1);
    int r1=solve(a1, d-1);
    return min(r0+s1-1, r1+s0-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        for(int j=0; j<30; j++)
        {
            bi[i][j]=x%2;
            x/=2;
        }
    }
    vi v;
    for(int i=0; i<n; i++) v.push_back(i);
    cout<<solve(v, 29)<<endl;

    return 0;
}