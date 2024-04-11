#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,m,a[N];
vec operator +(vec a,vec b){
	vec c;int i=0,j=0;
	while((i<(int)a.size() || j<(int)b.size()) && (int)c.size()<31)
		if(j>=(int)b.size() || (i<(int)a.size() && a[i]<b[j]))c.push_back(a[i++]);
		else c.push_back(b[j++]);	
	return c;
}
struct Segment_Tree{
	vec t[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	void build(int p,int l,int r){
		if(l==r){t[p]={a[l]};return;}
		int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r),t[p]=t[ls]+t[rs];	
	}
	vec query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];
		int mid=(l+r)>>1;
		if(y<=mid)return query(ls,l,mid,x,y);
		if(x>mid)return query(rs,mid+1,r,x,y);
		return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);	
	}
}T;
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read(),T.build(1,1,n);
	while(m--){
		int l=read(),r=read();
		vec t=T.query(1,1,n,l,r);
		int ans=1<<30;
		for(int i=0;i<(int)t.size();i++)
			for(int j=i+1;j<(int)t.size();j++)
				ans=min(ans,t[i]|t[j]);
		printf("%d\n",ans);
	}
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}