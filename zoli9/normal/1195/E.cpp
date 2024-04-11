#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
int n, m, a, b;
int board[3009][3009];
int board2[3009][3009];
deque<pair<int, int> > dd;
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>a>>b;
    ll gg, xx, yy, zz;
    cin>>gg>>xx>>yy>>zz;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            board[i][j]=gg;
            gg=(gg*xx+yy)%zz;
        }
    }
    //cout<<"jo"<<endl;

    for(int i=1; i<=n; i++)
    {
        dd.clear();
        for(int j=1; j<=m; j++)
        {
            while(dd.size()>0 && dd.back().F>=board[i][j]) dd.pop_back();
            dd.push_back({board[i][j], j});
            if(dd.front().S<=j-b) dd.pop_front();
            if(j>=b) board2[i][j]=dd.front().F;
        }
    }
    for(int j=b; j<=m; j++)
    {
        dd.clear();
        for(int i=1; i<=n; i++)
        {
            while(dd.size()>0 && dd.back().F>=board2[i][j]) dd.pop_back();
            dd.push_back({board2[i][j], i});
            if(dd.front().S<=i-a) dd.pop_front();
            if(i>=a) ans+=((ll)(dd.front().F));
        }
    }
    cout<<ans<<'\n';


    return 0;
}