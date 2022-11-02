#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
bool isd(char ch){
	return '0'<=ch&&ch<='9';
}
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isd(ch))
		ch=getchar();
	while (isd(ch))
		x=x*10+ch-48,ch=getchar();
	return x;
}
LL k,d,t,r;
int main(){
	k=read(),d=read(),t=read();
	t*=2;
	r=((k-1)/d+1)*d;
	LL a=k,b=r-k;
	LL x=a*2+b;
	double ans=t/x*r;
	LL y=t%x;
	if (y>k*2)
		ans+=k+y-k*2;
	else
		ans+=1.0*y/2;
	printf("%.10lf\n",ans);
	return 0;
}