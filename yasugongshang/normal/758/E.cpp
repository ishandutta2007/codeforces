#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define int long long
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005;
map<int,int> M[N];
int flag,n,xx[N],yy[N],sum[N],ww[N],pp[N],www[N],ppp[N],de[N];
vector<pair<int,pair<int,int> > > v[N];
inline void dfs(int p,int fa){
	for(int i=0;i<v[p].size();i++)if(v[p][i].first!=fa){
		int vv=v[p][i].first;
		ww[vv]=v[p][i].second.first; pp[vv]=v[p][i].second.second;
		dfs(vv,p);
		sum[p]+=sum[vv];
	}
	if(pp[p]<sum[p])flag=1;
	int t=min(pp[p]-sum[p],ww[p]-1);
	pp[p]-=t+sum[p]; ww[p]-=t; de[p]=t;
	sum[p]+=ww[p];
}
inline int dfs(int p,int fa,int dq){
	int tt=min(dq,de[p]);
	de[p]-=tt; dq-=tt;
	int t=tt; pp[p]+=tt;
	//cout<<p<<" "<<dq<<" "<<pp[p]<<endl;
	for(int i=0;i<v[p].size();i++)if(v[p][i].first!=fa){
		int vv=v[p][i].first;
		int tt=dfs(vv,p,min(dq,pp[p]));
		//cout<<tt<<" "<<pp[p]<<" "<<dq<<" "<<de[vv]<<endl;
		dq-=tt; t+=tt; pp[p]-=tt;
	}
	M[fa][p]=de[p]; 
	return t;
}
signed main(){
	n=read(); ww[1]=1; pp[1]=4e18;
	for(int i=1;i<n;i++){
		int x=read(),y=read(),w=read(),p=read();
		v[x].push_back(mp(y,mp(w,p))); v[y].push_back(mp(x,mp(w,p)));
		xx[i]=x; yy[i]=y; www[i]=w; ppp[i]=p;
	}
	dfs(1,0); if(flag){
		puts("-1"); return 0;
	}
	dfs(1,0,4e18);
	writeln(n);
	for(int i=1;i<n;i++){
		write(xx[i]); putchar(' '); write(yy[i]); putchar(' ');
		int t;
		if(M[xx[i]].find(yy[i])!=M[xx[i]].end())t=M[xx[i]][yy[i]]; else t=M[yy[i]][xx[i]];
		write(www[i]-t); putchar(' '); writeln(ppp[i]-t);
	}
}