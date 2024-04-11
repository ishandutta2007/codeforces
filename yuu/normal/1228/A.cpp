#include <bits/stdc++.h>
using namespace std;
int main(){
	int l, r;
	cin>>l>>r;
	while(l<=r){
		int u=l;
		map <int, int> d;
		while(u>0){
			d[u%10]++;
			u/=10;
		}
		bool bad=0;
		for(auto &x: d) if(x.second>1) bad=1;
		if(bad) l++;
		else break;
	}
	if(l>r) l=-1;
	cout<<l<<'\n';
}