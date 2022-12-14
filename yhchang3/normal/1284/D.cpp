#include<bits/stdc++.h>
using namespace std;


int sa[100001],sb[100001],ea[100001],eb[100001];
bool check(int n){
	multiset<int> st,en;
	vector<pair<pair<int,int>,int> > event;
	for(int i=1;i<=n;i++){
		event.emplace_back(make_pair(sa[i],0),i);
		event.emplace_back(make_pair(ea[i],1),i);
	}
	sort(event.begin(),event.end());
	for(auto it:event){
		if(it.first.second==0){
			st.insert(sb[it.second]);en.insert(eb[it.second]);
			if(eb[it.second]>=*prev(st.end())&&sb[it.second]<=*en.begin());
			else
				return false;
		}
		else{
			st.erase(st.find(sb[it.second]));
			en.erase(en.find(eb[it.second]));
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
	bool ok=check(n);
	swap(sa,sb);
	swap(ea,eb);
	ok&=check(n);
	if(ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}