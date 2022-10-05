#include<bits/stdc++.h>
using namespace std;

bool used[255][255];
int n,m,a,p,tot[255][255]={0},f[255][255]={0};

char c;
int GC(){
    for (;1;){
        scanf("%c",&c);
        if (c>='A'&&c<='Z') return c-'A'+1;
        if (c=='.') return -1;
        if (c=='*') return 0;
    }
}

struct P{
    int x,y,z;
}u,v;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
queue<P>q;
void bfs(int ii,int jj){
    for (int i=max(1,ii-30);i<=min(n,ii+30);i++){
        for (int j=max(1,jj-30);j<=min(m,jj+30);j++){
            used[i][j]=0;
        }
    }
    while (!q.empty()) q.pop();
    u=(P){ii,jj,f[ii][jj]*a};
    used[ii][jj]=1;
    q.push(u);
    while (!q.empty()){
        u=q.front();q.pop();
        if (tot[u.x][u.y]<=p) tot[u.x][u.y]+=u.z;
        if (u.z/2==0) continue;
        v.z=u.z/2;
        for (int i=0;i<4;i++){
            v.x=u.x+dx[i];
            v.y=u.y+dy[i];
            if (!used[v.x][v.y]&&f[v.x][v.y]){
                used[v.x][v.y]=1;
                q.push(v);
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d",&n,&m,&a,&p);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            f[i][j]=GC();
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (f[i][j]>0){
                bfs(i,j);
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (tot[i][j]>p) ans++;
        }
    }
    cout<<ans;
}