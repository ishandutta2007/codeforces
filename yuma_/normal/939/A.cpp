#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;



int main() { 
	int N;cin>>N;
	vector<int>loves(N);
	for(int i=0;i<N;++i){
		cin>>loves[i];
		loves[i]--;
	}

	bool ok=false;
	for(int i=0;i<N;++i){
		int k=i;
		for(int j=0;j<3;++j){
			k=loves[k];
		}
		if(k==i){
			ok=true;
		}
	}
	if(ok){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;

}