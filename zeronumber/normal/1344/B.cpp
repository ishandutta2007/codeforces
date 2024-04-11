#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
bool vis[1005][1005];
char s[1005][1005];
int n,m,ans,f[1005],g[1005];
void dfs(int x,int y){
    vis[x][y]=1;
    if (!vis[x][y-1]&&s[x][y-1]=='#') dfs(x,y-1);
    if (!vis[x][y+1]&&s[x][y+1]=='#') dfs(x,y+1);
    if (!vis[x-1][y]&&s[x-1][y]=='#') dfs(x-1,y);
    if (!vis[x+1][y]&&s[x+1][y]=='#') dfs(x+1,y);
}
int main(){
    cin >> n >> m;
    bool flag=1;
    for (int i=1;i<=n;i++) cin >> s[i]+1;
    for (int i=1;i<=n;i++){
        int p=-1;
        for (int j=1;j<=m;j++){
            if (s[i][j]=='#') f[i]=1;
            if (p==-1&&s[i][j]=='#') p=0;
            else if (p==0&&s[i][j]=='.') p=1;
            else if (p==1&&s[i][j]=='#') p=2;
        }
        if (p==2) flag=0;
    }
    for (int i=1;i<=m;i++){
        int p=-1;
        for (int j=1;j<=n;j++){
            if (s[j][i]=='#') g[i]=1;
            if (p==-1&&s[j][i]=='#') p=0;
            else if (p==0&&s[j][i]=='.') p=1;
            else if (p==1&&s[j][i]=='#') p=2;
        }
        if (p==2) flag=0;
    }
    bool of=0,og=0;
    for (int i=1;i<=n;i++) of|=!f[i];
    for (int i=1;i<=m;i++) og|=!g[i];
    if (of^og) flag=0;
    if (!flag){puts("-1");return 0;}
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (s[i][j]=='#'&&!vis[i][j]) dfs(i,j),++ans;
    printf("%d\n",ans);
    return 0;
}