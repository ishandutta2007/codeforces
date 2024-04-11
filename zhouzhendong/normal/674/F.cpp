#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
typedef unsigned uint;
uint Pow(uint x,uint y){
	uint ans=1;
	for (;y;y>>=1,x*=x)
		if (y&1)
			ans*=x;
	return ans;
}
const int N=150;
uint n,p,q;
int lim;
uint c[N];
void prework(){
	For(i,0,lim){
		uint res=1;
		int c2=0;
		For(j,0,i-1){
			uint a=j+1,b=n-j;
			while (~a&1)
				a>>=1,c2--;
			while (~b&1)
				b>>=1,c2++;
			res*=Pow(a,(1u<<31)-1);
			res*=b;
		}
		assert(c2>=0);
		c[i]=res<<c2;
	}
}
int main(){
	n=read(),p=read(),q=read();
	lim=min(n-1,p);
	prework();
	uint ans=0;
	For(i,1,q){
		uint tmp=1;
		uint v=0;
		For(j,0,lim){
			v+=tmp*c[j];
			tmp*=i;
		}
		ans^=(uint)i*v;
	}
	cout<<ans<<endl;
	return 0;
}