#include <bits/stdc++.h>
using namespace std;
int n;
deque <int> a, b;
int main(){
	cin>>n;
	a.resize(n);
	for(auto &x: a) cin>>x;
	b.resize(n);
	for(auto &x: b) cin>>x;
	while(a.front()){
		a.push_back(a.front());
		a.pop_front();
	}
	a.pop_front();
	while(a.front()!=1){
		a.push_back(a.front());
		a.pop_front();
	}
	while(b.front()){
		b.push_back(b.front());
		b.pop_front();
	}
	b.pop_front();
	while(b.front()!=1){
		b.push_back(b.front());
		b.pop_front();
	}
	if(a==b) cout<<"YES";
	else cout<<"NO";
}