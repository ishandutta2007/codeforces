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
int n,m,T,a[1010],b[1010];
int main(){
	read(T);
	while(T--){
		read(n);
		F(i,1,n)read(a[i]);
		F(i,1,n)read(b[i]);
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		F(i,1,n)cout<<a[i]<<" ";
		cout<<endl;
		F(i,1,n)cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}