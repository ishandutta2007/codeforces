#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
char a[200005],b[200005],d[200005];
int c[200005],la,lb,ans;
int main(){
	scanf("%s%s",a+1,b+1);
	la=strlen(a+1);
	lb=strlen(b+1);
	for (int i=1;i<=la;i++) scanf("%d",&c[i]);
	int l=0,r=la;
	while (l<=r){
		int mid=(l+r)/2;
		memcpy(d,a,sizeof(a));
		for (int i=1;i<=mid;i++) d[c[i]]='#';
		int p=1;
		for (int i=1;i<=la&&p<=lb;i++)
			if (d[i]==b[p]) p++;
		if (p>lb) ans=mid,l=mid+1; else r=mid-1;
	}
	printf("%d",ans);
}