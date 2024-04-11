#include<bits/stdc++.h>
using namespace std;
long long x,n,s,ans;
int i,j,m;
struct node {
	long long x,y;
}a[105];
int main() {
	scanf("%I64d%d",&n,&m);
	long long x=1,s=2,p=0;
	for (i=1;i<=63;i++) {
		if (!p) {
			a[i].x=x;
			a[i].y=s;
			x=x+s/2;
			p=(n-a[i].x)/(s/2)+1;
			p&=1;
			s=s*2;
		}
		else {
			a[i].x=x+s/2;
			if (a[i].x>n) a[i].x=x,x=x+s/2;
			a[i].y=s;
			p=(n-a[i].x)/(s/2)+1;
			p&=1;
			s=s*2;
		}
	}
	for (i=1;i<=m;i++) {
		scanf("%I64d",&x);
		long long s=0;
		for (j=1;j<=63;j++) {
			if ((x-a[j].x)%a[j].y==0) {
				ans=s+(x-a[j].x)/a[j].y+1;
				break;
			}
			else s+=(n-a[j].x)/a[j].y+1;
		}
		printf("%I64d\n",ans);
	}
}