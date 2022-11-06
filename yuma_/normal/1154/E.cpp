#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ll=long long ;
#define Whats(x) //cout<<#x<<" is "<<(x)<<endl
string ans;
vector<ll>nums(100);
vector<ll>tos(100);



int main() {
	int N,K;cin>>N>>K;
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);
	set<pair<int,int>>aset;
	for (int i = 0; i < N; ++i) {
		aset.emplace(v[i],i);
	}
	vector<int>anss(N,-1);
	vector<int>ls(N),rs(N);
	for (int i = 0; i < N; ++i) {
		ls[i]=i-1;
		rs[i]=i+1;
	}

	int id=0;
	while (!aset.empty()) {
		auto it=prev(aset.end());
		const int place=it->second;

		int l_place,r_place;
		anss[place]=id;
		aset.erase(it);
		int now=place;
		for (int x = 0; x < K; ++x) {
			now=rs[now];
			if (now == N) {
				break;
			}
			else {
				anss[now]=id;
				aset.erase(aset.find(make_pair(v[now],now)));
			}
		}
		if(now!=N)now=rs[now];
		r_place=now;
		now=place;
		for (int x = 0; x < K; ++x) {
			 now = ls[now];
			if (now == -1) {
				break;
			}
			else {
				anss[now] = id;
				aset.erase(aset.find(make_pair(v[now], now)));
			}
		}
		if (now != -1)now = ls[now];
		l_place = now;
		
		if (l_place != -1 && r_place != N) {
			rs[l_place]=r_place;
			ls[r_place]=l_place;
		}
		else if (r_place!=N) {
			ls[r_place]=-1;
		}
		else if (l_place!=-1) {
			rs[l_place]=N;
		}
		id^=1;
	}
	for (int i = 0; i < N; ++i) {
		printf("%d",anss[i]+1);
	}
	cout<<endl;
	return 0;
}