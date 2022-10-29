#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	n*=2,m*=2;
	printf("%d ",k%m==0?k/m:k/m+1);
	k-=(k%m==0?k/m-1:k/m)*m;
	printf("%d ",k&1?k/2+1:k/2);
	putchar(k&1?'L':'R');
}