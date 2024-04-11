#include<cstdio>
const int N=23,A=4500000;
int n,m,f[A],s[N],i,j,a,b,pre[A],ans[N],pre2[A];
int main(){
	scanf("%d%d",&n,&m);for(i=0;i<n;++i)s[i]=1<<i;
	while(m--)
		scanf("%d%d",&a,&b),s[--a]|=1<<--b,s[b]|=1<<a;
	for(i=1;i<1<<n;++i){
		for(j=0;j<n;++j)if(i>>j&1 && (s[j]&i)!=i)break;
		j<n?f[i]=100:0;
	}
	for(i=1;i<1<<n;++i)
		for(j=0;j<n;++j)
			if(i>>j&1 && f[i|s[j]]>f[i]+1)
				f[i|s[j]]=f[i]+1,pre[i|s[j]]=i,pre2[i|s[j]]=j;
	for(printf("%d\n",f[i=(1<<n)-1]),j=0;i;i=pre[i])
		if(f[i])ans[++j]=pre2[i]+1;
	for(;j;)printf("%d ",ans[j--]);
	return 0;
}