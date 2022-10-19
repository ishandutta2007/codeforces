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
const int M=1111;
int n,p[M],a[M][M];
int main(){
	n=read();
	F(i,1,n) p[i]=read();
	F(i,1,n){
		int px=i,py=i;
		F(T,1,p[i]){
			a[px][py]=p[i];
			if (py>1 && !a[px][py-1]) py--;
			else px++;	
		}
	}
	F(i,1,n){
		F(j,1,i){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/