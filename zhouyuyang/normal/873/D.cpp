#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
void work(int l,int r){
	if (k<1||l+1==r) return;
	k-=2; int mid=(l+r)/2;
	swap(a[mid-1],a[mid]);
	work(l,mid); work(mid,r);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) a[i]=i+1;
	--k; work(0,n);
	if (k) puts("-1");
	else for (int i=0;i<n;i++)
		printf("%d ",a[i]);
}