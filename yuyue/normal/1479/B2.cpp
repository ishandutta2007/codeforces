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
int dp[M],tg=0,mi=0,numi=0,semx=0;
int a[M],col[M],com[M],n;
int main(){
	n=read();
	F(i,1,n) a[i]=read();
	dp[0]=1; mi=1; numi=1;
	ms(col,1);
	F(i,2,n){
		int now=0;
		if (col[a[i]]==mi){
			now=mi;
		}
		else{
			now=mi+1;
		}
		if (a[i]^a[i-1]) tg++,now--;
//		cout<<now<<" "<<tg<<" "<<mi<<" "<<col[a[i]]<<"  hh\n";
		if (now<mi){
			mi=now;
			numi=1;
		}
		else{
			if (now==mi){
				numi++;
			}
		}
		if (now<col[a[i-1]]){
			col[a[i-1]]=now;
			com[a[i-1]]=1;
		}
		else{
			if (now==col[a[i-1]]){
				com[a[i-1]]++;
			}
		}
	}
	cout<<tg+mi<<"\n"; 
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/