#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10,mod=998244353;
LL la[M],p[M],s[M];
LL d[M],t[M];
int ct,N;
#define lowbit(x) (x&-x)
void clr(){
	F(i,0,N) d[i]=0;
}
void add(int x,int o){
	for (;x<=N;x+=lowbit(x)) d[x]+=o;
}
int qry(int x){
	int ret=0;
	for (;x;x-=lowbit(x)) ret+=d[x];
	return ret;
}
LL va[M],vb[M];
LL solve(int *a,int n,LL d0,LL d1){
	F(i,1,n){
		la[i]=-la[i-1]+a[i];
		p[i]=p[i-1]+a[i];
	}
	s[n+1]=0;
	DF(i,n,1) s[i]=s[i+1]+a[i];
	ct=0;
	F(i,0,n) va[i]=p[i]-la[i]+d0,t[++ct]=va[i];
	F(i,0,n) vb[i]=s[i+1]-la[i]+d1,t[++ct]=vb[i];
	sort(t+1,t+ct+1);
	N=unique(t+1,t+ct+1)-t-1; 
	F(i,0,n){
		va[i]=lower_bound(t+1,t+N+1,va[i])-t;
		vb[i]=lower_bound(t+1,t+N+1,vb[i])-t;
	}
	clr();
	LL ans=0;
	int num=0;
	DF(i,n,0){
		if (i&1){
			num++;
			add(vb[i],1);
			ans+=num-qry(va[i]);
		}
	}
	clr(); num=0;
	DF(i,n,0){
		if (i%2==0){
			num++;
			add(vb[i],1);
			ans+=num-qry(va[i]);
		}
	}
	return ans;
}
int n,a[M];
void work(){
	n=read(); 
	F(i,1,n) a[i]=read();
	LL ans=0;
	ans=solve(a,n,0,0);
//	cout<<ans<<"  pans \n"; 
	if (n>=3){
		if (n>3){
			F(i,2,n-2){
				if (p[i]-s[i+1]>0) ans++;
			}				
//			cerr<<ans<<"  1\n";
		}
		ans=(ans+solve(a+3,n-3,(LL)-a[1]+a[2]+a[3],0));
		ans=(ans+solve(a,n-3,0,(LL)a[n-2]+a[n-1]-a[n]));
		if (n>=6){
			ans+=solve(a+3,n-6,(LL)-a[1]+a[2]+a[3],(LL)a[n-2]+a[n-1]-a[n]);
		}
	}
	cout<<ans%mod<<"\n";
//	cout<<ans<<" ?? \n";
//	F(i,2,n){
//		if (n==3 && i==2 || n==2) continue;
//		if (s[i+1]-p[i]+p[1]*2>0) ans++; 
//	}
//	DF(i,n-1,1){
//		if (n==3 && i==2 || n==2) continue;
//		if (s[i]-s[n]*2-p[i-1]>0) ans++;
//	}
//	cout<<ans%mod<<"\n";
}
int main(){
	int T=read();
	while (T--) work();	
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
PPPPP, CPPPP, PCPPP, CCPPP, PCPCP

1 PCCPP,

2 PPPPC ,CPPPC, PCPPC,

* PPPCC 


 PPPP, PCPC  , PCPP, , , , , .
 

PPPC
PCCP,PCCC

PPCC

3
6 4 2

PPP
PPC
PCP
*/