#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
int t[59][59];
int t2[59][59];
vector<pii> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>t[i][j];
        }
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(t[i][j]>0 && t[i][j+1]>0 && t[i+1][j]>0 && t[i+1][j+1]>0)
            {
                t2[i][j]=1;
                t2[i][j+1]=1;
                t2[i+1][j]=1;
                t2[i+1][j+1]=1;
                ans.push_back({i, j});
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(t[i][j]!=t2[i][j])
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(pii p: ans)
    {
    cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}