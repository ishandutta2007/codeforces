#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
// template<class T,class U>
struct pai{
    int first;
    int second;
};
int dis[42][1010][1010];
int mp[1010][1010];
int cvis[42];
vector<pai> col[43];
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
            col[mp[i][j]].push_back({i,j});
        }
    }
    queue<pai> q;
    for(int i=1;i<=k;i++){
        for(int i=1;i<=k;i++)cvis[i]=0;
        for(auto &it:col[i]){
            dis[i][it.first][it.second]=1;
            q.push(it);
        }
        cvis[i]=1;
        while(!q.empty()){
            auto tmp=q.front();q.pop();
            int x=tmp.first;
            int y=tmp.second;
            for(int o=0;o<4;o++){
                int nowx=x+dirx[o];
                int nowy=y+diry[o];
                if(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m&&!dis[i][nowx][nowy]){
                    dis[i][nowx][nowy]=dis[i][x][y]+1;
                    q.push({nowx,nowy});
                }
            }
            if(!cvis[mp[x][y]]){
                cvis[mp[x][y]]=1;
                for(auto &it:col[mp[x][y]]){
                    if(!dis[i][it.first][it.second]){
                        dis[i][it.first][it.second]=dis[i][x][y]+1;
                        q.push({it.first,it.second});
                    }
                }
            }
        }
    }
    // for(int o=1;o<=k;o++){
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             cout<<dis[i][j][o]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    int Q;scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        int ans=abs(a-c)+abs(b-d);
        for(int i=1;i<=k;i++){
            ans=min(ans,dis[i][a][b]+dis[i][c][d]-1);
        }
        printf("%d\n",ans);
    }
}