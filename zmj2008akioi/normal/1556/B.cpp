#include <cstdio>
int t,n,cnt,arr[100010],odd[100010];
long long ans,ans1,ans2;
inline int abs(int x){
	return x>0?x:(-x);
}
inline long long min(long long a,long long b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		cnt=0;
		for(register int j=1;j<=n;++j){
			scanf("%d",&arr[j]);
			if(arr[j]%2==1)odd[++cnt]=j;
		}
		if(cnt!=n/2&&cnt!=(n+1)/2)printf("-1\n");
		else{
			ans=0;
			if(n%2==0){
				ans1=ans2=0;
				for(register int i=1;i<=n/2;++i)ans1+=abs(i*2-1-odd[i]);
				for(register int i=1;i<=n/2;++i)ans2+=abs(i*2-odd[i]);
				ans=min(ans1,ans2);
			}
			else if(cnt==n/2)for(register int i=1;i<=n/2;++i)ans+=abs(i*2-odd[i]);
			else for(register int i=1;i<=(n+1)/2;++i)ans+=abs(i*2-1-odd[i]);
			printf("%lld\n",ans);
		}
		
	}
	return 0;
}