#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],Ha[N],hs;
int t[N],ans[N];
vector <int> L[N],R[N],valL[N],valR[N];
void add(int x,int d){
	for (;x<=hs;x+=x&-x)
		t[x]+=d;
}
int sum(int x){
	int ans=0;
	for (;x>0;x-=x&-x)
		ans+=t[x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),Ha[i]=a[i];
	sort(Ha+1,Ha+n+1);
	hs=1;
	for (int i=2;i<=n;i++)
		if (Ha[i]!=Ha[i-1])
			Ha[++hs]=Ha[i];
	for (int i=1;i<=n;i++)
		a[i]=lower_bound(Ha+1,Ha+hs+1,a[i])-Ha;
	for (int i=1;i<=n;i++)
		for (int k=1;k<n&&k*(i-1)+2<=n;k++){
			L	[k*(i-1)+2].push_back(k);
			valL[k*(i-1)+2].push_back(a[i]);
			R	[min(n,k*i+1)+1].push_back(k);
			valR[min(n,k*i+1)+1].push_back(a[i]);
		}
	for (int i=n;i>=1;i--){
		add(a[i],1);
		for (int j=0;j<L[i].size();j++)
			ans[L[i][j]]+=sum(valL[i][j]-1);
		for (int j=0;j<R[i].size();j++)
			ans[R[i][j]]-=sum(valR[i][j]-1);
	}
	for (int i=1;i<n;i++)
		printf("%d ",ans[i]);
	return  0;
}