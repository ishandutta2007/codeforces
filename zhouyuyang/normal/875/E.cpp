#include<bits/stdc++.h>
#define abs(x) ((x)<0?(-(x)):(x))
using namespace std;
int n,a[100005];
set<int> S;
bool check(int ans){
	if (abs(a[1]-a[2])>ans) return 0;
	for (;!S.empty();S.erase(S.begin()));
	S.insert(a[1]);
	for (int i=3;i<=n;i++){
		if (abs(a[i-1]-a[i])<=ans) S.insert(a[i-1]);
		S.erase(S.begin(),S.lower_bound(a[i]-ans));
		S.erase(S.upper_bound(a[i]+ans),S.end());
		if (S.empty()) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&a[1],&a[2]); n+=2;
	for (int i=3;i<=n;i++) scanf("%d",&a[i]);
	int l=0,r=1e9,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
}