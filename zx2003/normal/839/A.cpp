#include<cstdio>
int a,n,k,i,s,ans,ss;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%d",&a);
		ss+=a; 
		if(ss>8)s+=8,ss-=8;
			else s+=ss,ss=0;
		if(s>=k && !ans)ans=i;
	}
	printf("%d\n",ans?ans:-1);
	return 0;
}