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
const int M=1e6+10;
vector<int> v[M];
int a[M],f[M];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
int ans[M],s[M],tp,tar,tot;
void dfs(int x,int fa){
	s[++tp]=x;
	if (x==tar){
		tot=tp;
		F(i,1,tp) ans[i]=s[i];
		return ;
	}
	for (int y:v[x]){
		if (y^fa) dfs(y,x);
	}
	tp--;
}
int n; 
void work(){
	n=read();
	F(i,1,n) v[i].clear(),f[i]=i;
	bool fl=0;
	F(i,1,n){
		a[i]=read();
		if (fl) continue;
		int x=n-i+1,y=x+a[i];
		
		int xx=Fd(x),yy=Fd(y);
		if (xx==yy){
			fl=1;
			tp=0;
			tar=y;
			dfs(x,0);
		}
		else{
			v[x].pb(y);
			v[y].pb(x);
			f[xx]=yy;
		}
	}
	cout<<tot<<"\n";
	F(i,1,tot){
		cout<<n-ans[i]+1<<" ";
	}
	cout<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}
/*
*/