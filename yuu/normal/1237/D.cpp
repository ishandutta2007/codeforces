#include <bits/stdc++.h>
using namespace std;
int n;
int a[600001];
deque <int> s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(*min_element(a+1, a+n+1)*2>=*max_element(a+1, a+n+1)){
		for(int i=1; i<=n; i++) cout<<"-1 ";
		return 0;
	}
	for(int i=1; i<=n; i++) a[i+n]=a[i];
	for(int i=1; i<=n; i++) a[i+n+n]=a[i];
	int f=2;
	s.push_back(1);
	while(a[f]*2>=a[s.front()]){
		while((!s.empty())&&(a[s.back()]<=a[f])) s.pop_back();
		s.push_back(f);
		f++;
	}
	cout<<f-1<<' ';
	for(int i=2; i<=n; i++){
		if(s.front()<i){
			s.pop_front();
			if(s.empty()) s.push_back(i);
			f=max(f, i+1);
		}
		// cerr<<i<<' '<<f<<'\n';
		while(a[f]*2>=a[s.front()]){
			while((!s.empty())&&(a[s.back()]<=a[f])) s.pop_back();
			s.push_back(f);
			// cerr<<f<<'\n';
			// cerr<<a[s.front()]<<'\n';
			f++;
		}
		// cerr<<i<<' '<<f<<'\n';
		cout<<f-i<<" \n"[i==n];
	}
}