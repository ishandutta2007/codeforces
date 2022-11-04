#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],n,p,q,k,s,ans[100005][305];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--)
		for (int j=1;j<=300;j++)
			if (i+j+a[i]>n) ans[i][j]=1;
			else ans[i][j]=ans[i+j+a[i]][j]+1;
	scanf("%d",&q); 
	while (q--){
		scanf("%d%d",&p,&k);
		if (k<=300){
			printf("%d\n",ans[p][k]);
			continue;
		}
		s=0;
		while (p<=n){
			p=a[p]+p+k;
			s++;
		}
		printf("%d\n",s);
	}
}