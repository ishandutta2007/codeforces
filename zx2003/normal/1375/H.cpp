#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
const int N=4099;
int n,q,B,a[N],b[N],i,j,l,r,cnt,ass[N*20];
struct atom{
	V a;vector<V>b;int n;
	inline int getv(int l,int r)const{
		l=lower_bound(a.begin(),a.end(),l)-a.begin();
		r=upper_bound(a.begin(),a.end(),r)-a.begin()-1;
		return l<=r?b[l][r]:0;
	}
}v[N];
vector<pair<int,int>>ve;
inline int uni(int x,int y){
	int ret;
	if(x && y)ve.push_back({x,y}),ret=++cnt;
		else ret=x|y;
	return ret;
}
inline atom uni(const atom&a,const atom&b){
	atom c;c.n=a.n+b.n;c.a.resize(c.n);
	merge(a.a.begin(),a.a.end(),b.a.begin(),b.a.end(),c.a.begin());c.b.resize(c.n);
	for(int i=0;i<c.n;++i){
		c.b[i].resize(c.n);
		for(int j=i;j<c.n;++j){
			int x=a.getv(c.a[i],c.a[j]),y=b.getv(c.a[i],c.a[j]);
			c.b[i][j]=uni(x,y);
		}
	}
	return c;
}
atom build(int l,int r,int be){
	if(l==r){
		atom ret;ret.n=1;
		ret.a={b[be+l-1]};ret.b={{b[be+l-1]}};
		return ret;
	}
	int m=l+r>>1;return uni(build(l,m,be),build(m+1,r,be));
}
int main(){
	scanf("%d%d",&n,&q);cnt=n;
	for(i=1;i<=n;++i)scanf("%d",a+i),b[a[i]]=i;
	B=sqrt(q);B=min(B,n);
	for(i=j=1;i<=n;i+=B,++j)v[j]=build(1,min(i+B-1,n)-i+1,i);
	for(int k=1;k<=q;++k){
		scanf("%d%d",&l,&r);
		for(i=j=1;i<=n;i+=B,++j)ass[k]=uni(ass[k],v[j].getv(l,r));
	}
	printf("%d\n",cnt);for(auto u:ve)printf("%d %d\n",u.first,u.second);
	for(i=1;i<=q;++i)printf("%d%c",ass[i],i==q?'\n':' ');
}