#include<cstdio>
int n,i,x,y;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(x>25 && x>y)y=x;
	}
	printf("%d\n",y>25?y-25:0);
	return 0;
}