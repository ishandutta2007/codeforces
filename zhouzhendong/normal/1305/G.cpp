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
const int N=1<<18;
int n;
int v[N],fa[N];
int &f(int x){
	return fa[x]=fa[x]==x?x:f(fa[x]);
}
int check(){
	For(i,1,n)
		if (f(i)!=f(1))
			return 0;
	return 1;
}
void add(pii &a,int b){
	if (v[b]>v[a.fi]){
		if (f(b)==f(a.fi))
			a.fi=b;
		else
			a.se=a.fi,a.fi=b;
	}
	else if (v[b]>v[a.se]&&f(b)!=f(a.fi))
		a.se=b;
}
pii Max(pii a,pii b){
	add(a,b.fi);
	add(a,b.se);
	return a;
}
pii a[N],mx[N];
int main(){
	n=read();
	For(i,1,n)
		v[i]=read();
	++n;
	sort(v+1,v+n+1);
	For(i,1,n)
		fa[i]=i;
	LL ans=0;
	while (!check()){
		For(i,0,N-1)
			a[i]=mp(1,1);
		For(i,2,n)
			add(a[v[i]],i);
		For(i,0,17)
			For(j,0,N-1)
				if (~j>>i&1)
					a[j|1<<i]=Max(a[j|1<<i],a[j]);
		For(i,1,n)
			mx[i]=mp(-1,0);
		For(i,1,n){
			pii p=a[v[i]^(N-1)];
			int id=f(p.fi)!=f(i)?p.fi:p.se;
			mx[f(i)]=max(mx[f(i)],mp(v[i]+v[id],id));
		}
		vi id;
		For(i,1,n)
			if (f(i)==i)
				id.pb(i);
		for (auto i : id)
			if (f(i)!=f(mx[i].se)){
				f(i)=f(mx[i].se);
				ans+=mx[i].fi;
			}
	}
	For(i,1,n)
		ans-=v[i];
	cout<<ans<<endl;
	return 0;
}