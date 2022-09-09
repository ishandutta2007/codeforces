#include<bits/stdc++.h>
using namespace std;
const int N=2005,M=17000;
int n,f[N][M],i,j,k,ans,nxt[N][M];
char l[N],r[N];
struct ACM{
	int ch[M][10],xb,mn[M],mx[M],val[M][N],islf[M],fail[M];
	void ins(char*c){
		int l=strlen(c),i,j,u=0;
		for(i=0;i<l && c[i]=='0';++i);
		for(;i<l;++i){
			for(j=u?0:1;j<10;++j)if(!ch[u][j])ch[u][j]=++xb;
			u=ch[u][c[i]-'0'];
		}
	}
	void getlf(){for(int i=0;i<=xb;++i)islf[i]=!ch[i][1],mn[i]=0,mx[i]=N;}
	void dfs(int x,int l,int tp){
		if(!x)return;
		if(tp)mx[x]=min(mx[x],l);else mn[x]=max(mn[x],l);
		for(int y:ch[x])dfs(y,l-1,tp);
	}
	void ini1(char*c,int tp){
		int l=strlen(c),u=0,i=0,j,x;
		for(i=0;i<l && c[i]=='0';++i);
		for(;i<l;++i){
			x=c[i]-'0';
			if(tp==0){for(j=x+1;j<=9;++j)dfs(ch[u][j],l-i-1,0);for(j=0;j<=x-1;++j)dfs(ch[u][j],l-i,0);}
				else {for(j=x+1;j<=9;++j)dfs(ch[u][j],l-i-2,1);for(j=0;j<=x-1;++j)dfs(ch[u][j],l-i-1,1);}
			u=ch[u][x];
			if(tp)mx[u]=min(mx[u],l-i-1);else mn[u]=max(mn[u],l-i-1);
		}
	}
	void ini2(){
		static int q[M];int t=0,w=1,u,i,j;q[1]=0;
		for(;t<w;){
			u=q[++t];
			for(i=0;i<10;++i)if(!ch[u][i])ch[u][i]=ch[fail[u]][i];
				else fail[ch[u][i]]=u?ch[fail[u]][i]:0,q[++w]=ch[u][i];
		}
		for(i=2;i<=w;++i){
			memcpy(val[q[i]],val[fail[q[i]]],n+1<<2);
			if(islf[q[i]])for(j=mn[q[i]];j<=mx[q[i]];++j)++val[q[i]][j];
				else if(mn[q[i]]==0 && 0<=mx[q[i]])++val[q[i]][0];
		}
		for(i=1;i<=xb;++i)for(j=1;j<=n;++j)val[i][j]+=val[i][j-1];
	}
}A;
int main(){
	scanf("%s%s%d",l,r,&n);
	A.ins(l);A.ins(r);A.getlf();A.ini1(l,0);A.ini1(r,1);A.ini2();
	for(i=0;i<=A.xb;++i)f[n][i]=A.val[i][0];
	for(i=n-1;i>=0;--i)for(j=0;j<=A.xb;++j){
		f[i][j]=-114514;
		for(k=0;k<10;++k){
			int nv=f[i+1][A.ch[j][k]];
			if(nv>f[i][j])f[i][j]=nv,nxt[i][j]=k;
		}
		f[i][j]+=A.val[j][n-i];
	}
	printf("%d\n",f[0][0]);
	int u=0;for(i=0;i<n;++i)putchar('0'+nxt[i][u]),u=A.ch[u][nxt[i][u]];puts("");
	return 0;
}