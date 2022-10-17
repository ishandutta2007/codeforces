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
int dp[M],tg=0,mx=0,numx=0,semx=0;
int a[M],col[M],com[M],n;
int main(){
	n=read();
	F(i,1,n) a[i]=read();
	dp[0]=1; mx=1; numx=1;
	F(i,2,n){
		int now=0;
		if (col[a[i]]==mx){
			if (com[a[i]]==numx) {
				now=mx;	
			}
			else now=mx+1;
		}
		else{
			now=mx+1;
		}
		if (a[i]^a[i-1]) tg++,now--;
		if (now>mx){
			mx=now;
			numx=1;
		}
		else{
			if (now==mx){
				numx++;
			}
		}
		if (now>col[a[i-1]]){
			col[a[i-1]]=now;
			com[a[i-1]]=1;
		}
		else{
			if (now==col[a[i-1]]){
				com[a[i-1]]++;
			}
		}
	}
	cout<<tg+mx<<"\n"; 
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/