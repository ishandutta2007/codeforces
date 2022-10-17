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
char ch[M]; 
int main(){
	int T=read(); 
	while (T--){
		int n=read();
		scanf("%s",ch+1);
		int pos=0,pl=n+1;
		F(i,1,n){
			if (ch[i]=='0') pos=i; 
			else break; 
		}
		DF(i,n,1){
			if (ch[i]=='1') pl=i; 
			else break; 
		}
		if (pl==pos+1) cout<<(ch+1)<<"\n";
		else {
			F(i,1,pos+1) cout<<"0";
			DF(i,n,pl)  cout<<"1"; 
			cout<<"\n";
		}
	}
	return 0;
}