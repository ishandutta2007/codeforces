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
bool b[M]; 
int main(){
	int T=read();
	while (T--){
		int n=read(),k=read();
		vector<int> p; 
		F(i,1,n) {
			a[i]=read();
			if (a[i]==k) p.pb(i);
			b[i]=(a[i]>=k);
		}
		if (!p.size()){
			puts("no");
			continue;
		}
		if (n==1){
			puts("yes");
			continue;
		}
		int mid=3;
		F(i,1,n){
			if (b[i]){
				if (i+1<=n && b[i+1]) mid=1;
				if (i+2<=n && b[i+2]) mid=2;
			}
		}
		if (mid<=2){
			puts("yes");
		}
		else puts("no");
		
	}
	return 0;
}