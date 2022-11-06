#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


int main()
{
	int Q;cin>>Q;

	vector<long long int>sums(31);
	vector<multiset<int>>sets(31);
	vector<int>ok_nums(31);

	while (Q--) {
		char ch;
		int b;
		scanf(" %c %d",&ch,&b);
		long long int a=b;
		int place=0;
		{
			int rest=a;
			while (rest) {
				place++;
				rest/=2;
			}
		}
		if (ch == '+') {
			sets[place].insert(a);
			if (sums[place - 1] * 2 < *sets[place].begin()) {
				ok_nums[place]=sets[place].size()-1;
			}
			else {
				ok_nums[place] = sets[place].size();

			}
			

			sums[place]+=a;
			for (int k = place + 1; k <= 30; ++k) {
				if (sets[k].size() >=1) {
					if (sums[k - 1] * 2 < (*sets[k].begin())) {
						ok_nums[k]=sets[k].size()-1;
					}
					else {
						ok_nums[k]=sets[k].size();
					}
				}
				sums[k]+=a;
			}
		}
		else {
			sets[place].erase(sets[place].find(a));
			if (sets[place].size()) {
				if (sums[place - 1] * 2 < (*sets[place].begin())) {
					ok_nums[place] = sets[place].size() - 1;

				}
				else {
					ok_nums[place] = sets[place].size();
				}
			}
			else {
				ok_nums[place]=0;
			}
			
			sums[place] -= a;
			for (int k = place + 1; k <= 30; ++k) {
				if (sets[k].size()) {
					if (sums[k - 1] * 2 < (*sets[k].begin())) {
						ok_nums[k] = sets[k].size()-1;
					}
					else {
						ok_nums[k] = sets[k].size();
					}
				}
				sums[k] -= a;
			}
		}

		int answer = accumulate(ok_nums.begin(), ok_nums.end(), 0);
		printf("%d\n", answer);
	}
	return 0;
}