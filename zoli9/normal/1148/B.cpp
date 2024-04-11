#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m, k;
ll ta, tb;
ll a[200009];
ll b[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>ta>>tb>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
    }
    if(k>=n || k>=m)
    {
        cout<<-1<<endl;
        return 0;
    }
    int bcnt=1;
    ll ans=0;
    for(int i=1; i<=k+1; i++)
    {
        int rem=k-(i-1);
        while(bcnt<=m && a[i]+ta>b[bcnt]) bcnt++;
        int best=bcnt+rem;
        if(best>m)
        {
            cout<<-1<<endl;
            return 0;
        }
        ans=max(ans, tb+b[best]);
    }
    cout<<ans<<endl;
    return 0;
}