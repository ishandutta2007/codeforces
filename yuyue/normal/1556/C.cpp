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
const int M=2020;
int n,c[M];
LL L[M][M],R[M][M];
void work(){
	n=read();
	F(i,1,n) c[i]=read();
	LL ans=0;
	F(le,1,n) 
	if (le&1)
	
	F(i,1,n){
			int j=i+le;
			if (j<=n){
				L[i][j]=R[i][j]=0;
				if (i&1){
					if (i+1==j){
						ans+=min(c[i],c[j]);
						(c[i]>c[j] ? R[i][j] : L[i][j])=abs(c[i]-c[j]);
					}
					else{
						LL dl=c[i]-L[i+1][j-1],dr=c[j]-R[i+1][j-1];
						ans+=max(0ll,min(dl,dr)+1);
						if (dl<=0) L[i][j]=-dl,dl=0;
						if (dr<=0) R[i][j]=-dr,dr=0;
						L[i][j]-=dl; if (L[i][j]<0) R[i][j]+=-L[i][j],L[i][j]=0;
						R[i][j]-=dr; if (R[i][j]<0) L[i][j]+=-R[i][j],R[i][j]=0;
					}
				}
				else{
					L[i][j]=L[i+1][j-1]+c[i];
					R[i][j]=R[i+1][j-1]+c[j];
				}
//				cout<<i<<" "<<j<<" "<<L[i][j]<<" "<<R[i][j]<<"    !!!!! \n" ; 
			}
	}
	cout<<ans<<"\n";
}
int main(){
	int T=1;
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