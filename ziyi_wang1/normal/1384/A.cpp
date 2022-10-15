#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
char s[220];
int n,m,T,a[110],b[110];
int main(){
	read(T);m=50;
	while(T--){
		read(n);F(i,1,n)read(a[i]);
		F(i,1,m)b[i]=0,s[i]='a';puts(s+1);
		F(i,1,n){
			b[a[i]+1]^=1;
			F(j,1,m)if(b[j])s[j]='b';else s[j]='a';
			puts(s+1);
		}
	}
	return 0;
}