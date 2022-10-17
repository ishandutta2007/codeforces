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
int n,m,a,b,s[M];
void work(){
	n=read(); m=read(); a=read(); b=read();
	if (a>b){
		a=n-a+1;
		b=n-b+1;
	}
	F(i,1,m){
		s[i]=read();
	}
	int tim=b-1,num=min(b-a-1,m);
	sort(s+1,s+m+1);
	int l=0,r=num,ans=0;
	while (l<=r){
		int mid=(l+r>>1);
		bool fl=0;
		F(i,1,mid){
			int st=mid-i+1;
			if (st+s[i]>tim) fl=1;
		}
		if (fl) r=mid-1;
		else l=mid+1,ans=mid;
	}
	cout<<ans<<"\n";
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