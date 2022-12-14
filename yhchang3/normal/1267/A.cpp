#include<bits/stdc++.h>
using namespace std;
long long int a[200001],b[200001],t[200001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long int ans=0,now=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>t[i];
	multiset<long long int> speed;
	typedef pair<long long int,int> pli;
	priority_queue<pli,deque<pli>,greater<pli> >  pq;
	for(int i=1;i<=n;i++)
		pq.emplace(a[i]+t[i],i);
	while(!pq.empty()){
		auto it=pq.top();pq.pop();
		if(speed.size()){
			long long int c=(it.first-now)/(*speed.begin());
			ans+=c;
			now+=c*(*speed.begin());
		}
		if(it.second<0){
			speed.erase(speed.find(t[-it.second]));
		}
		else{
			now=max(now,a[it.second]);
			speed.insert(t[it.second]);
			pq.emplace(b[it.second],-it.second);
		}
	}
	cout<<ans<<endl;
}