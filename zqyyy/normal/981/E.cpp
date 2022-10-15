#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=10007;
typedef bitset<N> bt;
int n,Q;
#define ls (p<<1)
#define rs (p<<1|1)
vector<int>vec[N<<2];
void modify(int p,int l,int r,int x,int y,int v){
	if(x<=l && r<=y)return vec[p].push_back(v);
	int mid=(l+r)>>1;
	if(x<=mid)modify(ls,l,mid,x,y,v);
	if(y>mid)modify(rs,mid+1,r,x,y,v);
}
bt ans;
void divide(int p,int l,int r,bt f){
	for(int x:vec[p])f|=f<<x;
	if(l==r){ans|=f;return;}
	int mid=(l+r)>>1;
	divide(ls,l,mid,f),divide(rs,mid+1,r,f);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),Q=read();
	while(Q--){
		int l=read(),r=read(),v=read();
		modify(1,1,n,l,r,v);
	}
	bt tmp;tmp.set(0);
	divide(1,1,n,tmp);
	vector<int>res;
	for(int i=ans._Find_next(0);i<=n;i=ans._Find_next(i))
		res.push_back(i);
	printf("%lu\n",res.size());
	for(int x:res)printf("%d ",x);
	return 0;
}