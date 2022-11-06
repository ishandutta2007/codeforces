#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

namespace FastFourierTransform
{
	using C = complex< double >;

	void DiscreteFourierTransform(vector< C > &F, bool rev)
	{
		const int N = (int)F.size();
		const double PI = (rev ? -1 : 1) * acos(-1);
		for (int i = 0, j = 1; j + 1 < N; j++) {
			int k=N>>1;
			for (; k > (i ^= k); k >>= 1);
			if (i > j) {
				swap(F[i], F[j]);
			}
		}
		C w, s, t;
		for (int i = 1; i < N; i <<= 1) {
			for (int k = 0; k < i; k++) {
				w = polar(1.0, PI / i * k);
				for (int j = 0; j < N; j += i * 2) {
					s = F[j + k];
					t = C(F[j + k + i].real() * w.real() - F[j + k + i].imag() * w.imag(),
						F[j + k + i].real() * w.imag() + F[j + k + i].imag() * w.real());
					F[j + k] = s + t, F[j + k + i] = s - t;
				}
			}
		}
		if (rev) for (int i = 0; i < N; i++) F[i] /= N;
	}

	vector< long long > Multiply(const vector<long long int > &A, const vector<long long int > &B)
	{
		int sz = 1;
		while (sz <= A.size() + B.size()) sz <<= 1;
		vector< C > F(sz), G(sz);
		for (int i = 0; i < A.size(); i++) F[i] = A[i];
		for (int i = 0; i < B.size(); i++) G[i] = B[i];
		DiscreteFourierTransform(F, false);
		DiscreteFourierTransform(G, false);
		for (int i = 0; i < sz; i++) F[i] *= G[i];
		DiscreteFourierTransform(F, true);
		vector< long long > X(A.size() + B.size() - 1);
		for (int i = 0; i < A.size() + B.size() - 1; i++) X[i] = F[i].real() + 0.5;
		return (X);
	}
};

long long int comb(long long int a, long long int k) {
	if(k==0)return 1;
	if(k==a)return 1;
	return comb(a-1,k-1)+comb(a-1,k);
}

long long int solve(int k,const vector<int>&v,vector< int>nums, const int now) {
	if (now == 10) {
		long long int ans=1;
		int sum=accumulate(nums.begin(),nums.end(),0);
		int rest=sum;
		for (int i = 0; i < 10; ++i) {
			if (nums[i]) {
				ans*=comb(rest,nums[i]);
				rest-=nums[i];
			}
		}
		if (nums[0]) {
			long long int nans=1;
			int rest=sum-1;
			for (int i = 0; i < 10; ++i) {
				if (nums[i]) {
					if(i==0)nans*=comb(rest,nums[i]-1);
					else nans*=comb(rest,nums[i]);

					if(i==0)rest-=nums[i]-1;
					else rest-=nums[i];
				}
			}
			ans-=nans;
		}
		return ans;
	}
	else {
		if (v[now]) {
			long long int ans=0;

			for (int x = 1; x <= v[now];++x) {
				nums[now]=x;
				ans += solve(k, v, nums, now + 1);
			}
			return ans;
		}
		else {
			nums[now]=0;
			return solve(k,v,nums,now+1);
		}
	}
}

int main()
{
	string st;cin>>st;
	vector<int>v(10);
	for (auto ch : st) {
		v[ch-'0']++;
	}
	vector<int>nums(10);
	long long int ans=solve(10,v,nums,0);
	cout<<ans<<endl;
	return 0;
}