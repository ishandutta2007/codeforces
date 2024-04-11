#include<bits/stdc++.h>
#define reg register
using namespace std;
typedef long long ll;
const int MN=1e5+5;
int to[MN<<1],nxt[MN<<1],h[MN],cnt;
inline void ins(int s,int t){
    to[++cnt]=t;nxt[cnt]=h[s];h[s]=cnt;
    to[++cnt]=s;nxt[cnt]=h[t];h[t]=cnt;
}
int n,Ans=1,deg[MN];
bool f[MN][2];
void dfs1(int st,int fa=0){
    if(!nxt[h[st]])f[st][0]=true;
    for(reg int i=h[st];i;i=nxt[i])
        if(to[i]!=fa){
            dfs1(to[i],st);
            if(f[to[i]][0]&&f[st][0])Ans=3;
            if(f[to[i]][1]&&f[st][1])Ans=3;
            f[st][0]|=f[to[i]][1];
            f[st][1]|=f[to[i]][0];
        }
}
void dfs2(int st,int fa=0){
    if(!nxt[h[st]]){
        if(st==1)deg[to[h[st]]]++;
        else{deg[fa]++;return;}
    }
    for(reg int i=h[st];i;i=nxt[i])
        if(to[i]!=fa)dfs2(to[i],st);
}
int main(){
    scanf("%d",&n);
    for(reg int i=1,s,t;i<n;i++)
        scanf("%d%d",&s,&t),ins(s,t);
    dfs1(1);printf("%d ",Ans);
    Ans=n-1;dfs2(1);
    for(reg int i=1;i<=n;i++)
        if(deg[i])Ans-=deg[i]-1;
    printf("%d\n",Ans);
    return 0;
}