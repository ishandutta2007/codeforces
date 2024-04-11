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
ll m;
ll n,T,l,r,a,b,c,d,x;
int main(){
	read(T);
	while(T--){
		read(l);read(r);read(m);
		for(a=l;a<=r;a++){
			n=(m+r-l)/a;
			if(m-r+l<=n*a&&n*a<=m+r-l){
				x=m-a*n;
				if(x>=0)b=x+l,c=l;
				else b=r+x,c=r;cout<<a<<" "<<b<<" "<<c<<endl;
				break;
			}
		}
//		assert(false);
	}
	return 0;
}