#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,color[300];
int a[N];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(color,-1,sizeof color);
	for (int i=1;i<=n;i++){
		if (color[a[i]]!=-1){
			printf("%d ",color[a[i]]);
			continue;
		}
		int j;
		for (j=a[i];j>0&&(a[i]-j+1)<k&&color[j-1]==-1;j--);
		int co;
		if (j>0&&color[j-1]!=-1&&a[i]-color[j-1]+1<=k)
			co=color[j-1];
		else
			co=j;
		for (int t=j;t<=a[i];t++)
			color[t]=co;
		printf("%d ",co);
	}
	return 0;
}