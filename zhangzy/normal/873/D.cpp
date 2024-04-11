#include<bits/stdc++.h>
using namespace std;

int n,k,f[101000],ans[101000];

void doit(int l,int r,int v,int aim){
	aim--;
	if (!aim) {
		for (int i=l;i<r;i++)
			ans[i]=v++;
		return;
	}
	int mid=l+r>>1,len1=mid-l,len2=r-mid;
	doit(l,mid,v+len2,min(aim-1,f[len1]));
	doit(mid,r,v,max(1,aim-f[len1]));
}

int main(){
	cin>>n>>k;
	f[1]=1;
	for (int i=2;i<=n;i++)
		f[i]=f[i/2]+f[i-i/2]+1;
	if (k>f[n]||k%2==0) return 0*puts("-1");
	doit(0,n,1,k);
	for (int i=0;i<n;printf("%d ",ans[i++]));
}