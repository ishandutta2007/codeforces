#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,q,M,a[N],ia[N<<1],ad[N<<2],mn[N<<2],su[N<<2],p,x,i;
set<int>s;
inline void upd(int i){
	int L=i<<1,R=i<<1|1;
	if(mn[L]>mn[R])swap(L,R);su[i]=su[L];mn[i]=mn[L]+ad[i];
	if(mn[L]==mn[R])su[i]+=su[R];
}
inline void mdy(int l,int r,int v){
	if(l>r)swap(l,r);else v*=2;l+=M-1;r+=M;
	for(;l^r^1;upd(l>>=1),upd(r>>=1)){if(!(l&1))ad[l^1]+=v,mn[l^1]+=v;if(r&1)ad[r^1]+=v,mn[r^1]+=v;}
	for(;l>>=1;upd(l));
}
int main(){
	scanf("%d%d",&n,&q);for(i=1;i<=n;++i)scanf("%d",a+i),ia[a[i]]=i,s.insert(a[i]);
	for(M=1;M<n+2;M<<=1);for(i=M;i<M<<1;++i)su[i]=1,mn[i]=N;for(i=1;i<n;++i)mn[i+M]=0;for(i=M-1;i;--i)upd(i);
	for(auto it=s.begin(),it2=it;++it2!=s.end();++it)mdy(ia[*it],ia[*it2],1);
	for(;q--;){
		scanf("%d%d",&p,&x);
		auto it=s.find(a[p]),it2=it;int u=0,v=0;
		if(it!=s.begin())it2=it,u=ia[*--it2];
		if(it!=--s.end())it2=it,v=ia[*++it2];
		if(u)mdy(u,p,-1);if(v)mdy(p,v,-1);if(u && v)mdy(u,v,1);
		u=v=0;s.erase(it);it=s.insert(a[p]=x).first;ia[x]=p;
		if(it!=s.begin())it2=it,u=ia[*--it2];
		if(it!=--s.end())it2=it,v=ia[*++it2];
		if(u)mdy(u,p,1);if(v)mdy(p,v,1);if(u && v)mdy(u,v,-1);
		printf("%d\n",1+(mn[1]==1?su[1]:0));
	}
	return 0;
}