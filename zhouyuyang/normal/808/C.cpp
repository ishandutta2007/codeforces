#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000005
#define ll long long 
using namespace std;
int n,k,ans[105],a[105],f[105];
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		ans[i]=a[i]-a[i]/2;
		k-=ans[i];
	} 
	if (k<0){
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;i++) f[i]=i;
	sort(f+1,f+n+1,cmp);
	for (int i=1;i<=n;i++){
		int tmp=min(a[f[i]]/2,k);
		k-=tmp; ans[f[i]]+=tmp;
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}