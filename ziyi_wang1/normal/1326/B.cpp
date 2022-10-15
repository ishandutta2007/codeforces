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
int n,m,b[202000],a[202000],now;
int main(){
	read(n);
	F(i,1,n)read(b[i]);
	a[1]=b[1];now=max(0,b[1]);
	F(i,2,n){
		a[i]=now+b[i];now=max(now,a[i]);
	}
	F(i,1,n)cout<<a[i]<<" ";
	return 0;
}