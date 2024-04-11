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
const int M=1111,inf=1e9+10;
int n,m,k;
int a[M][M],b[M][M],f[M][M][12];
int main(){
	n=read(); m=read(); k=read();
	F(i,1,n){
		F(j,1,m-1){
			a[i][j]=read();
		}
	}
	F(i,1,n-1){
		F(j,1,m){
			b[i][j]=read();
		}
	}
	if (k&1){
		F(i,1,n){
			F(j,1,m){
				cout<<"-1 ";
			}
			cout<<"\n";
		}
		return 0;
	}
	k/=2;
	F(o,1,k){
		F(i,1,n){
			F(j,1,m){
				f[i][j][o]=inf;
				if (i>1) f[i][j][o]=min(f[i][j][o],f[i-1][j][o-1]+b[i-1][j]);
				if (i<n) f[i][j][o]=min(f[i][j][o],f[i+1][j][o-1]+b[i][j]);
				if (j>1) f[i][j][o]=min(f[i][j][o],f[i][j-1][o-1]+a[i][j-1]);
				if (j<m) f[i][j][o]=min(f[i][j][o],f[i][j+1][o-1]+a[i][j]);
			}	
		}
	}
	F(i,1,n){
		F(j,1,m){
			cout<<f[i][j][k]*2<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/