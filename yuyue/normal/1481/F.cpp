#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n,m;
vector<int> v[M],t[M],h[M];
int dep[M];
int a[M],mxd;
bool nlef[M];
void dfs(int x,int fa){
	nlef[fa]=1;
	dep[x]=dep[fa]+1;
	a[dep[x]]++; h[dep[x]].pb(x);
	mxd=max(mxd,dep[x]);
	for (int y:v[x]){
		dfs(y,x);
	}
}
int bl[M],val[M];
bool tg[M];
int tot;
bitset<100005> f[888];
char ans[M];
int main(){
	n=read(); m=read();
	F(i,2,n){
		int x=read();
		v[x].pb(i);
	}
	dfs(1,0);
	F(i,1,mxd) t[a[i]].pb(i);
	F(i,1,n){
		int num=1,ps=0;
		if (!t[i].size()) continue;
		while (1){
			tot++; int o=1;
			while (ps<=SZ(t[i]) && o<=num) val[tot]+=i,bl[t[i][ps]]=tot,ps++,o++;
			num<<=1;
			if (ps>SZ(t[i])) break;
		}
	}
	f[0][0]=1;
	F(i,1,tot){
		f[i]=f[i-1];
		f[i]|=(f[i-1]<<val[i]);
	}
	if (f[tot][m]){
		cout<<mxd<<"\n";
		int now=m;
		DF(i,tot,1){
			if (f[i-1][now]) continue;
			now-=val[i];
			tg[i]=1;
		}
		F(i,1,n) if (tg[bl[dep[i]]]) cout<<'a';
		else cout<<'b';
		return 0;
	}
	else{
		cout<<mxd+1<<"\n";
		int nm[2]; nm[0]=m; nm[1]=n-m;
		F(i,1,mxd){
			int nl=0;
			for (int x:h[i]){
				nl+=(nlef[x]);
			}
			int d=(nl<=nm[1]);
			nm[d]-=nl;
			for (int x:h[i]){
				if (nlef[x]) ans[x]=d+'a';
				else{
					if (nm[d]) ans[x]=d+'a',nm[d]--;
					else ans[x]=(d^1)+'a',nm[d^1]--;
				}
			}
		}
		F(i,1,n) cout<<ans[i];
	}
	return 0;
}