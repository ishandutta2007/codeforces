#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int solve(vector<int>&v,int k) {
	vector<long long int>l_sums(v.size()+1),r_sums(v.size());
	for (int i = 0; i < v.size(); ++i) {
		l_sums[i+1]=l_sums[i]+v[i];
	}
	long long int sum=0;
	long long int minus=0;
	vector<long long int>nums(v.size()+1);
	for (int i = v.size()-1; i >= 0; --i) {
		r_sums[i]=sum;
		sum+=min(v[i],i+1);
		if (v[i] >= i+1) {
			nums[i+1]++;
		}
		else {
			nums[v[i]]++;
		}
		minus+=nums[i+1];
		sum-=minus;
	}

	for (int i = 0; i < v.size(); ++i) {
		long long int l=l_sums[i+1];
		long long int r=r_sums[i]+(i+1)*static_cast<long long int>(i);
		if(l<=r)continue;
		else {
			//too big
			if(i<k)return -1;
			else return 1;
		}
	}
	return 0;
}

int main()
{
	int N;cin>>N;
	vector<int>v(N);
	for (int i = 0; i < N; ++i) {
		cin>>v[i];
	}
	sort(v.begin(),v.end(),greater<int>());

	int al,ar;
	{
		int amin=-1;
		int amax=N+1;

		while (amin+1!=amax) {
			int amid((amin+amax)/2);
			int k;
			{
				auto it=lower_bound(v.begin(),v.end(),amid,greater<int>());
				k=it-v.begin();
				v.insert(it,amid);
			}
			int res=solve(v,k);
			if (res >= 0) {
				amax=amid;
			}
			else {
				amin=amid;
			}
			v.erase(v.begin()+k);
		}
		al=amax;
	}
	{
		int amin = -1;

		int amax = N + 1;

		while (amin+1!=amax) {
			int amid((amin + amax) / 2);
			int k;
			{
				auto it = lower_bound(v.begin(), v.end(), amid, greater<int>());
				k = it - v.begin();
				v.insert(it, amid);
			}
			int res = solve(v, k);
			if (res > 0) {
				amax = amid;
			}
			else {
				amin = amid;
			}
			v.erase(v.begin()+k);
		}
		ar = amin;
	}
	vector<int>anss(ar-al+1);
	iota(anss.begin(),anss.end(),al);
	long long int total=accumulate(v.begin(),v.end(),0ll);
	{
		vector<int>next_anss;
		for (auto ans : anss) {
			if (total % 2) {
				if(ans%2)next_anss.push_back(ans);
			}
			else {
				if(ans%2==0)next_anss.push_back(ans);
			}
		}
		anss=next_anss;
	}
	if (anss.empty()) {
		cout<<-1<<endl;
	}
	else {


		for (int i = 0; i < anss.size(); ++i) {
			printf("%d", anss[i]);
			if (i == anss.size() - 1)cout << endl;
			else printf(" ");
		}
	}
	return 0;
}