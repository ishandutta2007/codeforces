#include<bits/stdc++.h>
using namespace std;
int a[1005],n;
vector<pair<int,int> > ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int L=1,R=n,st=1,ed=a[n]+1;
	for (;L<=R;){
		for (int i=1;i<=a[L]-a[L-1];i++){
			for (int j=st+1;j<=ed;j++)
				ans.push_back(make_pair(st,j));
			st++;
		}
		L++;
		ed=a[--R]+1;
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
}