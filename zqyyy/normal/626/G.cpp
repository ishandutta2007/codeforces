#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ld=double;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
const ld INF=1e18,eps=1e-10;
int n,t,Q,p[N],l[N],c[N];
inline ld f(int id,int c){
	if(!~c)return INF;
	if(c>=l[id])return 0;
	return p[id]*(1.*(c+1)/(c+l[id]+1)-1.*c/(c+l[id]));
}
inline ld g(int id){
	return 1.*p[id]*min(c[id],l[id])/(min(c[id],l[id])+l[id]);
}
struct D{
	ld val;int id,c;
	inline D(int id,int c):id(id),c(c){val=f(id,c);}
	inline bool operator <(const D &q) const {return fabs(val-q.val)<eps?id>q.id:val<q.val;}
};
multiset<D>s,S;
ld ans;
inline void add(){
	auto it=--s.end();
	ans+=it->val;int x=it->id;
	S.erase(D(x,c[x]-1)),S.insert(*it);
	s.erase(it),s.insert(D(x,++c[x]));
}
inline void del(){
	auto it=S.begin();
	ans-=it->val;int x=it->id;
	s.erase(D(x,c[x])),s.insert(*it);
	S.erase(it),S.insert(D(x,(--c[x])-1));
}
int main(){
	n=read(),t=read(),Q=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++)l[i]=read(),s.insert(D(i,0)),S.insert(D(i,-1));
	while(t--)add();
	while(Q--){
		int op=read(),x=read();
		s.erase(D(x,c[x])),S.erase(D(x,c[x]-1)),ans-=g(x);
		l[x]+=op==1?1:-1;
		s.insert(D(x,c[x])),S.insert(D(x,c[x]-1)),ans+=g(x);	
		while(s.rbegin()->val>S.begin()->val+eps)del(),add();
		printf("%.9lf\n",ans);
	}
	return 0;
}