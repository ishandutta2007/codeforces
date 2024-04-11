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

int n, l, r, s;

int tri(int x) { return x*(x+1)/2; }

void solve(int st, int xcl)
{
    l--;
    r--;
    int cnt=r-l+1;
    int pl=l;
    vector<bool> was(n+1, false);
    vi ans(n, -1);
    for(int i=st; i<=st+cnt; i++)
    {
        if(i==xcl) continue;
        was[i]=true;
        ans[pl]=i;
        pl++;
    }
    int id=1;
    for(int p=0; p<n; p++)
    {
        if(ans[p]==-1)
        {
            while(id<=n && was[id]) id++;
            ans[p]=id;
            was[id]=true;
        }
    }
    for(int p=0; p<n; p++)
    {
        cout<<ans[p]<<" ";
    }
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>l>>r>>s;
        bool ok=false;
        int cnt=r-l+1;
        for(int st=1; st<=n; st++)
        {
            if(st+cnt-1>n) continue;
            if(tri(st+cnt-1)-tri(st-1)==s)
            {
                solve(st, st+cnt);
                ok=true;
                break;
            }
            if(st+cnt>n) continue;
            int y=tri(st+cnt)-tri(st-1);
            int xcl=y-s;
            if(st<=xcl && xcl<=st+cnt)
            {
                solve(st, xcl);
                ok=true;
                break;
            }
        }
        if(!ok)
        {
            cout<<-1<<'\n';
        }
    }
    return 0;
}