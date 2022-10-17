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
const int M=(1<<20)+10,N=1e5+10;
int n,m,b[M],lim;
char s[22][N];
void FWT(LL *f,int op){
	for (int p=2;p<=lim;p<<=1){
		int len=p>>1;
		for (int k=0;k<lim;k+=p){
			for (int l=k;l<k+len;l++){
				LL x=f[l],y=f[l+len];
				f[l]=x+y;
				f[l+len]=x-y;
				if (op==-1){
					assert(f[l]%2==0 && f[l+len]%2==0);
					f[l]>>=1;
					f[l+len]>>=1;
				}
			}
		}
	}
}
LL f[M],g[M];
int sz[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read();
	F(i,0,n-1){
		scanf("%s",s[i]+1);
		F(j,1,m){
			b[j]|=((s[i][j]=='1')<<i);
		}
	}
	F(i,1,m) g[b[i]]++;
	lim=(1<<n);
	F(i,0,lim-1){
		sz[i]=sz[i>>1]+(i&1);
	}
	F(i,0,lim-1){
		f[i]=min(sz[i],sz[i^(lim-1)]);
	}
	FWT(f,1); FWT(g,1);
	F(i,0,lim-1) f[i]=f[i]*g[i];
	FWT(f,-1);
	LL ans=f[0]; 
	F(i,0,lim-1){
		ans=min(ans,f[i]);
//		cout<<f[i]<<" "<<i<<"   gg\n";
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
*/