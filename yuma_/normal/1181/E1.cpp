#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

struct castle{
	int l;
	int r;
	int u;
	int d;
};
bool solve(vector<castle>castles){
	//cout<<castles.size()<<endl;
	if(castles.size()==1)return true;
	map<int,int>xs,ys;
	for(auto c:castles){
		xs[2*c.l]++;
		xs[2*c.r-1]--;
		ys[2*c.u]++;
		ys[2*c.d-1]--;
	}
	int sum=0;
	for(auto it=xs.begin();it!=xs.end();++it){
		sum+=it->second;
		if(sum==0&&next(it)!=xs.end()){
			int div_x=(it->first+1)/2;
			vector<castle> lc,rc;
			for(auto c:castles){
				if(c.r<=div_x)lc.push_back(c);
				else {
					assert(c.l>=div_x);
					rc.push_back(c);
				}
			}
				return solve(lc)&solve(rc);

		}
	}
	for(auto it=ys.begin();it!=ys.end();++it){
		sum+=it->second;
		if(sum==0&&next(it)!=ys.end()){
			int div_y=(it->first+1)/2;
			vector<castle> lc,rc;
			for(auto c:castles){
				if(c.d<=div_y)lc.push_back(c);
				else {
					assert(c.u>=div_y);
					rc.push_back(c);
				}
			}
				return solve(lc)&solve(rc);

		}
	}
	return false;
}
int main() {
	int N;cin>>N;
	vector<castle>castles;
	for(int i=0;i<N;++i){
		int l,u,r,d;cin>>l>>u>>r>>d;
		castles.push_back(castle{l,r,u,d});
	}
	bool ok=solve(castles);
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}