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
int n,a[M],bl[M],p[M];
int main(){
	
	n=read();
	int d=0; 
	F(i,1,n) a[i]=read(),p[i]=i,d=__gcd(d,a[i]);
	const double Start=clock();
	if (d>1){
		puts("NO");
		return 0;
	}
	while(clock()-Start<CLOCKS_PER_SEC*0.45){
		random_shuffle(p+1,p+1+n);
		int d1=0,d2=0;
		F(i,1,n){
			int x=p[i];
//			cerr<<a[x]<<" ";
			int now=__gcd(d1,a[x]);
			if(now^d1){
				d1=now;
				bl[x]=1;
			}
			else{
				d2=__gcd(d2,a[x]);
				bl[x]=2;
			}
		}
		if(d1==1 && d2==1){
			puts("YES");
			for(int i=1;i<=n;i++) cout<<bl[i]<<" ";
			return 0;
		}
	}
	puts("NO");
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/