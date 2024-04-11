#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int tot=0,ans=0;
	for (int i=1,j;i<=n;i=j+1){
		for (j=i;j<n&&a[j+1]==a[i];j++);
		int now=j-i+1;
		if (now>=tot){
			ans+=tot;
			tot=now;
		}
		else
			ans+=now;
	}
	printf("%d",ans);
	return 0;
}