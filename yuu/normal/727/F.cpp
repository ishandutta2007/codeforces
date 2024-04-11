#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[751];
using ll=long long;
ll cost[751];
bool check(ll s, int k){
	priority_queue <int> q;
	for(int i=1; i<=n; i++){
		s+=a[i];
		q.push(-a[i]);
		while(s<0){
			if((!q.empty())&&(k)){
				s+=q.top();
				q.pop();
				k--;
			}
			else return 0;
		}
	}
	return 1;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=0; i<=n; i++){
		ll low=0, high=1e16, mid;
		while(low<=high){
			mid=(low+high)/2;
			if(check(mid, i)){
				cost[i]=mid;
				high=mid-1;
			}
			else low=mid+1;
		}
	}
	for(int i=1; i<=m; i++){
		ll s;
		cin>>s;
		int low=0, high=n, mid, res=n;
		while(low<=high){
			mid=(low+high)/2;
			if(cost[mid]<=s){
				res=mid;
				high=mid-1;
			}
			else low=mid+1;
		}
		cout<<res<<'\n';
	}
}