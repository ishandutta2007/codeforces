#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
vector<pii> v;
int nx[500009][21];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i].F>>v[i].S;
    }
    sort(v.begin(), v.end());
    int cnt=0;
    int eler=0;
    for(int i=0; i<=500000; i++)
    {
        eler=max(i, eler);
        while(cnt<n && v[cnt].F==i)
        {
            eler=max(eler, v[cnt].S);
            cnt++;
        }
        nx[i][0]=eler;
    }
    for(int j=1; j<20; j++)
    {
        for(int i=0; i<=500000; i++)
        {
            nx[i][j]=nx[nx[i][j-1]][j-1];
        }
    }
    for(int tt=1; tt<=m; tt++)
    {
        int sta, fin;
        cin>>sta>>fin;
        int ans=0;
        for(int j=19; j>=0; j--)
        {
            if(nx[sta][j]<fin)
            {
                sta=nx[sta][j];
                ans+=(1<<j);
            }
        }
        if(ans>n) cout<<-1<<'\n';
        else cout<<ans+1<<'\n';
    }
    return 0;
}