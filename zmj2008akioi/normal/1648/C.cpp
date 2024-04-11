#include <cstdio>
const int harry=998244353,N=2e5,EXT=10;
int n,m,ans,inv,s[N+EXT],t[N+EXT],prd[N+EXT],bkt[N+EXT],invprd[N+EXT],segtrr[4*N+EXT];
inline int lc(int x){return x<<1;}
inline int rc(int x){return (x<<1)+1;}
inline int md(int x,int y){return (x+y)>>1;}
inline void pushup(int u){segtrr[u]=(segtrr[lc(u)]+segtrr[rc(u)])%harry;}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=(long long)nw*nw%harry)if(rm&pw)rm^=pw,rs=(long long)rs*nw%harry;
	return rs;
}
void modify(int l,int r,int u,int s,int d){
	if(l==r)segtrr[u]=d;
	else{
		if(md(l,r)>=s)modify(l,md(l,r),lc(u),s,d);
		else modify(md(l,r)+1,r,rc(u),s,d);
		pushup(u);
	}
}
int query(int l,int r,int u,int s,int t){
	if(s>t)return 0;
	if(l>=s&&r<=t)return segtrr[u];
	else{
		int res=0;
		if(md(l,r)>=s)res+=query(l,md(l,r),lc(u),s,t);
		if(md(l,r)+1<=t)res+=query(md(l,r)+1,r,rc(u),s,t);
		return res%harry;
	}
}
int main(){
	scanf("%d %d",&n,&m),inv=prd[0]=invprd[0]=1;
	for(register int i=1;i<=n;++i)scanf("%d",&s[i]),++bkt[s[i]];
	for(register int i=1;i<=m;++i)scanf("%d",&t[i]);
	for(register int i=1;i<=N;++i)prd[i]=(long long)prd[i-1]*i%harry;
	invprd[N]=qpow(prd[N],harry-2);
	for(register int i=N-1;i;--i)invprd[i]=(long long)invprd[i+1]*(i+1)%harry;
	for(register int i=1;i<=N;++i)inv=(long long)inv*invprd[bkt[i]]%harry,modify(1,N,1,i,bkt[i]);
	for(register int i=1;i<=m;++i){
		ans+=(long long)prd[n-i]*inv%harry*query(1,N,1,1,t[i]-1)%harry;
		if(!bkt[t[i]])break;
		if(i==n){
			if(n!=m)++ans;
			break;
		}
		inv=(long long)inv*bkt[t[i]]%harry,modify(1,N,1,t[i],--bkt[t[i]]),ans%=harry;
	}
	printf("%d",ans%harry);
	return 0;
}