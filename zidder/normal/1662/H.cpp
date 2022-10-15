#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> divs(int a) {
	vector<int> smalls = {1};
	vector<int> larges = {a};
	for (int i=2;i*1ll*i<=a;++i) {
		if (a%i==0) {
			smalls.push_back(i);
			larges.push_back(a/i);
		}
	}
	reverse(larges.begin(), larges.end());
	for (int i: larges) {
		if (smalls.back() == i) continue;
		smalls.push_back(i);
	}
	return smalls;
}

void solve(int test_ind){
	int w, l;
	cin >> w >> l;
	// (w - 1) / a, (l - 1) / a
	// (w - 2) / a, l / a
	// w / a, (l - 2) / a


	// w / a, (l - 1) / a, (w - 2) / a
	// l / a, (l - 2) / a, (w - 1) / a
	set<int> a = {1};
	if (l % 2 && w % 2 == 0 || w % 2 && l % 2 == 0) a.insert(2);
	vector<int> w1 = divs(w-1), l1 = divs(l-1), w2 = divs(w-2), l0 = divs(l), w0 = divs(w), l2 = divs(l-2);

	for (int i=0,j=0;i<w1.size() && j < l1.size();){
		if (w1[i] < l1[j]) i++;
		else if (w1[i] > l1[j]) j++;
		else if (w1[i] == l1[j]) {
			a.insert(w1[i]);
			i++;
			j++;
		}
	}
	for (int i=0,j=0;i<w0.size() && j < l2.size();){
		if (w0[i] < l2[j]) i++;
		else if (w0[i] > l2[j]) j++;
		else if (w0[i] == l2[j]) {
			a.insert(w0[i]);
			i++;
			j++;
		}
	}
	for (int i=0,j=0;i<w2.size() && j < l0.size();){
		if (w2[i] < l0[j]) i++;
		else if (w2[i] > l0[j]) j++;
		else if (w2[i] == l0[j]) {
			a.insert(w2[i]);
			i++;
			j++;
		}
	}
	cout << a.size();
	for (int i: a){
		printf(" %d", i);
	}
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}