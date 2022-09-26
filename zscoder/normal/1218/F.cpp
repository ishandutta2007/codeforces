#include<bits/stdc++.h>
using namespace std;
int n,k,a;
int x[100001];
int c[100001];
priority_queue<int,vector<int>,greater<int> >pq;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++) cin >> x[i];
	cin >> a;
	int cur=0;
	long long ans=0;
	for(int i=1; i<=n ;i++){
		cin >> c[i];
		pq.push(c[i]);
		x[i]=(x[i]-k+a-1)/a;
		if(x[i]<=cur) continue;
		while(cur<x[i]){
			if(pq.empty()) return cout << "-1\n",0;
			ans+=pq.top();
			pq.pop();
			cur++;
		}
	}
	cout << ans << endl;
}