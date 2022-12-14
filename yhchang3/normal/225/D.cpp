#include<bits/stdc++.h>
using namespace std;
int dp[225][1<<16];
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int tran[4]={2,3,0,1};
string s[15];
bool visit[15][15][1<<16];
int n,m,length,backx,backy,startbody,status;
struct snake{
    int x,y,body;
}start;
bool in(int x,int y){
    return  (x>=0&&x<n&&y>=0&&y<m);
}
bool collision(int x,int y,snake sn){
    int body=sn.body;
    int xx=sn.x;int yy=sn.y;
    for(int i=1;i<length-1;i++){
        xx+=dx[tran[body&3]];
        yy+=dy[tran[body&3]];
        body>>=2;
        if(x==xx&&y==yy)    return  true;
    }
    return false;
}
int BFS(){
    queue<pair<snake,int>>  Q;
    Q.push({start,0});
    visit[start.x][start.y][start.body]=1;
    while(!Q.empty()){
        snake nowsnake=Q.front().first;
        int nowstep=Q.front().second;
        if(s[nowsnake.x][nowsnake.y]=='@')  return nowstep;
        Q.pop();
        for(int i=0;i<4;i++){
            int nextx=nowsnake.x+dx[i];
            int nexty=nowsnake.y+dy[i];
            if(in(nextx,nexty)&&s[nextx][nexty]!='#'&&!collision(nextx,nexty,nowsnake)){
                snake nextsnake;
                nextsnake.x=nextx;
                nextsnake.y=nexty;
                nextsnake.body=((nowsnake.body<<2)&startbody)|i;
                if(!visit[nextsnake.x][nextsnake.y][nextsnake.body]){
                    visit[nextsnake.x][nextsnake.y][nextsnake.body]=true;
                    Q.push({nextsnake,nowstep+1});
                }
            }
        }
    }
    return -1;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    length=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]!='#'&&s[i][j]!='@'&&s[i][j]!='.'){
                if(s[i][j]=='1'){
                    start.x=i;
                    start.y=j;
                }
                if(s[i][j]-'0'>length){
                    backx=i;
                    backy=j;
                    length=s[i][j]-'0';
                }
            }
        }
    }
    startbody=(1<<((length-1)*2))-1;
    status=0;
    while(s[backx][backy]!='1'){
        for(int i=0;i<4;i++){
            int newbackx=backx+dx[i];
            int newbacky=backy+dy[i];
            if(in(newbackx,newbacky)&&s[newbackx][newbacky]+1==s[backx][backy]){
                status<<=2;
                status|=i;
                backx=newbackx;
                backy=newbacky;
                break;
            }
        }
    }
    start.body=status;
    cout<<BFS()<<endl;
}