#include<bits/stdc++.h>
using namespace std;

namespace dp{
	struct R{
		int to,nex;
	}r[2002000];
	int hea[1001000],cnt,n,f[1001000][2],used[1001000];
	
	void RE(){
		for (int i=1;i<=n;i++) hea[i]=0;
		cnt=1;
	}
	void A(int u,int v){
		u--;v--; if (!u||!v) return;
		r[++cnt]=(R){v,hea[u]};hea[u]=cnt;
		r[++cnt]=(R){u,hea[v]};hea[v]=cnt;
	}
	
	void dfs(int x){
		used[x]=1;
		f[x][0]=0;f[x][1]=1;
		int y;
		for (int i=hea[x];i>0;i=r[i].nex){
			y=r[i].to; if (used[y]) continue;
			dfs(y);
			f[x][0]+=max(f[y][0],f[y][1]);
			f[x][1]+=f[y][0];
		}
	}
	
	int realmain(){
		for (int i=1;i<=n;i++) used[i]=0;
		int ans=0;
		for (int i=1;i<=n;i++){
			if (!used[i]){
				dfs(i);
				ans+=max(f[i][0],f[i][1]);
			}
		}
		return ans;
	}
}

int ch[1001000][26],cnt,T,n,l,p,c;
char s[1001000];

void ddd(int p1,int p2){
	if (!p1||!p2) return;
	dp::A(p1,p2);
	for (int i=0;i<26;i++){
		ddd(ch[p1][i],ch[p2][i]);
	}
}

int main(){
	for (scanf("%d",&T);T--;){
		for (int i=1;i<=cnt;i++) memset(ch[i],0,sizeof ch[i]);
		cnt=1;
		for (scanf("%d",&n);n--;){
			scanf("%s",s);
			l=strlen(s);
			p=1;
			for (int i=0;i<l;i++){
				c=s[i]-'a';
				if (!ch[p][c]) ch[p][c]=++cnt;
				p=ch[p][c];
			}
		}
		dp::n=cnt-1; dp::RE();
		for (int i=0;i<26;i++){
			ddd(1,ch[1][i]);
		}
		printf("%d\n",dp::realmain());
	}
}