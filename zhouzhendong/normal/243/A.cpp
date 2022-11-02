#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,a[N],vis[1<<20];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int v1=a[i],v2=0;
		for (int j=i-1;j>=0;j--){
			vis[v1]=1;
			if (v1==v2)
				break;
			v1|=a[j],v2|=a[j];
		}
	}
	int ans=0;
	for (int i=0;i<(1<<20);i++)
		ans+=vis[i];
	printf("%d",ans);
	return 0;
}