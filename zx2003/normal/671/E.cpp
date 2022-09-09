#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,k,i,j,w[N],g[N],M,st[N],tp,st2[N],tp2,ans;
ll s1[N],s2[N],t1[N*3],t2[N*3],tg[N*3],mx[N],mxx[N],vv[N],vvv[N];
inline ll ask1(int l,int r){
	ll ans=-(1ll<<60);
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){	
		if(!(l&1))ans=max(ans,t1[l^1]);
		if(r&1)ans=max(ans,t1[r^1]);
	}
	return ans;
}
inline void psh(int i,const ll&v){tg[i]+=v;t2[i]+=v;}
inline void upd(int i){t2[i]=min(t2[i<<1],t2[i<<1|1])+tg[i];}
inline void add(int l,int r,ll v){
	for(l+=M-1,r+=M+1;l^r^1;upd(l>>=1),upd(r>>=1)){
		if(!(l&1))psh(l^1,v);
		if(r&1)psh(r^1,v);
	}
	for(;l>>=1;upd(l));
}
ll sm;
inline int ask2(){
	int i=M;sm=0;
	for(;t2[i^1]>k;i>>=1);
	for(i^=1;i<M;)sm+=tg[i],i=i<<1|(t2[i<<1]+sm>k);
	sm+=t2[i];
	return i-M;
}
inline int ask3(int l,int r,ll v){
	static int A[99],B[99];int Axb=0,Bxb=0,i;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
		if(!(l&1))A[++Axb]=l^1;
		if(r&1)B[++Bxb]=r^1;
	}
	for(i=1;i<=Bxb;++i)if(v-t1[B[i]]<=k)break;
	if(i<=Bxb)i=B[i];else{for(i=Axb;i;--i)if(v-t1[A[i]]<=k)break;i=A[i];}
	for(;i<M;)i=i<<1|(v-t1[i<<1|1]<=k);
	return i-M;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;for(M=1;M<n+2;M<<=1);
	for(i=1;i<n;++i)cin>>w[i];for(i=1;i<=n;++i)cin>>g[i],s2[i]=s1[i-1]-w[i-1],s1[i]=s2[i]+g[i],t1[i+M]=s1[i];
	for(i=M-1;i;--i)t1[i]=max(t1[i<<1],t1[i<<1|1]);
	st[0]=n+1;
	for(i=n;i;--i){
		for(;tp && s2[i]<s2[st[tp]];--tp){
			if(tp>1)add(1,tp-1,-vv[tp]);
			if(st2[tp2]==tp)add(st2[tp2-1]+1,tp-1,-mx[tp]),add(tp,tp,-vvv[tp2]),--tp2;
				else add(tp,tp,mxx[tp]);
		}
		st[++tp]=i;
		if(tp>1)vv[tp]=s2[i]-s2[st[tp-1]],add(1,tp-1,vv[tp]);
		mx[tp]=max(mxx[tp]=ask1(i,st[tp-1]-1)-s2[i],vv[tp]+s1[st[tp-1]-1]-s2[i]);
		for(;tp2 && mx[st2[tp2]]<mx[tp];--tp2)add(st2[tp2-1]+1,st2[tp2]-1,-mx[st2[tp2]]),
			add(st2[tp2],st2[tp2],-mxx[st2[tp2]]),add(st2[tp2],st2[tp2],-vvv[tp2]);
		st2[++tp2]=tp;vvv[tp2]=0;add(st2[tp2-1]+1,tp-1,mx[tp]);
		if(tp2>1 && mx[tp]>mxx[st2[tp2-1]])
			add(st2[tp2-1],st2[tp2-1],-vvv[tp2-1]),
			add(st2[tp2-1],st2[tp2-1],vvv[tp2-1]=mx[tp]-mxx[st2[tp2-1]]);
		j=ask2();
		ans=max(ans,ask3(st[j],st[j-1]-1,sm+mxx[j]+s2[st[j]])-i+1);
	}
	cout<<ans<<endl;
	return 0;
}