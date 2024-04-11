#include <bits/stdc++.h>
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define fi first
#define se second
#define pb push_back
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
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
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
}
const int N=200005;
int n,m,x;
int a[N],b[N],alim[N],blim[N];
void get_lim(int n,int *a,int *alim){
	For(i,1,n)
		a[i]=read(),alim[i]=x;
	vector <pii> st={mp(0,0)};
	#define top st.back()
	For(i,1,n){
		pii t=mp(i,a[i]);
		while (a[i]<a[top.fi]){
			ckmin(alim[top.fi],t.se);
			ckmax(t.se,top.se);
			st.pop_back();
		}
		if (st.size()>1)
			ckmin(alim[i],t.se);
		st.pb(t);
	}
}
int _c0[N],_c1[N];
void add(int *c,int x){
	for (;x<N;x+=x&-x)
		c[x]++;
}
int ask(int *c,int x){
	int ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
int main(){
	n=read(),m=read(),x=read();
	get_lim(n,a,alim);
	get_lim(m,b,blim);
	vector <pii> v;
	For(i,1,n)
		if (a[i]<alim[i])
			v.pb(mp(a[i],alim[i]));
	For(i,1,m)
		if (b[i]<blim[i])
			v.pb(mp(-b[i],blim[i]));
	sort(v.begin(),v.end(),[&](pii a,pii b){
		return a.se-abs(a.fi)>b.se-abs(b.fi);
	});
	LL ans=0;
	for (auto p : v){
		int v=abs(p.fi),lim=p.se;
		int *c0=_c0,*c1=_c1;
		if (p.fi<0)
			swap(c0,c1);
		ans+=ask(c1,x-v)-ask(c1,x-lim);
		add(c0,v);
	}
	cout<<ans<<endl;
	return 0;
}