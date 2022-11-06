#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int N, M;
vector<long long int>solve(const vector<long long int>&part_cant_withs,int offset=0) {
	int asize=part_cant_withs.size();
	vector<long long int>sum_cant_withs(1ll<<asize);
	for (int i = 0; i < (1ll<<asize); ++i) {
		long long int total_cant_with=0;
		for (int j = 0; j < asize; ++j) {
			if ((i&(1 << j)) != 0) {
				total_cant_with |= part_cant_withs[j];
			}
		}
		bool ok=true;
		for (int j = 0; j < asize; ++j) {
			if ((i&(1 << j)) != 0) {
				if ((total_cant_with&(1ll << (j+offset))) != 0) {
					ok=false;
				}
			}
		}
		if (ok) {
			sum_cant_withs[i]=total_cant_with;
		}
		else {
			sum_cant_withs[i]=-1;
		}
	}
	return sum_cant_withs;
}
int main()
{
	cin>>N>>M;
	vector<long long int>cant_withs(M);
	{
		long long int cant_with = 0;
		int nextid = 0;
		map<string, int>name_mp;
		for (int i = 0; i < N; ++i) {
			int x; scanf("%d", &x);
			if (x == 1) {
				if (i == 0)continue;
				else {
					for (int i = 0; i < M; ++i) {
						if (cant_with&(1ll << i)) {
							cant_withs[i] |= cant_with;
						}
					}
					cant_with=0;
				}
			}
			else {
				char chs[50];
				scanf("%s", chs);
				string st = chs;
				if (name_mp.find(st) == name_mp.end()) {
					name_mp[st] = nextid++;
				}
				int id = name_mp[st];
				cant_with |= (1ll << id);
			}
		}
		{
			if (cant_with) {
				for (int i = 0; i < M; ++i) {
					if (cant_with&(1ll << i)) {
						cant_withs[i]|=cant_with;
					}
				}
			}
			cant_with=0;
		}
		for (int i = 0; i < M; ++i) {
			if (cant_withs[i] & (1ll << i)) {
				cant_withs[i]^=(1ll<<i);
			}
		}
	}
	int pre_num=M/2;
	int aft_num=M-M/2;
	vector<long long int>pre_cant_withs(cant_withs.begin(),cant_withs.begin()+pre_num);
	vector<long long int>aft_cant_withs(cant_withs.begin()+pre_num,cant_withs.end());
	vector<long long int>pre_sum_cant_withs=solve(pre_cant_withs);
	{
		for (auto& scw : pre_sum_cant_withs) {
			if(scw!=-1)scw>>=pre_num;
		}
	}
	vector<long long int>aft_sum_cant_withs = solve(aft_cant_withs,pre_num);
	vector<int>aft_nums(1ll<<pre_num);
	{
		long long int k=(1<<pre_num)-1;
		for (auto& scw : aft_sum_cant_withs) {
			if(scw!=-1)scw&=k;
		}

		for (int i = 0; i <(1<<aft_num); ++i) {
			int ascw=aft_sum_cant_withs[i];
			if(ascw==-1)continue;
			bitset<20>bs(i);

			long long int rev=((1<<pre_num)-1)^ascw;
			aft_nums[rev]=max(aft_nums[rev],int(bs.count()));
		}
		for (int i = (1<<pre_num)-1; i>=0;--i){
			for (int j = 0; j < pre_num; ++j) {
				if ((i&(1 << j)) !=0) {
					aft_nums[i^(1<<j)]=max(aft_nums[i],aft_nums[i^(1<<j)]);
				}
			}
		}
	}


	int answer=0;
	for (int i = 0; i < pre_sum_cant_withs.size(); ++i) {
		int now_answer=0;
		long long int sum_cant_with(pre_sum_cant_withs[i]);
		if(sum_cant_with==-1)continue;
		bitset<40>bs(i);
		now_answer+=bs.count();
		now_answer+=aft_nums[i];
		answer=max(answer,now_answer);
	}
	cout<<answer<<endl;
	
	return 0;
}