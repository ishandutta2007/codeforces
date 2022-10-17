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
int n,k;
LL a[M],b[M],c[M],s[M],A[M];
int main(){
	n=read(); k=read();
	F(i,2,n){
		cout<<"and "<<1<<" "<<i<<endl;
		a[i]=read();
		cout<<"or "<<1<<" "<<i<<endl;
		b[i]=read();
		c[i]=b[i]-a[i];
		s[i]=b[i]+a[i];
	}
	cout<<"and "<<2<<" "<<3<<endl;
	LL x=read();
	cout<<"or "<<2<<" "<<3<<endl;
	x+=read();
	A[1]=(s[2]+s[3]-x)/2;
	F(i,2,n) A[i]=A[1]^c[i];
	sort(A+1,A+n+1);
	cout<<"finish "<<A[k]<<endl;
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/