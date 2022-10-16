#include <bits/stdc++.h>
using namespace std;
int n, k=2;
vector <pair <int, int>> elements;
int cnt[200001];
vector <int> color[200001];
bool check(int req){
	priority_queue <int> q;
	vector <int> temp;
	for(auto &x: elements) q.push(x.first);
	for(int i=1; i<=k; i++){
		temp.clear();
		for(int j=1; j<=req; j++){
			if(q.empty()) return 0;
			auto p=q.top();
			q.pop();
			if(p>1){
				temp.emplace_back(p-1);
			}
		}
		for (auto &x: temp) q.push(x);
	}
	return 1;
}
void make_answer(int req){
	priority_queue <pair <int, int>> q;
	for(auto &x: elements) q.push(x);
	vector <pair <int, int>> temp;
	for(int i=1; i<=k; i++){
		temp.clear();
		for(int j=1; j<=req; j++){
			assert(!q.empty());
			auto p=q.top();
			q.pop();
			color[p.second].emplace_back(i);
			if(p.first>1){
				temp.emplace_back(p.first-1, p.second);
			}
		}
		for (auto &x: temp) q.push(x);
	}
}
void solve(){
	for(int i=0; i<=25; i++){
		cnt[i]=0;
		color[i].clear();
	}
	elements.clear();
	
	
	k=2;
	string s;
	cin>>s;
	n=s.size();
	for(char c: s) cnt[c-'a']++;
	for(int i=0; i<=25; i++) if(cnt[i]) elements.emplace_back(cnt[i], i);
	sort(elements.begin(), elements.end());
	reverse(elements.begin(), elements.end());
	int low=0, high=n/k, mid, ans=-1;
	while(low<=high){
		mid=(low+high)/2;
		if(check(mid)){
			ans=mid;
			low=mid+1;
		}
		else high=mid-1;
	}
	cout<<ans<<'\n';
	// make_answer(i);
	
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}