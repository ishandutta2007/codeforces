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
const int M=2e5+10;
int a[M],w[M]; 
int main(){
	int T=read(); 
	while (T--){
		int n=read(),k=read();
		F(i,1,n) a[i]=read(); 
		F(i,1,k) w[i]=read(); 
		sort(w+1,w+k+1); sort(a+1,a+n+1);
		int pl=1,pr=n; 
		LL ans=0;
		F(i,1,k){
			if (w[i]==1) ans+=2*a[pr],pr--; 
			else break;
		}
		DF(i,k,1){
			if (w[i]==1) break;
			ans+=a[pl]+a[pr]; 
			pl+=w[i]-1; pr--;
		}
		cout<<ans<<"\n";
 	}
	return 0;
}