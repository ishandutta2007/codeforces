#include<stdio.h>
#define inf 1000000007
int n,k,a[2000002],p[2000002],b[2000002],c[2000002],tp=0,ans=0;
inline int mod(int &p){p-=p>=inf?inf:0;}
inline void add(int p,int v){
	while(p<=n)mod(c[p]+=v),p+=p&-p;
}
inline int get(int p){
	if(p<=0)return 0;
	register int cnt=0;
	while(p)mod(cnt+=c[p]),p-=p&-p;
	return cnt;
}
inline int ksm(register unsigned long long a,register int b){
	register int ans=1;
	while(b)(b&1)&&(ans=a*ans%inf),a=a*a%inf,b>>=1;
	return ans;
}
int main(){
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;i++)b[i]=ksm(i,k);
	for(int i=1;i<=n;i++)add(i,b[i]>=b[i-1]?b[i]-b[i-1]:inf+b[i]-b[i-1]);
	for(int i=2;i<=n;i++){
		if(!a[i])p[++tp]=i;
		for(int j=1;j<=tp&&p[j]*i<=n&&(a[p[j]*i]=1)&&i%p[j];j++);
	}
	for(int i=1;i<=tp;i++){
		for(int j=n/p[i],k=p[i]*j,val=get(j-1),lval=get(j);j;k-=p[i],lval=val,val=get(--j-1)){
			add(k,val>=lval?val-lval:inf+val-lval);
		}
	}for(int i=1;i<=n;i++)mod(ans+=get(i)^i);
	printf("%d",ans);
}