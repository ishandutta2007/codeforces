#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5];
ll max(ll a,ll b){
	return a>b? a:b;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld",a+1,a+2,a+3);
		sort(a+1,a+1+3);
		if(a[2] - a[1] >= 1 && a[3] - a[2]>=1){
			printf("%lld\n",a[2] - a[1] - 1 + a[3] - a[2] - 1 + a[3] - a[1] - 2);
		}
		else{
			if(a[1] == a[2]){
				if(a[2] == a[3]) puts("0");
				else printf("%lld\n", max(2 * (a[3] - a[2] - 2) , 0 ));
			}
			else printf("%lld\n",max(2*(a[3] - a[1] - 2) , 0));
		}
	}
	return 0;
}