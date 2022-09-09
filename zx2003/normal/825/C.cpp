#include<cstdio>
#include<algorithm>
int n,k,a[1005],i,j,ans;
inline void up(int&a,int b){
	if(a<b)a=b;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(i=1;i<=n;)
		if(k<<1<a[i])++ans,k<<=1;
			else up(k,a[i]),++i;
	printf("%d\n",ans);
	return 0;
}