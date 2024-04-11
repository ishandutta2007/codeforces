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
int finished;

int pmn(int x)
{
    if(x<=n) return x+n;
    else return x-n;
}

int pr[1000009];
bool was[1000009];
vi groups[500009];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n%2==0)
    {
        cout<<"First"<<endl;
        fflush(stdout);
        for(int i=1; i<=n; i++) cout<<i<<" ";
        for(int i=1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
        fflush(stdout);
        cin>>finished;
        return 0;
    }
    cout<<"Second"<<endl;
    fflush(stdout);
    for(int i=1; i<=2*n; i++)
    {
        int g;
        cin>>g;
        groups[g].push_back(i);
    }
    for(int i=1; i<=n; i++)
    {
        pr[groups[i][0]]=groups[i][1];
        pr[groups[i][1]]=groups[i][0];
    }
    vi ans;
    for(int i=1; i<=2*n; i++)
    {
        if(was[i]) continue;
        ans.push_back(i);
        was[i]=true;
        was[pr[i]]=true;
        int x=pmn(pr[i]);
        while(x!=i)
        {
            ans.push_back(x);
            was[x]=true;
            was[pr[x]]=true;
            x=pmn(pr[x]);
        }
    }
    ll sum=0;
    for(int x: ans) sum+=x;
    if(sum%(2*n)==0)
    {
        for(int x: ans) cout<<x<<" ";
        cout<<endl;
        fflush(stdout);
        cin>>finished;
        return 0;
    }
    vector<bool> b(2*n+1, false);
    for(int x: ans) b[x]=true;
    for(int i=1; i<=2*n; i++) if(!b[i]) cout<<i<<" ";
    cout<<endl;
    fflush(stdout);
    cin>>finished;
    return 0;
}