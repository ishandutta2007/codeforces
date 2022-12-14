#include<bits/stdc++.h>
using namespace std;

int vis[100010];

int a[100010],b[100010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	memset(vis,-1,sizeof vis);
	long long int ans=0;
	int cnt=0;
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=1;i<=n;i++){
		if(vis[a[i]]==-1)
			vis[a[i]]=b[i];
		else{
			pq.emplace(min(vis[a[i]],b[i]));
			vis[a[i]]=max(vis[a[i]],b[i]);
		}
	}
	for(int i=1;i<=k;i++)
		if(vis[i]==-1)
			cnt++;
	while(cnt--)
		ans+=pq.top(),pq.pop();
	cout<<ans<<endl;
}