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
const int M=(int)1e6+10;
int p[M],t[M];
int main(){
	int N=(int)1e6;
	F(i,2,N){
		if (!p[i]){
			t[i]++;
			for (int j=i;j<=N;j+=i){
				p[j]=1;
			}
		}
		t[i]+=t[i-1];
	}
	int T=read();
	while (T--){
		int x=read(),tmp=sqrt(x);
		cout<<t[x]-t[tmp]+1<<"\n";
	}
	return 0;
}