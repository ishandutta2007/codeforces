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
const int M=5e5+10;
int n,a[M],m;
bool ban[M];
void work(){
	
	n=read(); m=read();
	F(i,1,n) ban[i]=0;
	F(i,1,m){
		int x=read(),y=read(),z=read(); 
		ban[y]=1;
	}
	F(i,1,n){
		if (!ban[i]){
			F(x,1,n){
				if (x^i){
					cout<<x<<" "<<i<<"\n";
				}
			}
			return ;
		}
	}
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