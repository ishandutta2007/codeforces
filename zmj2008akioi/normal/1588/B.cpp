#include <cstdio>
int T,n,d,ld,rg,md;
long long sum;
long long query(int l,int r){
	long long nw;
	printf("? %d %d\n",l,r),fflush(stdout);
	scanf("%lld",&nw);return nw;
}
int div(){
	int mid,l=1,r=n;
	while(l!=r){
		mid=(l+r+1)>>1;
		if((long long)mid*(mid-1)/2<=sum)l=mid;
		else r=mid-1;
	}
	return l;
}
int bsc(){
	int mid,l=1,r=n;
	while(l!=r){
		mid=(l+r)>>1;
		if(query(1,mid)==sum)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	scanf("%d",&T);
	do{
		scanf("%d",&n);
		sum=query(1,n),rg=bsc();
		d=sum-query(1,rg-1),md=rg-d,sum-=(long long)d*(d+1)/2;
		ld=div(),printf("! %d %d %d\n",md-ld,md,rg),fflush(stdout);
	}while(--T);
	return 0;
}
/*
1
10
6
1
4
6
4
*/