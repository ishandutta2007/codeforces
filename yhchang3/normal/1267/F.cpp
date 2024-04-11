#include<bits/stdc++.h>
using namespace std;


int cnt[200010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ka,kb;
	cin>>n>>m>>ka>>kb;
	queue<int> qa,qb;
	for(int i=0;i<ka;i++){
		int x;
		cin>>x;
		qa.emplace(x);
		cnt[x]++;
	}
	for(int i=0;i<kb;i++){
		int x;
		cin>>x;
		cnt[x]++;
		qb.emplace(x);
	}
	if(ka>m-1||kb>n-1)
		cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		for(int i=ka;i<m-1;i++)
			qa.emplace(1),cnt[1]++;
		for(int i=kb;i<n-1;i++)
			qb.emplace(n+1),cnt[n+1]++;
		priority_queue<int,vector<int>,greater<int> > pq;
		for(int i=1;i<=n+m;i++)
			if(cnt[i]==0)
				pq.emplace(i);
		vector<pair<int,int>> e;
		for(int _=1;_<=n+m-2;_++){
			int x=pq.top();pq.pop();
			if(x>n){
				int y=qa.front();qa.pop();
				e.emplace_back(x,y);
				if(--cnt[y]==0)
					pq.emplace(y);
			}
			else{
				int y=qb.front();qb.pop();
				e.emplace_back(x,y);
				if(--cnt[y]==0)
					pq.emplace(y);
			}
		}
		int x=pq.top();pq.pop();
		int y=pq.top();pq.pop();
		e.emplace_back(x,y);
		for(auto it:e)
			cout<<it.first<<' '<<it.second<<'\n';
	}
}