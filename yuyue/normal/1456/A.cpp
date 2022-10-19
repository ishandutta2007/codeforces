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
const int M=2e5+6;
int a[M],m,f[M],n,p,k;
char ch[M];
void work(){
	n=read(); p=read(); k=read(); 
	scanf("%s",ch+1);
	int x=read(),y=read();
	m=0;
	LL ans=1e18;
	F(i,1,n+k) f[i]=0;
	DF(i,n,1){
		if (ch[i]=='0'){
			f[i]=f[i+k]+1;
		}
		else{
			f[i]=f[i+k];
		}
		if (i>=p){
			ans=min(ans,1ll*(i-p)*y+1ll*f[i]*x);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}