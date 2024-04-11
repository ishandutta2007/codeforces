#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;
const int inf=0x7fffffff;
const double eps=1e-10;
const double pi=acos(-1.0);
//char buf[1<<15],*S=buf,*T=buf;
//char getch(){return S==T&&(T=(S=buf)+fread(buf,1,1<<15,stdin),S==T)?0:*S++;}
inline int read(){
    int x=0,f=1;char ch;ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=0;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
    if(f)return x;else return -x;
}
struct Trie{
    int son[2][200000*30+10],tot;
    void Insert(int a){
        int now=0,id;
        for(int i=30;i>=0;i--){
            id=(a>>i)&1;
            if(!son[id][now])son[id][now]=++tot;
            now=son[id][now];
        }
    }
    int Find(int r1,int r2,int b){
        if(b<0) return 0;
        int a1=-1,a2=-1;
        if(son[0][r1]&&son[0][r2]) a1=Find(son[0][r1],son[0][r2],b-1);
        if(son[1][r1]&&son[1][r2]) a2=Find(son[1][r1],son[1][r2],b-1);
        if(~a1&&~a2) return min(a1,a2);
        if(~a1) return a1;if(~a2) return a2;
        if(son[1][r1]&&son[0][r2]) a1=Find(son[1][r1],son[0][r2],b-1)+(1<<b);
        if(son[0][r1]&&son[1][r2]) a2=Find(son[0][r1],son[1][r2],b-1)+(1<<b);
        if(~a1&&~a2) return min(a1,a2);
        if(~a1) return a1;if(~a2) return a2;
    }
}T;
long long ans;
void dfs(int a,int b){
    if(b<0) return;
    if(T.son[0][a]&&T.son[1][a]) ans+=1ll*T.Find(T.son[0][a],T.son[1][a],b-1)+(1ll<<b);
    if(T.son[0][a]) dfs(T.son[0][a],b-1);
    if(T.son[1][a]) dfs(T.son[1][a],b-1);
}
int n,v;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)T.Insert(read());
    dfs(0,30);
    printf("%I64d\n",ans);
    return 0;
}