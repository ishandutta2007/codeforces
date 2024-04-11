#include <cstdio>
int t,a,b;
inline void swap(int &x,int &y){
	x^=y^=x^=y;
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d",&a,&b);
		if(a>b)swap(a,b);
		switch((a+b)%2){
			case 0:printf("%d\n",a+1);for(register int i=(b-a)/2;i<=a+b-(b-a)/2;i+=2)printf("%d ",i);break;
			case 1:printf("%d\n",2*a+2);for(register int i=(b-a-1)/2;i<=a+b-(b-a-1)/2;++i)printf("%d ",i);break;
			default:printf("I AK IOI!!!");//this won't happen
		}
		putchar('\n');
	}
	return 0;
}