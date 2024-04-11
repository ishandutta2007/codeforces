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
const int M=50000;
int r[M],b[M],n;
int main(){
	n=read();
	F(i,1,n) r[i]=read();
	
	F(i,1,n) b[i]=read();
	int o=0,sm=0;
	F(i,1,n){
		if (r[i]==1 && b[i]==0){
			o++;
		}
		if (r[i]==0 && b[i]==1){
			sm++;
		}
	}
	if (!o) {
		cout<<"-1\n";
		return 0;
	}
	cout<<sm/o+1<<"\n";
	return 0;
}