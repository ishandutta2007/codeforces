#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long
char mp[2100010];
int n,m;
int vis[2100010];
int vis2[2100010];
struct nod{
    int x,y,c;
}p[2100010];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i*m+j];
        }
    }
    queue<nod> q;
    int flg=0;
    q.push({1,1,1});
    vis[1*m+1]=1;
    while(!q.empty()){
        nod now=q.front();q.pop();
        int x=now.x,y=now.y,c=now.c;
        if(x==n&&y==m){
            flg=1;
        }
        if(x+1<=n&&y<=m&&!vis[(x+1)*m+y]&&mp[(x+1)*m+y]!='#'){
            q.push({x+1,y,c+1});
            vis[(x+1)*m+y]=c+1;
        }
        if(x<=n&&y+1<=m&&!vis[x*m+y+1]&&mp[x*m+y+1]!='#'){
            q.push({x,y+1,c+1});
            vis[x*m+y+1]=c+1;
        }
    }
    if(!flg){
        cout<<0<<endl;
    }
    else{
        queue<nod> q;
        q.push({n,m,1});
        vis2[n*m+m]=1;
        while(!q.empty()){
            nod now=q.front();q.pop();
            int x=now.x,y=now.y,c=now.c;

            if(x-1>=1&&y>=1&&!vis2[(x-1)*m+y]&&mp[(x-1)*m+y]!='#'){
                q.push({x-1,y,c+1});
                vis2[(x-1)*m+y]=c+1;
            }
            if(x>=1&&y-1>=1&&!vis2[x*m+y-1]&&mp[x*m+y-1]!='#'){
                q.push({x,y-1,c+1});
                vis2[x*m+y-1]=c+1;
            }
        }
        int flg=0;
        for(int k=3;k<=n+m-1;k++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                int j=k-i;
                if(j>m)continue;
                if(j<=0)break;
                //cout<<i<<" "<<j<<" "<<vis[i*m+j]+vis2[i*m+j]<<endl;
                if(vis[i*m+j]+vis2[i*m+j]==n+m)cnt++;
            }
            if(cnt==1){
                flg=1;
                break;
            }
        }
        if(flg)cout<<1<<endl;
        else cout<<2<<endl;
    }
}