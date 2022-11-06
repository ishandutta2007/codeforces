#include<algorithm>
#include<cstdio>
int a[1000002],n,k;long long cnt=0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);int mid=n+1>>1;
	for(int i=mid;i<=n;i++){
		cnt+=a[i];
		if((long long)a[i]*(i-mid+1)-cnt<k)continue;
		cnt-=a[i]-k;return printf("%lld",cnt/(i-mid))&0;
	}printf("%lld",(cnt+k)/mid);
}