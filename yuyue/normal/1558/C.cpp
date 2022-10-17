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
const int M=2050;
int n,a[M];
void work(){
	n=read();
	F(i,1,n) a[i]=read();
	F(i,1,n){
		if (a[i]%2!=i%2){
			puts("-1");
			return;
		}
	}
	vector<int> ans; 
	for (int x=n;x>=3;x-=2){
		int ps=0;
		F(i,1,x) if (a[i]==x) ps=i;
		ans.pb(ps);
		reverse(a+1,a+ps+1);
		
		F(i,1,x) if (a[i]==x-1) ps=i;
		ans.pb(ps-1);
		reverse(a+1,a+ps);
		
		ans.pb(x);
		reverse(a+1,a+x+1);
		
		F(i,1,x) if (a[i]==x) ps=i;
		ans.pb(ps);
		reverse(a+1,a+ps+1);
		
		ans.pb(x);
		reverse(a+1,a+x+1);
	}
//	F(i,1,n) cerr<<a[i]<<" "; cerr<<"  sort ?\n";
	cout<<ans.size()<<"\n";
	F(i,0,SZ(ans)) cout<<ans[i]<<" ";
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
1
7
3 6 1 4 5 2 7
*/