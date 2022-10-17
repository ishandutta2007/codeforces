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
int n,m,a[M],sf[M],k;
void work(){
	n=read(); k=read(); m=read();
	F(i,1,n) a[i]=1,sf[i]=0;
	F(i,1,m){
		int x=read();
		a[x]=0;
		sf[x]=1;
	}
	if ((n-m)%(k-1)!=0){
		puts("NO");
		return ;
	}
	F(i,1,n) a[i]+=a[i-1];
	int cnt=0; 
	F(i,1,n){
		if (sf[i]){
			if (a[i]>=(k-1)/2 && a[n]-a[i]>=(k-1)/2){
				cnt++; 
			}
		}
	}
	if (cnt>0) puts("YES");
	else puts("NO");
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
*/