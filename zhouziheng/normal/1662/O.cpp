#include<bits/stdc++.h>
#define id(i,j) ((i)*360+(j))
using namespace std;
int T,n;
bool tag1[22][360],tag2[22][360];
vector<int> G[22*360];
bool vis[22*360];
queue<int> Q;
void solve(){
    memset(tag1,0,sizeof(tag1));
    memset(tag2,0,sizeof(tag2));
    for(int i=0;i<22*360;i++) G[i].clear(),vis[i]=0;
    scanf("%d",&n);
    char ch;int x,y,z;
    for(int i=1;i<=n;i++){
        scanf(" %c %d %d %d",&ch,&x,&y,&z);
        if(ch=='C'){
            for(int i=y;i!=z;i=(i+1)%360) tag1[x][i]=1;
        }else{
            for(int i=x;i<y;i++) tag2[i][z]=1;
        }
    }
    for(int i=0;i<=20;i++){
        for(int j=0;j<360;j++){
            if(tag2[i][(j+1)%360]) continue;
            G[id(i,j)].push_back(id(i,(j+1)%360));
            G[id(i,(j+1)%360)].push_back(id(i,j));
        }
    }
    for(int i=1;i<=20;i++){
        for(int j=0;j<360;j++){
            if(tag1[i][j]) continue;
            // printf("%d %d %d %d\n",i,j,id(i,j),id(i-1,j));
            G[id(i,j)].push_back(id(i-1,j));
            G[id(i-1,j)].push_back(id(i,j));
        }
    }
    vis[0]=1;Q.push(0);
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        // printf("%d\n",x);
        for(auto to:G[x]){
            if(vis[to]) continue;
            vis[to]=1;Q.push(to);
        }
    }
    bool pd=0;
    for(int i=0;i<360;i++) pd|=vis[id(20,i)];
    if(pd) puts("YES");
    else puts("NO");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}