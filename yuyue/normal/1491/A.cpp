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
int n,s,a[M];
int main(){
	n=read(); int q=read(); 
	F(i,1,n){
		a[i]=read();
		s+=a[i];
	}
	F(i,1,q){
		int op=read(),x=read();
		if (op==1){
			if (a[x]) s--;
			else s++;
			a[x]^=1;
		}
		else{
			cout<<(x<=s ? 1 : 0)<<"\n";
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* calm down
*/