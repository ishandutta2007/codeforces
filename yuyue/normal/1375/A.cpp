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
const int M=555;
int a[M];
int main(){
	int T=read();
	while (T--){
		int n=read();
		F(i,1,n) a[i]=read(),a[i]=abs(a[i]); 
		
		for (int i=2;i<=n;i+=2){
			int o=(a[i]>=a[i-1])+(a[i+1]>=a[i]);
			if (o==0 || o==2) a[i]=-a[i];
		}
		F(i,1,n) cout<<a[i]<<" "; cout<<"\n"; 
	}
	return 0;
}