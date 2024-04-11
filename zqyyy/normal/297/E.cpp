#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
struct Xian{
	int x,y,id;
}a[N];
inline bool cmp1(const Xian &p,const Xian &q){
	return p.x<q.x;
}
inline bool cmp2(const Xian &p,const Xian &q){
	return p.y<q.y;
}
int n,nn,l[N],r[N];
struct BIT{
	int c[N*2];
#define lowbit(x) ((x)&-(x))
	inline void clear(){
		for(int i=1;i<=nn;i++)c[i]=0;
	}
	inline void add(int p){
		for(;p<=nn;p+=lowbit(p))c[p]++;
	}
	inline int ask(int p){
		int res=0;
		for(;p;p-=lowbit(p))res+=c[p];
		return res;
	}
}t;
ll ans;
int main(){
	n=read(),nn=2*n;
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read(),a[i].id=i;
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		l[a[i].id]+=t.ask(a[i].x)+i-1-t.ask(a[i].y);
		t.add(a[i].y);
	}
	t.clear();
	for(int i=n;i;i--){
		r[a[i].id]+=t.ask(a[i].y);
		t.add(a[i].y);
	}
	sort(a+1,a+n+1,cmp2);
	t.clear();
	for(int i=n;i;i--){
		l[a[i].id]+=n-i-t.ask(a[i].y);
		t.add(a[i].x);
	}
	ans=1ll*n*(n-1)*(n-2)/6;
	ll sum=0;
	for(int i=1;i<=n;i++){
		ans-=1ll*l[i]*r[i];
		sum+=1ll*(l[i]+r[i])*(n-l[i]-r[i]-1);
	}
	return cout<<ans-sum/2,0;
}