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
const int M=1e5+10;
int a[M],b[M],c[M],d[M];
int main(){
	int T=read();
	while(T--){
		int n=read(),k=read();
		F(i,1,n) a[i]=read();
		int num=0,ans=0;
		a[n+1]=-1;
		if (a[1]!=a[n] && k==1){
			cout<<"-1\n";
			continue;
		}
		F(i,1,n){
			if (a[i]!=a[i+1]) num++;
			if (num==k){
				ans++;
				num=1;
			}
//			cout<<ans<<" "<<num<<"\n";
		}
		if (ans && num>1) ans++;
		if (!ans) ans=1;
		cout<<ans<<"\n";
	}
	return 0;
}