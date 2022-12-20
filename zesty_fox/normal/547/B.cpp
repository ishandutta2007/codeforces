#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=200010;
int n,f[N],siz[N],vis[N],ans[N];
pii h[N];
int find(int x){
    return x==f[x]?f[x]:f[x]=find(f[x]);
}

void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    f[y]=x;siz[x]+=siz[y];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i].first),h[i].second=i,f[i]=i,siz[i]=1;
    sort(h+1,h+n+1);int k=1;
    for(int i=n;i>=1;i--){
        int x=h[i].first,id=h[i].second;
        vis[id]=1;
        if(vis[id-1]) merge(id,id-1);
        if(vis[id+1]) merge(id,id+1);
        int tmp=siz[find(id)];
        for(;k<=tmp;k++) ans[k]=x;
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}