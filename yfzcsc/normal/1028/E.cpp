#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef long long ll;
int n,a[maxn];
ll b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	ll mn=*min_element(a+1,a+n+1);
	ll mx=*max_element(a+1,a+n+1);
	if(mn==mx){
		if(mn==0){
			puts("YES");
			for(int i=1;i<=n;++i)printf("1 ");
		} else {
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)if(a[i]==mx&&a[i==1?n:i-1]!=mx){
		puts("YES");
		b[i]=a[i];
		for(int j=(i==1?n:i-1);j!=i;j=(j==1?n:j-1)){
			ll val=b[j==n?1:j+1];
			ll nxt=a[j==1?n:j-1];
//			printf("[%d:%lld(%lld)]",j,nxt+1-a[j],val);
			b[j]=((nxt+1-a[j]+val-1)/val)*val+a[j];
		}
		for(int j=1;j<=n;++j)printf("%lld ",b[j]);
		return 0;
	}
}