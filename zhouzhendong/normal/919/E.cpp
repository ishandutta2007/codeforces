#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=1e6+10;
LL a,b,p,x,inv[P];
LL Pow(LL x,LL y){
	if (!y)
		return 1;
	LL xx=Pow(x,y/2);
	xx=xx*xx%p;
	if (y&1LL)
		xx=xx*x%p;
	return xx;
}
LL Inv(LL x){
	return Pow(x,p-2);
}

int main(){
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&p,&x);
	for (LL i=1;i<p;i++)
		inv[i]=Inv(i);
	LL ans=0;
	for (LL i=1;i<p;i++){
		LL y=b*inv[Pow(a,i)]%p;
		// n=y (mod p)
		// n=i (mod p-1)
		// n=up+y=v(p-1)+i
		// n=kp(p-1) - (p-1)*y + p*i
		LL mod=p*(p-1),n=(p*i%mod-(p-1)*y%mod+mod-1)%mod+1;
		if (n<=x)
			ans+=(x-n)/mod+1;
	}
	printf("%I64d",ans);
	return 0;
}