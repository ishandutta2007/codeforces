#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,i,j;
ll a[100005],x,y;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);for(i=1;i<=n;++i)scanf("%lld",a+i);
		for(j=0;;++j){
			x=(1ll<<j)-1;y=a[1];
			for(i=2;i<=n;++i){
				if(a[i]+x<y)break;y=a[i]<y?y:a[i];
			}
			if(i>n)break;
		}
		printf("%d\n",j);
	}
}