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
const int M=1e7+10,mod=1e9+7,N=5e5+10;
bool p[M];
int P[M/10],cnt;
short miu[M];
int pw[M];
void sieve(int n){
	miu[1]=1;
	F(i,2,n){
		if (!p[i]){
			miu[i]=-1;
			P[++cnt]=i;
		}
		for (int j=1;j<=cnt && P[j]*i<=n;j++){
			int o=P[j]*i;
			p[o]=1;
			if (i%P[j]==0){
				miu[o]=0;
				break;	
			}		
			miu[o]=-miu[i];
		}
	}
}
int a[M],n,m,b[M];
int d[M];
void red(int &x){
	x=(x>=mod ? x-mod : x);
}
int main(){
//	freopen("1.in","r",stdin);
	n=read();
	F(i,1,n){
		int x=read();
		a[x]++;
		m=max(m,x);
	}
	sieve(m);
	F(i,1,cnt){
		for (int j=m/P[i],o=j*P[i];j>=1;j--,o-=P[i]){
			a[j]+=a[o];
		}
	}
	pw[0]=1; 
	F(i,1,n) pw[i]=pw[i-1]*2%mod;
	F(i,1,m) b[i]=a[i]*miu[i],d[i]=pw[a[i]]-1;
	
	F(i,1,cnt){
		int lim=m/P[i];
		for (int j=1,o=P[i];j<=lim;j++,o+=P[i]){
			b[o]+=b[j];
			d[j]+=mod-d[o];
			d[j]=(d[j]>=mod ? d[j]-mod : d[j]);
		}
	}
	LL ans=0;
	F(i,2,m){
		ans=(ans+1ll*b[i]*d[i])%mod;
	}
	cout<<ans<<"\n";	
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
2
1 10000000
*/