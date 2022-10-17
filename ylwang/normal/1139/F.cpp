#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
inline ll read() {
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=1e5+5;
struct BIT {
	int N,c[MAXN<<1];
	inline int lowbit(int x) {
		return x&(-x);
	}
	void add(int p,int x) {
		for(;p<=N;p+=lowbit(p)) c[p]+=x;
	}
	int ask(int p) {
		int res=0;
		for(;p>0;p-=lowbit(p)) res+=c[p];
		return res;
	}
}T;
int n,m,p[MAXN],s[MAXN],b[MAXN],inc[MAXN],pref[MAXN],p1[MAXN],p2[MAXN],p3[MAXN<<1],ans[MAXN];
void lisanhua(int *p1,int *p2,int *p3) {
	vector<int> v;
	for(int i=1;i<=n;++i) v.pb(p1[i]);
	for(int i=1;i<=m;++i) v.pb(p2[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i) p3[i]=lower_bound(v.begin(),v.end(),p1[i])-v.begin()+1;
	for(int i=1;i<=m;++i) p3[i+n]=lower_bound(v.begin(),v.end(),p2[i])-v.begin()+1;
}
struct node {
	int x,y,z,typ,id;
}q[MAXN<<1],tmp[MAXN<<1];
bool cmp1(node a,node b) {
	return (a.x<b.x) || (a.x==b.x&&a.y<b.y) || (a.x==b.x&&a.y==b.y&&a.z<b.z) || (a.x==b.x&&a.y==b.y&&a.z==b.z&&a.typ>b.typ);
}
bool cmp2(node a,node b) {
	return a.y<=b.y;
}
void cdq(int l,int r) {
	if(l==r) return ;
	int mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	
	int pa=l,pb=mid+1,ct=0;
	while(pa<=mid && pb<=r) {
		if(cmp2(q[pa],q[pb])) {
			if(q[pa].typ==1) T.add(q[pa].z,1);
			tmp[++ct]=q[pa++];
		} else {
			if(q[pb].typ==0) ans[q[pb].id]+=T.ask(q[pb].z);
			tmp[++ct]=q[pb++];
		}
	}
	while(pa<=mid) {
		if(q[pa].typ==1) T.add(q[pa].z,1);
		tmp[++ct]=q[pa++];
	}
	while(pb<=r) {
		if(q[pb].typ==0) ans[q[pb].id]+=T.ask(q[pb].z);
		tmp[++ct]=q[pb++];
	}
	
	for(int i=l;i<=mid;++i) {
		if(q[i].typ==1) T.add(q[i].z,-1);
	}
	for(int i=1;i<=ct;++i) q[l+i-1]=tmp[i];
}
int main() {
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);/*syn*/
	n=read();m=read(); T.N=n+m;
	for(int i=1;i<=n;++i) p[i]=read();
	for(int i=1;i<=n;++i) s[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	for(int i=1;i<=m;++i) inc[i]=read();
	for(int i=1;i<=m;++i) pref[i]=read();
	
	for(int i=1;i<=n;++i) p1[i]=b[i]+p[i];
	for(int i=1;i<=m;++i) p2[i]=inc[i]+pref[i];
	lisanhua(p1,p2,p3);
	for(int i=1;i<=n+m;++i) q[i].x=p3[i];
	
	for(int i=1;i<=n;++i) p1[i]=p[i]-b[i];
	for(int i=1;i<=m;++i) p2[i]=inc[i]-pref[i];
	lisanhua(p1,p2,p3);
	for(int i=1;i<=n+m;++i) q[i].y=p3[i];
	
	for(int i=1;i<=n;++i) p1[i]=-s[i];
	for(int i=1;i<=m;++i) p2[i]=-inc[i];
	lisanhua(p1,p2,p3);
	for(int i=1;i<=n+m;++i) q[i].z=p3[i];
	
	for(int i=1;i<=n;++i) q[i].typ=1,q[i].id=i;
	for(int i=1;i<=m;++i) q[i+n].id=i;
	
	sort(q+1,q+n+m+1,cmp1);
	cdq(1,n+m);
	
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	cout<<endl; 
	return 0;
}