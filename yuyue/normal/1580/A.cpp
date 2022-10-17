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
const int M=444;
char a[M][M];
bool b[M][M];
int s[M][M],h[M][M];
int n,m;
void work(){
	n=read(); m=read();
	F(i,1,n){
		scanf("%s",a[i]+1);
		F(j,1,m) b[i][j]=a[i][j]-'0',s[i][j]=s[i-1][j]+b[i][j],h[i][j]=h[i][j-1]+(!b[i][j]);
	}
	int ans=1000000;
	F(i,1,n){
		F(ii,i+4,n){
			int mx=-1e9,sm=0,cs=0,ul=0;
			F(j,1,m){
				if (j>1) cs+=s[ii-1][j-1]-s[i][j-1];
				if (j>=4){
					sm+=s[ii-1][j-3]-s[i][j-3];
					mx=max(mx,sm+h[i][j-3]+h[ii][j-3]-(ii-i-1-s[ii-1][j-3]+s[i][j-3]));
//					cout<<cs<<" "<<sm<<"   hhh\n";
					ans=min(cs-mx+h[i][j-1]+h[ii][j-1]+(ii-i-1-s[ii-1][j]+s[i][j]),ans);
				}
			}
//			int ret=0;
//			F(k,i+1,i+3) ret+=(!b[k][j])+(!b[k][j+3]);
//			F(l,j+1,j+2) ret+=(!b[i][l])+(!b[i+4][l]);
//			F(k,i+1,i+3){
//				F(l,j+1,j+2){
//					ret+=b[k][l];
//				}
//			}
////			if (ret==4){
////				cout<<i<<" "<<j<<"   ??\n";
////			}
//			ans=min(ans,ret); 
		}
	}
	cout<<ans<<"\n";
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
*/