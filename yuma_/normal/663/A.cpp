#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


int main() {
	vector<string>sts;
	while (1) {
		string st; cin >> st;
		sts.push_back(st);
		if (isdigit(st[0]))break;
	}
	int ans = stoi(sts.back());
	vector<bool>isplus(sts.size() / 2);
	isplus[0] = true;
	vector<string>newsts;
	for (int i = 0; i < sts.size() / 2-1; ++i) {
		assert(sts[2 * i] == "?");
		if (sts[2 * i + 1][0] == '+')isplus[i + 1] = true;
		else isplus[i + 1] = false;
	}
	int plusnumsize = count(isplus.begin(), isplus.end(), true);
	int minusnumsize = isplus.size() - plusnumsize;
	vector<int>plusnums(plusnumsize);
	vector<int>minusnums(minusnumsize);
	/*if (minusnumsize ==0) {
		if (ans < plusnumsize) {

		}
		else {
			plusnums[0] = ans - plusnumsize + 1;
			for (int i = 1; i < plusnums.size(); ++i) {
				plusnums[i] = 1;
			}
		}
	}
	else */
	bool ok = true;
	{
		if (plusnumsize*ans - minusnumsize < ans) {
			ok = false;
		}
		else if(plusnumsize-minusnumsize*ans>ans){
			ok = false;
		}
		else {
			if (plusnumsize*ans - minusnumsize*ans<=ans) {
				for (int i = 0; i < plusnums.size(); ++i) {
					plusnums[i] = ans;
				}
				int rest = ans - (plusnumsize*ans - minusnumsize*ans);
				for (int i = 0; i < minusnums.size(); ++i) {
					minusnums[i] = ans;
					if (rest >= ans - 1) {
						rest -= ans - 1 ;
						minusnums[i] -= ans - 1;
					}
					else if (rest) {
						minusnums[i] -= rest;
						rest = 0;
					}
				}
			}
			else if (plusnumsize*ans - minusnumsize*ans >= ans) {
				for (int i = 0; i < minusnums.size(); ++i) {
					minusnums[i] = ans;
				}
				int rest = -(ans - (plusnumsize*ans - minusnumsize*ans));
				for (int i = 0; i < plusnums.size(); ++i) {
					plusnums[i] = ans;
					if (rest >= ans - 1) {
						rest -= ans - 1;
						plusnums[i] -= ans - 1;
					}
					else if (rest) {
						plusnums[i] -= rest;
						rest = 0;
					}
				}
			}
		}
	}
	if (!ok) {
		cout << "Impossible" << endl;
	}
	else {
		cout << "Possible" << endl;
		auto pit = plusnums.begin();
		auto mit = minusnums.begin();
		cout << *pit ;
		pit++;
		for (int i = 1; i < isplus.size(); ++i) {
			if (isplus[i]) {
				cout << " + " << *pit; pit++;
			}
			else {
				cout << " - " << *mit; mit++;
			}
		}
		cout << " = " << ans << endl;
	}
	return 0;
}