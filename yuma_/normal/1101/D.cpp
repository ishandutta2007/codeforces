#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int answer=0;
map<int, int>dfs(int now,int from,const vector<int>&as, const vector<vector<int>>&edges) {
	vector<map<int,int>>mps;
	for (auto e : edges[now]) {
		if(e==from)continue;
		else {
			mps.push_back(dfs(e,now,as,edges));
		}
	}
	vector<int>my_primes;
	{
		int rest=as[now];
		for ( int i = 2; i <= int(sqrt(as[now]))+1; ++i) {
			if (rest % i == 0) {
				my_primes.push_back(i);
				while (rest%i == 0) {
					rest/=i;
				}
			}
		}
		if(rest!=1)my_primes.push_back(rest);
	}
	map<int,vector<int>>max_mp;
	for (auto my_prime : my_primes) {
		max_mp[my_prime] = vector<int>{ 0,0 };
	}
	for (auto& mp : mps) {
		map<int,int>next_mp;
		for (auto my_prime : my_primes) {
			if (mp.find(my_prime) != mp.end()) {
				next_mp[my_prime]=mp[my_prime];
			}
		}
		mp=next_mp;
		for (auto m : mp) {
			max_mp[m.first].push_back(m.second);
			sort(max_mp[m.first].begin(),max_mp[m.first].end(),greater<int>());
			max_mp[m.first].pop_back();
			
		}
	}
	for (auto max_m : max_mp) {
		if (max_m.second.size() == 1) {
			answer=max(answer,max_m.second[0]+1);
		}
		else {
			answer=max(answer,max_m.second[0]+max_m.second[1]+1);
		}
	}

	map<int,int>ret_mp;
	for (auto max_m : max_mp) {
		ret_mp[max_m.first]=1+max_m.second[0];
	}
	return ret_mp;

}

int main()
{
	int N;cin>>N;
	vector<int>as(N);
	for(int i=0;i<N;++i)scanf("%d",&as[i]);
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,-1,as,edges);
	cout<<answer<<endl;
	
	return 0;
}