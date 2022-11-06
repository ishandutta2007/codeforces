#include <bits/stdc++.h>
using namespace std;
using ld=long double;

int main() {
	int A,B;cin>>A>>B;
	vector<int>as;
	vector<int>bs;
	for(int i=0;i<A;++i){
		int a;cin>>a;
		as.push_back(a);
	}
	for(int i=0;i<B;++i){
		int b;cin>>b;
		bs.push_back(b);
	}
	if(B==1){
		*find(as.begin(),as.end(),0)=bs[0];
		if(is_sorted(as.begin(),as.end())){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
		
	}else{
		cout<<"Yes"<<endl;
	}

	return 0;
}