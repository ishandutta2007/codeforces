#include<cstdio>
#include<cmath>
#include<algorithm>
int Q,n;
unsigned cal(unsigned x){
    return n-x+std::min(x*(x-1)/2,n-x);
}
int main()
{
	for(scanf("%d",&Q);Q--;)
		if(scanf("%d",&n),n<6)printf("%d\n",n-1);
		else	printf("%u\n",std::max(cal(sqrt(2u*n)),cal(sqrt(2u*n)+1)));
}