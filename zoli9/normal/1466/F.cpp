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
int m, n;
int infi=1e8;
int apa[500009];
int mag[500009];
ll MOD=1e9+7;

int holvan(int x)
{
    if(apa[x]==x) return x;
    return apa[x]=holvan(apa[x]);
}

void unio(int x, int y)
{
    if(mag[x]>mag[y])
    {
        apa[y]=x;
    }
    else
    {
        apa[x]=y;
        if(mag[x]==mag[y]) mag[y]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1; i<=n; i++)
    {
        apa[i]=i;
        mag[i]=1;
    }
    vector<int> answer;
    for(int i=1; i<=m; i++)
    {
        int k, x, y;
        cin>>k;
        if(k==1)
        {
            cin>>x;
            x=holvan(x);
            if(mag[x]!=infi)
            {
                mag[x]=infi;
                answer.push_back(i);
            }
        }
        else
        {
            cin>>x>>y;
            x=holvan(x);
            y=holvan(y);
            if(x==y || (mag[x]==infi && mag[y]==infi)) continue;
            unio(x, y);
            answer.push_back(i);
        }
    }
    ll ans1=1;
    int si=answer.size();
    for(int i=1; i<=si; i++)
    {
        ans1=(2*ans1)%MOD;
    }
    cout<<ans1<<" "<<si<<endl;
    for(int i: answer) cout<<i<<" ";
    cout<<endl;
    return 0;
}