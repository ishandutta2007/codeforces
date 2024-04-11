#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int a[109];
int b[109];
int c[109][109];
int ans[109][109];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>h;
    for(int i=1; i<=m; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>c[i][j];
            if(c[i][j]==1)
            {
                ans[i][j]=min(a[j], b[i]);
            }
            else ans[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}