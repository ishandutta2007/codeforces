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
const int M=5050;
LL a[M],s[M],n;
void work(){
	ms(a,0); ms(s,0);
	n=read();
	LL ans=0; 
	F(i,1,n){
		a[i]=read();
		s[i]+=s[i-1];
//		cout<<s[i]<<" "<<a[i]<<"\n";
		int len=min(s[i],a[i]-1);
		if (i+a[i]+1-len<=n) s[i+a[i]+1-len]++; 
		if (i+a[i]+1<=n) s[i+a[i]+1]--;
//		cout<<i+a[i]+1-len<<" "<<i+a[i]<<"  +1\n";
		int t1=s[i]-len;
		s[i+1]+=t1; s[i+2]-=t1;
//		cout<<t1<<"  nmd \n";
		if (a[i]-s[i]>=2){
			int tim=a[i]-s[i]-1;
			s[i+2]++; 
			if (i+2+tim<=n) s[i+2+tim]--;
			ans+=tim;
		}
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
10
6
1 2 2 2 2 3
*/