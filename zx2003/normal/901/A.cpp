#include<cstdio>
const int N=300005;
int s,n,h,i,a[N],b[N],c[N],j;
int main(){
	scanf("%d",&h);
	for(i=0;i<=h;++i)scanf("%d",a+i),n+=a[i];
	for(i=1;i<h;++i)if(a[i]>1 && a[i+1]>1)break;s=i;
	if(s==h)puts("perfect");
		else{
			puts("ambiguous");
			for(i=b[0]=1;i<=h;++i)b[i]=b[i-1]+a[i];printf("0 ");
			for(i=1;i<=h;++i)
				for(j=b[i-1]+1;j<=b[i];++j)printf("%d ",b[i-1]);
			printf("\n0 ");
			for(i=1;i<=h;++i)
				if(i==s+1){
					printf("%d ",b[i-1]-1);
					for(j=b[i-1]+2;j<=b[i];++j)printf("%d ",b[i-1]);
				}else for(j=b[i-1]+1;j<=b[i];++j)printf("%d ",b[i-1]);
		}
	return 0;
}