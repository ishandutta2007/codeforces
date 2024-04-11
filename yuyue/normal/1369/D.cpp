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
const int M=2e6+10,mod=1e9+7;
LL f[M][2],g[M]; 
int main(){
	g[3]=f[3][1]=4;
	F(i,4,M-5) {
		f[i][0]=(g[i-2]*2+g[i-1])%mod; 
		f[i][1]=(f[i-2][0]*2+f[i-1][0]+4)%mod; 
		g[i]=max(f[i][0],f[i][1]);
	}
	int T=read(); 
	while (T--){
		int x=read(); 
		cout<<g[x]<<"\n";
 	}
	return 0;
}