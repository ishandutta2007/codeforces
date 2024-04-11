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
int n,X,a[111111];
void work(){
	
	n=read(); X=read();
	int sm=0;
	F(i,1,n) a[i]=read(),sm+=a[i];
	if (sm==X){
		puts("NO");
		return ;
	}
	puts("YES");
	sort(a+1,a+n+1);
	sm=0;
	F(i,1,n){
		if (sm+a[i]==X){
			swap(a[i],a[i+1]);
		}
		cout<<a[i]<<" ";
		sm+=a[i];
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