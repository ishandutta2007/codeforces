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
int n,a[M];
void work(){
	n=read();
	int sm=0;
	F(i,1,n) a[i]=read(),sm+=a[i];
	F(i,2,sm-1){
		if (sm%i==0){
			cout<<n<<"\n";
	F(i,1,n) cout<<i<<" ";
	cout<<"\n";
			return ;
		}
	}
	
	cout<<n-1<<"\n";
			bool fl=0 ;
			F(j,1,n){
				if (!fl && a[j]&1){
					fl=1;
				}	
				else cout<<j<<" ";
			}
			cout<<"\n";
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