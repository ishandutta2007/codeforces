#include <bits/stdc++.h>
using namespace std;
int n, k, q;
set <int> f[21];
int main(){
	cin>>n>>k;
	for(int i=1, a; i<=n; i++){
		cin>>a;
		for(int j=1, sum=a; j<=k; j++, sum+=a) f[j].insert(sum);
	}
	cin>>q;
	f[0].insert(0);
	for(int i=1, x; i<=q; i++){
		int good=0;
		cin>>x;
		for(int ans=1; ans<=k; ans++){
			for(int j=0; j+j<=ans; j++){
				for(auto y: f[j]){
					if(f[ans-j].find(x-y)!=f[ans-j].end()){
						good=ans;
						break;
					}
				}
				if(good) break;
			}
			if(good) break;
		}
		if(!good)	good=-1;
		cout<<good<<'\n';
	}
}