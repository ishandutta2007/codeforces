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
int n,s,a[M];
void work(){
	n=read(); int x=read(),y=read();
	bool sm=1,cn=1;
	F(i,1,n){
		a[i]=read();
		sm&=(i==1 || a[i]==a[i-1]);
		cn&=(i==1 || abs(a[i]-a[i-1])<=1);
	}
	if (!cn){
		cout<<0<<"\n";
		return ;
	}
	if (sm){
		cout<<min(x+y,2*y)<<"\n";
		return ;
	}
	cout<<min(x,y)<<"\n";
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
	* calm down
*/