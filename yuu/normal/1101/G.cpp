#include <bits/stdc++.h>
using namespace std;
int n;
int x[200001];
vector <int> ans;
int w[32];
bool can_add(int x){
	for(int i=30; i>=0; i--) if((x>>i)&1){
		if(w[i]>=0){
			x^=ans[w[i]];
		}
		else{
			w[i]=ans.size();
			ans.push_back(x);
			return 1;
		}
	}
	return 0;
}
vector <int> now;
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>x[i];
		x[i]^=x[i-1];
	}
	if(x[n]==0){
		cout<<"-1\n";
		return 0;
	}
	for(int i=0; i<32; i++) w[i]=-1;
	can_add(x[n]);
	x[n]=0;
	bool found=1;
	while(found){
		found=0;
		for(int i=1; i<=n; i++) if(x[i]){
			if(can_add(x[i])) found=1;
			else x[i]=0;
		}
	}
	cout<<ans.size()<<'\n';
}