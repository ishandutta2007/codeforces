#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

const int inf=~0U>>1;

int main(){
	int n;
	cin>>n;

	int ret[1234][10][2];

	rep(i,10) rep(j,2){
		vector<int> qry;
		rep(k,n) if((k>>i&1)==j)
			qry.push_back(k);
		if(qry.empty()){
			rep(k,n) ret[k][i][j] = inf;
		} else {
			cout<<qry.size()<<endl;
			rep(i,qry.size()) cout<<qry[i]+1<<" ";
			cout<<endl<<flush;
			rep(k,n) cin>>ret[k][i][j];
		}
	}

	cout<<-1<<endl;
	rep(k,n){
		int ans = inf;
		rep(i,10) ans = min(ans,ret[k][i][1-(k>>i&1)]);
		cout<<ans<<" ";
	}
	cout<<endl;
}