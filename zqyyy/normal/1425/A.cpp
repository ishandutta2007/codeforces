#include <cstdio>
#include <cctype>
#define re register
#define ll long long
using namespace std;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
inline void work(){
	ll n=read(),ans=0;bool flg=1;
	while(n){
		if(n&1)n--,ans+=flg;
		else {
            if(n%4==0 && n!=4) n--,ans+=flg;
            else ans+=flg?n/2:0,n>>=1;
        }
		flg^=1;
	}printf("%lld\n",ans);
}
int main(){
	int t=read();
	while(t--)work();
	return 0;
}