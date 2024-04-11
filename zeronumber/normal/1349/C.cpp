#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
bool f[1005][1005],vis[1005][1005];
int a[1005][1005],t,n,m,_;
char s[1005];
queue <pi> q;
void ins(int x,int y,int z){
    if (vis[x][y]) return;
    vis[x][y]=1; a[x][y]=z;
    q.push((pi){x,y});
}
int main(){
    cin >> n >> m >> _;
    for (int i=1;i<=n;i++){
        scanf("%s",s+1);
        for (int j=1;j<=m;j++) f[i][j]=(s[j]=='1')^((i+j)&1);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<m;j++)
            if (f[i][j]!=f[i][j+1]){
                ins(i,j,0);
                ins(i,j+1,0);
            }
    for (int i=1;i<n;i++)
        for (int j=1;j<=m;j++)
            if (f[i][j]!=f[i+1][j]){
                ins(i,j,0);
                ins(i+1,j,0);
            }
    if (q.empty()){
        while (_--){
            int x,y; long long t;
            cin >> x >> y >> t;
            int ans=f[x][y]^((x+y)&1);
            cout << ans << endl;
        }
        return 0;
    }
    while (!q.empty()){
        pi tmp=q.front(); q.pop();
        int x=tmp.F,y=tmp.S,res=a[x][y]+1;
        if (x<n) ins(x+1,y,res);
        if (x>1) ins(x-1,y,res);
        if (y<m) ins(x,y+1,res);
        if (y>1) ins(x,y-1,res);
    }
    while (_--){
        int x,y; long long t; cin >> x >> y >> t;
        int ans=f[x][y]^((x+y)&1);
        if (t>a[x][y]) ans^=(t-a[x][y])&1;
        cout << ans << endl;
    }
    return 0;
}