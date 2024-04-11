#include<cstdio>
const int N=300005;
int a,n,i,j;
bool b[N];
int main(){
	scanf("%d",&n);j=n;printf("1 ");
	for(i=1;i<=n;++i){
		scanf("%d",&a);
		b[a]=1;
		while(b[j])--j;
		printf("%d ",i-(n-j)+1);
	}
	return 0;
}