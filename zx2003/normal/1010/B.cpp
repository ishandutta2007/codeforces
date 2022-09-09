#include<cstdio>
int m,n,l,r,mid,a[300],i,x;
int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i){
		puts("1");fflush(stdout);
		scanf("%d",&x);
		a[i]=x;
		if(x==0)return 0;
	}
	i=0;
	l=1;r=m;
	for(;l<r;){
		++i;if(i>n)i=1;
		mid=(l+r)>>1;
		printf("%d\n",mid);fflush(stdout);
		scanf("%d",&x);
		if(x==0)return 0;
		if(a[i]==x)l=mid+1;
			else r=mid-1;
	}
	printf("%d\n",l);fflush(stdout);
	scanf("%d",&x);
	if(x==0)return 0;
	return 0;
}