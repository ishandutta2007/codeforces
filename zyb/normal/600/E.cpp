#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int>a[N];map<int,int>S[N];
int F[N],id[N],c[N],n,i,x,y;
long long G[N],ans[N];
void work(int x,int y,int color){
    if (y>F[x]) F[x]=y,G[x]=0;
    if (y==F[x]) G[x]+=color;
}
void Union(int &x,int y){
    if (S[x].size()<S[y].size()) swap(x,y);
    for (map<int,int>::iterator it=S[y].begin();it!=S[y].end();it++)
        work(x,S[x][it->first]+=it->second,it->first);
}
void DFS(int x,int fa){
    id[x]=x;S[x][c[x]]=1;
    F[x]=1;G[x]=c[x];
    for (int i=0,y;i<a[x].size();i++)
        if ((y=a[x][i])!=fa)
            DFS(y,x),Union(id[x],id[y]);
    ans[x]=G[id[x]];
}
int main(){
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for (i=1;i<n;i++)
        scanf("%d%d",&x,&y),
        a[x].push_back(y),
        a[y].push_back(x);
    DFS(1,0);
    for (i=1;i<=n;i++)
        printf("%I64d ",ans[i]);
}