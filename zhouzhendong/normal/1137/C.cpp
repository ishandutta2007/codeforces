#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=100005,D=55,INF=1e9;
int n,m,d;
vector <int> e[N],r[N];
int tag[N][D],dp[N][D],vis[N][D],ans[N][D],sid[N];
int dfn[N],low[N],bh[N],st[N],inst[N],Vis[N],Time,top,tot;
void Tarjan_Prepare(){
    Time=top=tot=0;
    memset(bh,0,sizeof bh);
    memset(st,0,sizeof st);
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
    clr(Vis);
    memset(inst,0,sizeof inst);
}
void Tarjan(int x){
    dfn[x]=low[x]=++Time;
    inst[x]=Vis[x]=1;
    st[++top]=x;
    for (auto y : e[x])
        if (!Vis[y]){
            Tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (inst[y])
            low[x]=min(low[x],low[y]);
    if (dfn[x]==low[x]){
        tot++;
        bh[st[top]]=tot;
        inst[st[top]]=0;
        while (st[top--]!=x){
            bh[st[top]]=tot;
            inst[st[top]]=0;
        }
    }
}
void dfs(int x,int tg){
	if (sid[x])
		return;
	sid[x]=tg;
	for (auto y : r[x])
		dfs(y,tg);
}
void dfs2(int x,int t){
	if (vis[x][t])
		return;
	vis[x][t]=1;
	for (auto y : r[x])
		dfs2(y,(t+1)%d);
}
vector <int> ids[N];
int in[N];
int q[N],head,tail;
int main(){
	n=read(),m=read(),d=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y);
	}
	For(i,1,n)
		For(j,0,d-1)
			scanf("%1d",&tag[i][j]);
	Tarjan_Prepare();
	For(i,1,n)
		if (!Vis[i])
			Tarjan(i);
//	For(i,1,n)printf("%d\n",bh[i]);
	For(x,1,n)
		for (auto y : e[x])
			if (bh[x]==bh[y])
				r[x].pb(y);
	For(i,1,n)
		if (!sid[i]){
			dfs(i,i);
			dfs2(i,0);
		}
/*	For(i,1,n)printf("sid[%d] = %d, ",i,sid[i]);puts("");
	For(i,1,n){
		For(j,0,d-1)
			printf("%11d ",vis[i][j]);
		puts("");
	}puts("");*/
	For(i,1,n)
		ids[sid[i]].pb(i);
	For(i,1,n)
		if (sid[i]==i){
			For(j,0,d-1){
				ans[i][j]=0;
				for (auto x : ids[i]){
					int flag=0;
					For(k,0,d-1){
						if (vis[x][k]&&tag[x][(j+k)%d]){
							flag=1;
							break;
						}
					}
					ans[i][j]+=flag;
				}
			}
		}
/*	For(i,1,n){
		For(j,0,d-1)
			printf("%11d ",ans[i][j]);
		puts("");
	}puts("");*/
	For(i,1,n)
		for (auto j : e[i])	
			if (bh[i]!=bh[j])
				in[sid[j]]++;
	For(i,1,n)
		For(j,0,d-1)
			dp[i][j]=-INF;
	dp[1][0]=0;
	For(i,1,n)
		if (sid[i]==i&&!in[i])
			q[++tail]=i;
	while (head<tail){
		int x=q[++head];
//	outval(x);
/*	For(i,1,n){
		For(j,0,d-1)
			printf("%11d ",dp[i][j]);
		puts("");
	}puts("");*/
		if (sid[x]==x){
			int val[D];
			For(i,0,d-1){
				for (auto y : ids[x]){
					For(j,0,d-1)
						if (vis[y][j])
							dp[x][i]=max(dp[x][i],dp[y][(j+i)%d]);
				}
			}
			For(i,0,d-1)
				val[i]=dp[x][i]+ans[x][i];
			For(i,0,d-1){
				for (auto y : ids[x]){
					For(j,0,d-1)
						if (vis[y][j])
							dp[y][(j+i)%d]=max(dp[y][(j+i)%d],val[i]);
				}
			}
			for (auto y : ids[x])
				if (y!=x)
					q[++tail]=y;
		}
		For(i,0,d-1)
			for (auto y : e[x])
				if (bh[y]!=bh[x]){
					dp[y][(i+1)%d]=max(dp[y][(i+1)%d],dp[x][i]);
				}
		for (auto y : e[x])
			if (bh[y]!=bh[x])
				if (!--in[sid[y]]){
					q[++tail]=sid[y];
				}
	}
//	For(i,1,tail)printf("%d ",q[i]);puts("");
	int ans=0;
/*	For(i,1,n){
		For(j,0,d-1)
			printf("%11d ",dp[i][j]);
		puts("");
	}puts("");*/
	For(i,1,n)
		For(j,0,d-1)
			ans=max(ans,dp[i][j]);
	cout<<ans<<endl;
	return 0;
}
/*
4 5 3
1 2
2 3 
2 4
4 3
1 4
110
101
001
010
*/