#include<bits/stdc++.h>
#define maxn  200010
using namespace std;
int a[maxn],n,mxx;
long long s[maxn],x;
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),mxx=max(mxx,a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int lst=1;
		long long ans=0;
		if(a[i]==a[i-1])continue;
		for(int j=0;1ll*j*a[i]<=mxx;j++){
			int pos=lower_bound(a+1,a+n+1,(j+1)*a[i])-a-1;
//			printf("[%d,%d]",lst,pos);
			ans+=1ll*(pos-lst)*j*a[i];
			lst=pos;
		}
//		printf("%I64d",ans);
		x=max(x,ans);
//		putchar(10);
	}
	cout<<x;
}