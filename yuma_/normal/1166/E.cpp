#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;


int main() {
	ios::sync_with_stdio(false);
	int M,N;cin>>M>>N;
	vector<vector<int>>vs(M,vector<int>(N));
	for(int i=0;i<M;++i){
		int a;cin>>a;
		for(int j=0;j<a;++j){
			int b;cin>>b;
			vs[i][b-1]=true;
		}
	}
	bool answer=true;
	for(int i=0;i<M;++i){
		for(int j=i+1;j<M;++j){
			bool ok=false;
			for(int k=0;k<N;++k){
				if(vs[i][k]&&vs[j][k])ok=true;
			}
			if(!ok)answer=false;
		}
	}
	if(!answer)cout<<"im";
	cout<<"possible"<<endl;
	return 0;
}