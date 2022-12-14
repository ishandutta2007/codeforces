#include<bits/stdc++.h>
using namespace std;


int a[101][101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	int ans=1000;
	vector<int> v;
	for(int i=1;i<n;i++){
		vector<int> vv;
		int diff=0;
		for(int j=1;j<=m;j++)
			diff+=a[j][n]-a[j][i];
		priority_queue<pair<int,int> > pq;
		for(int j=1;j<=m;j++)
			pq.emplace(a[j][n]-a[j][i],j);
		while(diff>0){
			diff-=pq.top().first;vv.emplace_back(pq.top().second);
			pq.pop();
		}
		if(vv.size()<ans){
			ans=vv.size();
			v=vv;
		}
	}
	cout<<ans<<endl;
	for(int it:v)
		cout<<it<<' ';
	cout<<endl;
}