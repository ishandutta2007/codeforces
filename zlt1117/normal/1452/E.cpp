#include<bits/stdc++.h>
#define re register
#define ll long long
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
#define FOR(i,a,b) for(re int i=(a),i##i=(b);i<=i##i;++i)
#define ROF(i,a,b) for(re int i=(a),i##i=(b);i>=i##i;--i)
#define gc getchar()
using namespace std;
const int N=4100;
LL read(){
	ll p=0; bool w=0; char ch=gc;
	while(!isdigit(ch)) w=ch=='-'?1:0,ch=gc;
	while(isdigit(ch)) p=p*10+ch-'0',ch=gc;
	return w?-p:p;
}
int n,m,K,l[N],r[N],nw,ans,tg[N],ad[N];
I get(int l1,int r1,int l2,int r2){
//	if(l1>l2) swap(l1,l2),swap(r1,r2);
//	int as=0;
//	if(r1>=r2) as=r2-l2+1;
//	else as=max(0,r1-l2+1);
//	return as;
	return max(0,min(r1,r2)-max(l1,l2)+1);
}
int main(){
	n=read(),m=read(),K=read();
	FOR(i,1,m) l[i]=read(),r[i]=read();
	FOR(i,1,n-K+1){
		memset(tg,0,sizeof(tg));
		nw=0;
		FOR(j,1,m){
			int len=get(i,i+K-1,l[j],r[j]);
			nw+=len;
			if(len==r[j]-l[j]+1) continue;
			if(r[j]-l[j]+1>=K){
				int pos=0;
				pos=n+len+l[j]-K;
				tg[pos+1]+=1;
				pos=n+l[j];
				tg[pos+1]-=1;
				pos=n+r[j]-K+1;
				tg[pos+1]-=1;
				pos=n+r[j]-len+1;
				tg[pos+1]+=1;
			}
			else{
				int pos=0;
				pos=n+len-K+l[j];
				tg[pos+1]+=1;
				pos=n+r[j]-K+1;
				tg[pos+1]-=1;
				pos=n+l[j];
				tg[pos+1]-=1;
				pos=n+r[j]-len+1;
				tg[pos+1]+=1;
			}
			
		}
		int tmp=0,us=0;
		FOR(j,1,2*n-K+1){
			us+=tg[j];
			tmp+=us;
			if(j>n) ans=max(ans,nw+tmp);
		}
	}
	cout<<ans;
	
	return 0;
}