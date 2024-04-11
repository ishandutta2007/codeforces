#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define num ch-'0'
#define rep(i,k,n) for(int i=k;i<=n;++i)
using namespace std;
int n,m,s,cnt=0;
int head[1000005],dep[1000005],fa[1000005][64],lg[1000005];
struct node
{
    int to,nex;
}e[1000005];
inline void add(int x,int y)
{
    e[++cnt].nex=head[x];
    e[cnt].to=y;
    head[x]=cnt;
}
void init(int u,int f)
{
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for(int i=1;(1<<i)<=dep[u];++i)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].nex)
    {
        if(e[i].to==f) continue;
        init(e[i].to,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y])
        x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x!=y)
    {
        for(int i=lg[dep[x]];i>=0;--i)
            if(fa[x][i]!=fa[y][i])
            {
                x=fa[x][i];
                y=fa[y][i];
            }
        x=fa[x][0];
    }
    return x;
}

// int dep[1000010];
// void dfs(int u,int fa){
//     dep[u]=dep[fa]+1;
//     for(int i=head[u];i;i=e[i].nex){
//         if(e[i].to==fa) continue;
//         dfs(e[i].to,u);
//     }
// }

int dst(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        add(a,b);add(b,a);
    }
    init(1,0);
    rep(i,1,n) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    // dfs(1,0);

    int q;cin>>q;
    
    for(int i=1;i<=q;i++){

        int flg=0;
        int x,y,a,b,k;cin>>x>>y>>a>>b>>k;
        int dis=dst(a,b);
        if(k>=dis&&(k-dis)%2==0){
            flg=1;
        }

        // cout<<"now1:"<<dis<<endl;

        int dis1=dst(a,x);
        int dis2=dst(b,y);
        
        dis=dis1+dis2+1;
        if(k>=dis&&(k-dis)%2==0){
            flg=2;
        }

        // cout<<"now2:"<<dis<<endl;

        dis1=dst(a,y);
        dis2=dst(b,x);
        
        dis=dis1+dis2+1;
        if(k>=dis&&(k-dis)%2==0){
            flg=3;
        }  

        // cout<<"now3:"<<dis<<endl;

        // cout<<i<<" "<<flg<<endl;
        if(!flg)cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";

    }
    
}