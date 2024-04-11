
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()


int main() {
	int n, t;
	cin >> n >> t;
	vector<int> NeedTimes;
	for (int i = 0; i < n; ++i) {
		int at;
		cin >> at;
		NeedTimes.push_back(at);
	}
	int maxbook=0;
	int nowbook=0;
	int atime = 0;
	auto fit = NeedTimes.begin();
	auto bit = NeedTimes.begin();
	atime += *NeedTimes.begin();
	while (1) {
		if (bit == NeedTimes.end()) {
			break;
		}
		if (atime > t) {
			if (fit == bit) {
				
				bit++;
				if(bit != NeedTimes.end()) {
					atime += *bit;
				}else {
					break;
				}
				atime -= *fit;
				fit++;
			}
			else {
				nowbook--;
				atime -= *fit;
				fit++;
			}
			
		}
		else {
			nowbook++;
			
			bit++;
			if (bit != NeedTimes.end()) {
				atime += *bit;
			}
			else {
				break;
			}
			
		}
		maxbook = max(nowbook, maxbook);
	}
	maxbook = max(nowbook, maxbook);
	cout <<maxbook<< endl;
	return  0;
}