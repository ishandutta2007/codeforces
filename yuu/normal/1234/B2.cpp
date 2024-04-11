#include <bits/stdc++.h>
using namespace std;
deque <int> q;
set <int> s;
int n, k;
int main(){
	cin>>n>>k;
	for(int i=1, x; i<=n; i++){
		cin>>x;
		if(s.find(x)!=s.end()) continue;
		s.insert(x);
		q.push_front(x);
		if(q.size()>k){
			s.erase(q.back());
			q.pop_back();
		}
	}
	cout<<q.size()<<'\n';
	for(int x: q) cout<<x<<' ';
	cout<<'\n';
}