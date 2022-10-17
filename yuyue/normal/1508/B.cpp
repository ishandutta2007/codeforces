#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n,a[M];
LL k;
LL pw(int x){
	if (x<=0) return 1;
	if (x>=61) return 2e18;
	return (1ll<<x);
}
void work(){
	n=read(); k=read();
	if (n<=61 && pw(n-1)<k){
		cout<<"-1\n";
		return ;
	}
	int lst=1;
	LL tmp=0;
	F(i,1,n){
		if (tmp+pw(n-i-1)>=k){
			DF(j,i,lst){
				cout<<j<<" ";
			}
			k-=tmp; tmp=0;
			lst=i+1;
		}
		else tmp+=pw(n-i-1);
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