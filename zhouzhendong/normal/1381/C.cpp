#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (x>y)
		x=y;
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
const int N=100005;
int n,x,y,X,Y,sp;
int a[N],b[N];
vi p[N];
struct cmp{
	bool operator () (int x,int y){
		return p[x].size()<p[y].size();
	}
};
void check(){
	vi ca(n+2,0),cb(n+2,0);
	int xx=0,yy=0;
	For(i,1,n){
		xx+=a[i]==b[i];
		ca[a[i]]++;
		cb[b[i]]++;
	}
	For(i,1,n+1)
		yy+=min(ca[i],cb[i]);
	assert(xx==X&&yy==Y);
}
void solve(){
	n=read(),x=X=read(),y=Y=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n+1)
		p[i].clear();
	For(i,1,n)
		p[a[i]].pb(i);
	For(i,1,n+1)
		if (p[i].empty()){
			sp=i;
			break;
		}
	priority_queue <int,vi,cmp> q;
	For(i,1,n+1)
		q.push(i);
	while (x>0){
		int i=q.top();
		q.pop();
		assert(p[i].size()>0);
		int id=p[i].back();
		p[i].pop_back();
		b[id]=i;
		q.push(i);
		x--;
		y--;
	}
//	outarr(b,1,n);
	if (y<0)
		return (void)puts("NO");
	while (y>0){
		int i=q.top();
		q.pop();
		int j=q.top();
		q.pop();
		if (p[i].empty()||p[j].empty())
			return (void)puts("NO");
		if (y==3&&p[j].size()==1){
			int k=q.top();
			q.pop();
			if (p[i].empty()||p[j].empty()||p[k].empty())
				return (void)puts("NO");
			int idi=p[i].back();
			p[i].pop_back();
			int idj=p[j].back();
			p[j].pop_back();
			int idk=p[k].back();
			p[k].pop_back();
			b[idi]=j,b[idj]=k,b[idk]=i;
			y-=3;
			q.push(i),q.push(j),q.push(k);
			break;
		}
		int idi=p[i].back();
		p[i].pop_back();
		int idj=p[j].back();
		p[j].pop_back();
		b[idi]=j;
		if (y>=2){
			b[idj]=i;
			y-=2;
		}
		else {
			b[idj]=sp;
			y-=1;
		}
		q.push(i);
		q.push(j);
//		outarr(b,1,n);
	}
	For(i,1,n+1)
		while (!p[i].empty()){
			b[p[i].back()]=sp;
			p[i].pop_back();
		}
//	outarr(a,1,n);outarr(b,1,n);
	puts("YES");
	For(i,1,n)
		printf("%d ",b[i]);
	puts("");
	check();
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}