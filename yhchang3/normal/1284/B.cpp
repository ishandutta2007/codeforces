#include<bits/stdc++.h>
using namespace std;

bool vis[100010];
int mx[100010];
int mi[100010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int ans=0;
	int n;
	cin>>n;
	vector<int> v;
	for(int i=1,l;i<=n;i++){
		cin>>l;
		cin>>mx[i];
		mi[i]=mx[i];
		for(int j=2;j<=l;j++){
			int x;
			cin>>x;
			if(x>mi[i])	vis[i]=true;
			mx[i]=max(mx[i],x);
			mi[i]=min(mi[i],x);
		}
		if(!vis[i])
			v.emplace_back(mx[i]);
	}
	long long int cnt=0;
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			cnt++;
			int idx=upper_bound(v.begin(),v.end(),mi[i])-v.begin();
			ans+=v.size()-idx;
		}
	ans+=(long long int) n*n-cnt*cnt;
	cout<<ans<<endl;
}