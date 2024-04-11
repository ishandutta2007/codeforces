#include<bits/stdc++.h>
using namespace std;

int n,v;
int price[1000001],pos[1000001];
deque<pair<int,int> > dq;//(pos,price)

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		//cin>>pos[i];
		pos[i]=i;
	}
	for(int i=1;i<=n;i++){
		//cin>>price[i];
		price[i]=i;
	}
	for(int i=1;i<n;i++){
		if(pos[i+1]-pos[i]>v){
			cout<<-1<<endl;
			return 0;
		}
	}
	long long int ans=0,tanknow,target,tmp;
	for(int i=1;i<n;i++){
		tanknow=0;
		target=pos[i+1]-pos[i];
		while(!dq.empty()&&(pos[i]-pos[dq.front().first])>=v)
			dq.pop_front();
		while(!dq.empty()&&price[i]<=dq.back().second)
			dq.pop_back();
		dq.push_back({i,price[i]});
		while(tanknow+(tmp=(v-(pos[i]-pos[dq.front().first]+tanknow)))<target){
			tanknow+=tmp;
			ans+=dq.front().second*tmp;
			dq.pop_front();
		}
		ans+=dq.front().second*(target-tanknow);
	}
	cout<<ans<<endl;
}