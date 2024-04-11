#include <cstdio>
#include <algorithm>
int t,n,h,ans,arr[200010];
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d",&n,&h);
		for(register int i=0;i<n;++i)scanf("%d",&arr[i]);
		std::sort(arr,arr+n);
		ans=2*(h/(arr[n-1]+arr[n-2])),h%=arr[n-1]+arr[n-2];
		if(!h)printf("%d\n",ans);
		else if(arr[n-1]>=h)printf("%d\n",ans+1);
		else printf("%d\n",ans+2);
	}
	return 0;
}