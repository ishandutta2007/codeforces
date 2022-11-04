#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll sum;
int n,m,a[100005],b[100005];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]),sum+=a[i];
	if (sum<=m){
		printf("-1");
		return 0;
	}
	double l=0,r=1e12,mid,ans;
	while (r-l>1e-9){
		mid=(l+r)/2;
		double need=0;
		for (int i=1;i<=n;i++)
			if (b[i]-a[i]*mid<0)
				 need+=a[i]*mid-b[i];
		if (need>m*mid) r=mid;
		else l=ans=mid;
	}
	printf("%.10lf",ans);
}