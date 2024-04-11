#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for (int i=1;i<=n;i++){
		int p=(i-1)*2+1;
		int x;
		for (int j=p+1;j<=n*2;j++){
			if (a[j]==a[p]){
				x=j;
				break;
			}
		}
		ans+=x-p-1;
		for (int j=x;j>p+1;j--)
			swap(a[j],a[j-1]);
	}
	printf("%d",ans);
	return 0;
}