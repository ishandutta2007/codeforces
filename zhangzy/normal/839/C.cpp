#include<bits/stdc++.h>
#define db double
using namespace std;
int n;
db ans=0.0;
vector<int>r[233333];

void dfs(int x,int fa,db p,db dis){
    int y;
    for (int i=0;i<r[x].size();i++){
        y=r[x][i];
        if (y==fa) continue;
        dfs(y,x,p/(r[x].size()-1.0),dis+1.0);
    }
    if (r[x].size()==1){
        ans+=p*dis;
    }
}

int main(){
    scanf("%d",&n);
    int x,y;
    for (int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        r[x].push_back(y);
        r[y].push_back(x);
    }
    r[1].push_back(0);
    dfs(1,0,1.0,0.0);
    printf("%.10lf\n",ans);
}