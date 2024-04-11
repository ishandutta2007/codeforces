#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[509][509];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int db=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='*') db++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(c[i][j]!='*' || i==1 || i==n || j==1 || j==m) continue;
            int cnt=1;
            int ii=i-1;
            while(ii>=1 && c[ii][j]=='*')
            {
                cnt++;
                ii--;
            }
            if(ii==i-1) continue;
            ii=i+1;
            while(ii<=n && c[ii][j]=='*')
            {
                cnt++;
                ii++;
            }
            if(ii==i+1) continue;
            int jj=j-1;
            while(jj>=1 && c[i][jj]=='*')
            {
                cnt++;
                jj--;
            }
            if(jj==j-1) continue;
            jj=j+1;
            while(jj<=m && c[i][jj]=='*')
            {
                cnt++;
                jj++;
            }
            if(jj==j+1) continue;
            if(cnt==db)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }

    cout<<"NO"<<endl;
    return 0;
}