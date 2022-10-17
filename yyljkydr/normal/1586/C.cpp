#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,m,q;

string a[N];

vector<int>s[N];

int r[N],c[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        s[i].resize(m+1),a[i].resize(m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=0;i<=m;i++)
        a[0][i]='X';
    for(int i=0;i<=n;i++)
        a[i][0]='X';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j-1]=='X'&&a[i-1][j]=='X');
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int sum=s[n][b]-s[n][a]-s[1][b]+s[1][a];
        if(sum)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}