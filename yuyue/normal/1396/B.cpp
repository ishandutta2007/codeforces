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
int a[M];
int main(){
	int T=read();
	while (T--){
		int n=read();
		int sum=0,mx=0;
		F(i,1,n){
			a[i]=read();
			sum+=a[i];
			mx=max(a[i],mx);
		}
		if (mx>sum-mx){
			puts("T");
		}
		else {
			if (sum&1){
				puts("T");
			}
			else puts("HL");
		}
	}
	return 0;
}