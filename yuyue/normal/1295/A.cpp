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
int bac[10]={6,2,5,5,4,5,6,3,7,6};
int o[10]={-1,-1,1,7,7,7,9,9,9,9};
const int M=1e5+10;
char ch[M];
int main(){
	int T=read();
	while (T--){
		int n=read();
		int t=n,ct=0;
		while (t>=2){
			ch[++ct]='1';
			t-=2;
		}
		if (t&1) ch[ct]='7';
		DF(i,ct,1) cout<<ch[i];
		cout<<"\n"; 
	}
	return 0;
}