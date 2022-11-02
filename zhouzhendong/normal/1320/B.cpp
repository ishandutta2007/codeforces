#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define outtime() cerr<<"User Time = "<<(double)clock()/CLOCKS_PER_SEC<<endl
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
/*
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
*/
const int N=200005;
int n,m,s,t;
vector <int> e[N],r[N];
int dis[N],cnt[N];
int p[N],k,vis[N];
void dijkstra(){
	For(i,1,n)
		dis[i]=1e9,cnt[i]=0;
	dis[t]=0,cnt[t]=1;
	queue <int> q;
	vis[t]=1;
	q.push(t);
	while (!q.empty()){
		int x=q.front();q.pop();
		for (auto y : r[x]){
			if (!vis[y]){
				dis[y]=dis[x]+1,cnt[y]=0;
				q.push(y);
				vis[y]=1;
			}
			if (dis[y]==dis[x]+1)
				cnt[y]=min(cnt[y]+1,2);
		}
	}
}
int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y),r[y].pb(x);
	}
	k=read();
	For(i,1,k)
		p[i]=read();
	s=p[1],t=p[k];
	dijkstra();
//	outarr(dis,1,n);outarr(cnt,1,n);
	int minans=0,maxans=0;
	For(i,1,k-1){
		if (dis[p[i]]-1!=dis[p[i+1]])
			minans++,maxans++;
		else if (cnt[p[i]]>1)
			maxans++;
	}
	cout<<minans<<" "<<maxans<<endl;
	return 0;
}