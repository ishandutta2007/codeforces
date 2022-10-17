#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=111,mod=1e9+7;
LL fast(LL x,LL p){
	LL ret=1;
	for(;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
bool c[M][M];
LL a[M][M],g[M][M];
int n;
LL det(){
	LL ret=1;
	F(i,1,n-1){
		ret=ret*a[i][i]%mod;
		if (!ret) return 0;
		F(j,i+1,n-1){
			LL inv=a[j][i]*fast(a[i][i],mod-2)%mod;
			F(k,i,n-1){
				a[j][k]=(a[j][k]-inv*a[i][k])%mod;
				if (a[j][k]<0) a[j][k]+=mod;
			}	
		}
	}
	return ret;
}
void out(){
	F(i,1,n){
		F(j,1,n){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\-----------------\n";
}
int main(){
	n=read();
	F(i,1,n-1){
		int x=read(),y=read();
		c[x][y]=c[y][x]=1;
	}
	F(k,1,n){
		F(i,1,n){
			F(j,1,n){
				if (i==j) continue;
				a[i][j]=c[i][j] ? -k : -1;
			}
		}
		F(i,1,n) {
			a[i][i]=0;
			F(j,1,n){
				if (i==j) continue;
				a[i][i]-=a[i][j];
			}
		}
		F(i,1,n){
			g[k][i]=fast(k,i-1);
		}	
//		out();
		g[k][n+1]=det();
//		cout<<g[k][n+1]<<"\n";
	}
	F(i,1,n){
		F(j,1,n){
			if (i==j) continue;
			LL inv=g[j][i]*fast(g[i][i],mod-2)%mod;
			F(k,i,n+1){
				g[j][k]=(g[j][k]-inv*g[i][k])%mod;
				if (g[j][k]<0) g[j][k]+=mod;
			}
		}
	}
	F(i,1,n){
		cout<<g[i][n+1]*fast(g[i][i],mod-2)%mod<<" ";
	}
	return 0;
}