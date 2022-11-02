#include <bits/stdc++.h>
using namespace std;
const int maxd=505;
const int maxs=5005;
int g[maxd][10];
int f[maxd][maxs];
pair<int,int> pre[maxd][maxs];
int main(){
    int d,s;scanf("%d%d",&d,&s);
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for(int i=0;i<d;i++){
        for(int j=0;j<10;j++){
            g[(i*10+j)%d][j]=i;
        }
    }
    queue< pair<int,int> >q;
    q.push(make_pair(0,0));
    for(;q.size();){
        pair<int,int>h=q.front();
        q.pop();
        int x=h.first;
        int y=h.second;
        for(int i=0;i<10;i++){
            int _x=(x*10+i)%d;
            int _y=y+i;
            if(_y>s || ~f[_x][_y])continue;
            f[_x][_y]=f[x][y]+1;
            pre[_x][_y]=make_pair(x,y);
            q.push(make_pair(_x,_y));
        }
    }
    if(f[0][s]==-1)puts("-1");
    else{
        pair<int,int>now=make_pair(0,s);
        vector<int>ans;
        for(;f[now.first][now.second]>0;){
            int k=now.second-pre[now.first][now.second].second;
            ans.push_back(k);
            now=pre[now.first][now.second];
        }
        assert(ans.size()>0);
        reverse(ans.begin(),ans.end());
        for(int i:ans)printf("%d",i);
    }
    return 0;
}