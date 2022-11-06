#include <bits/stdc++.h>
using namespace std;
using ld=long double;
ld eps=1e-9;
struct circle{
	int x;
	int y;
	int r;
};
bool a_is_in_b(circle&a,circle&b){
	ld dis=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
	return a.r+dis-eps<b.r;
}
int main() {
	int N;cin>>N;
	vector<circle>cs;
	cs.push_back(circle{0,0,1<<30});
	for(int i=0;i<N;++i){
		int x,y,r;cin>>x>>y>>r;
		cs.push_back(circle{x,y,r});
	}
	vector<vector<int>>edges(N+1);
	vector<int>froms(N+1);
	
	for(int i=0;i<N+1;++i){
		for(int j=0;j<N+1;++j){
			if(i==j)continue;
			else{
				if(a_is_in_b(cs[i],cs[j])){
					edges[j].push_back(i);
					froms[i]++;
				}
			}
		}
	}
	ld ans=0;
	queue<pair<int,int>>que;
	que.emplace(0,0);
	while(!que.empty()){
		auto atop(que.front());
		que.pop();
		int now=atop.first;
		int depth=atop.second;
		if(now){
			if(depth==1||depth==2)ans+=acos(-1.0)*cs[now].r*cs[now].r;
			else{
				if(depth%2){
					ans-=acos(-1.0)*cs[now].r*cs[now].r;
				}else{
					ans+=acos(-1.0)*cs[now].r*cs[now].r;
				}
			}
		}
		for(auto e:edges[now]){
			froms[e]--;
			if(froms[e]==0){
				que.emplace(e,depth+1);
			}
		}
	}
	cout<<setprecision(10)<<fixed<<ans<<endl;
	return 0;
}