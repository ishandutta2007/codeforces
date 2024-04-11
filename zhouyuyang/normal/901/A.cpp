#include<bits/stdc++.h>
using namespace std;
int n,a[100005],fa[200005];
int main(){
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=1;
	for (int i=1;i<=n;i++){
		for (int j=r+1;j<=r+a[i];j++)
			fa[j]=l;
		l=r+1,r+=a[i];
	}
	int s=r; l=1,r=1;
	for (int i=1;i<=n;i++){
		if (a[i]!=1&&a[i-1]!=1){
			puts("ambiguous");
			for (int j=1;j<=s;j++)
				printf("%d ",fa[j]);
			fa[r+1]=l+1; puts("");
			for (int j=1;j<=s;j++)
				printf("%d ",fa[j]);
				return 0;
		}
		l=r+1,r+=a[i];
	}
	puts("perfect");
}