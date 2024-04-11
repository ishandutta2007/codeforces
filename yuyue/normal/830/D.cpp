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
const int M=404,mod=1e9+7;
LL f[M][M];
int n;
int main(){
	n=read();
	f[1][1]=1; f[1][0]=1;
	F(i,2,n){
		F(j,0,n){
			F(k,0,n-j){
				LL tmp=f[i-1][j]*f[i-1][k]%mod;
				f[i][j+k]=(f[i][j+k]+tmp*(1+2*(j+k)))%mod;
				if (j+k>=1) f[i][j+k-1]=(f[i][j+k-1]+(2*j*k+j*(j-1)+k*(k-1))*tmp)%mod;
				f[i][j+k+1]=(f[i][j+k+1]+tmp)%mod;
			}
		}
	}
	cout<<f[n][1]<<"\n";
	return 0; 
}