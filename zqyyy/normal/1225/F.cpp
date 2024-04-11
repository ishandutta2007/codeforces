#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,ans,dep[N],fa[N],len[N],son[N];
int tot,a[N];
vector<int>G[N];
void dfs(int x){
    a[++tot]=x;
    for(int y:G[x])if(y^son[x])dfs(y);
    if(son[x])dfs(son[x]);
}
int main(){
    n=read();
    for(int i=2;i<=n;i++){
	fa[i]=read()+1;
	G[fa[i]].push_back(i),dep[i]=dep[fa[i]]+1;
    }
    for(int i=n;i;i--)
	if(len[i]+1>=len[fa[i]])len[fa[i]]=len[i]+1,son[fa[i]]=i;
    dfs(1);
    for(int i=1;i<=n;i++)printf("%d ",a[i]-1);puts("");
    for(int i=2;i<=n;i++)ans+=dep[a[i-1]]-dep[fa[a[i]]];
    printf("%d\n",ans);
    for(int i=2;i<=n;i++)for(int j=dep[a[i-1]]-dep[fa[a[i]]];j>0;j--)printf("%d ",a[i]-1);
    return 0;
}