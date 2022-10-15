#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
ll n;
inline void work(){
	n=read();
	if(n%2==1)puts("2");
	else{
		ll x=n,y=2;
		while(x%2==0)x>>=1,y<<=1;
		__int128 res=(__int128)x*(x+1)/2;
		if(x>1 && res<=n)printf("%lld\n",x);
        else{
            res=(__int128)y*(y+1)/2;
            if(res<=n)printf("%lld\n",y);
            else puts("-1");
        }
	}
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}