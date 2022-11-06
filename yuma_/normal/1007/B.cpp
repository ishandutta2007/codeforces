#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
vector<int>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}
long long int gcd(long long int l, long long int r) {
	if (l > r)return gcd(r, l);
	else {
		if (r%l) {
			return gcd(l, r%l);

		}
		else {
			return l;
		}
	}
}
map<long long int, int>soinnsuu(long long int a) {
	hurui(1e5+10);
	map<long long int, int>ans;
	for (auto i : primes) {
		if (i> a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
long long int calc(const map<long long int,int>&mp) {
	long long int ans=1;
	for (auto m : mp) {
		ans*=1+m.second;
	}
	return ans;
}
int main() {
	int T;cin>>T;
	set<vector<int>>used;
	for (int a_id = 1; a_id < 8; ++a_id) {
		for (int b_id = 1; b_id < 8; ++b_id) {
			for (int c_id = 1; c_id < 8; ++c_id) {
				if ((a_id & 1) == 0 || (b_id & 2) == 0 || (c_id & 4) == 0)continue;
				else {
					vector<int>v{ a_id,b_id,c_id };
					sort(v.begin(), v.end());
					if (used.find(v) != used.end())continue;
					else {
						used.emplace(v);

					}
				}
			}
		}
	}
	vector<long long int>cnts(1e5+1);
	for (int i = 1; i <= 1e5; ++i) {
		auto mp=soinnsuu(i);
		cnts[i]=calc(mp);
	}
	while (T--) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		long long int a_num,b_num,c_num,ab_num,bc_num,ca_num,abc_num;
		a_num=cnts[a];
		b_num=cnts[b];
		c_num=cnts[c];
		ab_num=cnts[gcd(a,b)];
		bc_num=cnts[gcd(b,c)];
		ca_num=cnts[gcd(c,a)];
		abc_num=cnts[gcd(a,gcd(b,c))];

		long long int answer=0;
		vector<int>nums(8);
		nums[1]=a_num-ab_num-ca_num+abc_num;
		nums[2]=b_num-ab_num-bc_num+abc_num;
		nums[4]=c_num-bc_num-ca_num+abc_num;
		nums[3]=ab_num-abc_num;
		nums[5]=ca_num-abc_num;
		nums[6]=bc_num-abc_num;
		nums[7]=abc_num;

		for(auto v:used){
			vector<long long int>muls(3);
			long long int nans=1;
			long long int div=1;
			for (int x = 0; x < 3; ++x) {
				if (x&&v[x] == v[x - 1]) {
					muls[x] = muls[x-1] + 1;
					if(x==2&&v[0]==v[1]&&v[1]==v[2])div*=3;
					else {
						div *= 2;

					}
				}
				else muls[x]=nums[v[x]];
			}
							
			for(auto mul:muls)nans*=mul;
			nans/=div;
			if(nans<0)assert(false);
			answer+=nans;
		}

		printf("%lld\n",answer);
	}
	return 0;
}