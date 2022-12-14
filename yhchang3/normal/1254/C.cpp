#include<bits/stdc++.h>
using namespace std;


long long int area[1001];
int sign[1001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,L=-1,R=-1;
	cin>>n;
	vector<int> l,r;
	for(int i=3;i<=n;i++){
		cout<<1<<' '<<1<<' '<<2<<' '<<i<<endl;
		cin>>area[i];
		cout<<2<<' '<<1<<' '<<2<<' '<<i<<endl;
		cin>>sign[i];
		if(sign[i]==1)
			l.emplace_back(i);
		else
			r.emplace_back(i);
	}
	vector<int> ans(1,1);
	if(r.size()!=0){
		for(int it:r)
			if(R==-1||area[it]>area[R])
				R=it;
		for(int it:r)
			if(it!=R){
				cout<<2<<' '<<1<<' '<<R<<' '<<it<<endl;
				cin>>sign[it];
			}
		vector<pair<long long int,int> > v;
		for(int it:r)
			if(it!=R&&sign[it]==-1)
				v.emplace_back(make_pair(area[it],it));
		sort(v.begin(),v.end());
		for(auto it:v)
			ans.emplace_back(it.second);
		v.clear();
		ans.emplace_back(R);
		for(int it:r)
			if(it!=R&&sign[it]==1)
				v.emplace_back(make_pair(-area[it],it));
		sort(v.begin(),v.end());
		for(auto it:v)
			ans.emplace_back(it.second);
	}
	ans.emplace_back(2);
	if(l.size()!=0){
		for(int it:l)
			if(L==-1||area[it]>area[L])
				L=it;
		for(int it:l)
			if(it!=L){
				cout<<2<<' '<<1<<' '<<L<<' '<<it<<endl;
				cin>>sign[it];
			}
		vector<pair<long long int,int> > v;
		for(int it:l)
			if(it!=L&&sign[it]==-1)
				v.emplace_back(make_pair(area[it],it));
		sort(v.begin(),v.end());
		for(auto it:v)
			ans.emplace_back(it.second);
		v.clear();
		ans.emplace_back(L);
		for(int it:l)
			if(it!=L&&sign[it]==1)
				v.emplace_back(make_pair(-area[it],it));
		sort(v.begin(),v.end());
		for(auto it:v)
			ans.emplace_back(it.second);
	}
	cout<<0<<' ';
	for(int it:ans)
		cout<<it<<' ';
	cout<<endl;
}