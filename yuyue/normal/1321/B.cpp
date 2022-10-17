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
int b[M],n;
LL t[M*10];
int main(){
	n=read();
	int mx=0;	
	LL ans=0;
	F(i,1,n) b[i]=read(),t[b[i]-i+M]+=b[i],mx=max(mx,b[i]-i+M);
	F(i,0,mx){
		ans=max(ans,t[i]);
	}
	cout<<ans<<"\n";
	return 0;
}