#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;i++)
#define DF(i,a,b) for (int i=a;i>=b;i--)
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define OO(x) fixed<<setprecision(x)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
int f[M];
LL sol(LL x){
	if (x<=10) return f[x];
	if (x&1) return x-sol(x-1);
	LL o=x/2;
	if (o&1) return x-sol(o);
	return x-sol(x-1);
}
int main(){
	int T=read();
	F(i,1,10){
		if (i&1) f[i]=i-f[i-1];
		else f[i]=i-min(f[i-1],f[i/2]);
	}
	F(i,1,T){
		LL x=read();
		cout<<sol(x)<<"\n";
	}
	return 0;
}