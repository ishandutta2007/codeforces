#include <cstdio>
int t,n,q,c,l,r,sum0[300010],sum1[300010];
char str[300010];
inline int abs(int x){
	return x>0?x:(-x);
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d",&n,&q);
		scanf("%s",str+1);
		for(register int j=1;j<=n;++j){
			sum0[j]=sum0[j-1];
			sum1[j]=sum1[j-1];
			if(str[j]=='+'&&j%2==0)++sum0[j];
			if(str[j]=='+'&&j%2==1)++sum1[j];
			if(str[j]=='-'&&j%2==0)++sum1[j];
			if(str[j]=='-'&&j%2==1)++sum0[j];
		}
		for(register int j=1;j<=q;++j){
			scanf("%d %d",&l,&r);
			if(sum0[r]-sum0[l-1]==sum1[r]-sum1[l-1])printf("0\n");
			else if((r-l)%2==0)printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}