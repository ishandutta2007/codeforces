#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> prod(vector<int> &a, vector<int> &b){
	vector<int> c(a.size());
	for (int i=0;i<a.size();++i){
		c[i] = b[a[i]];
	}
	return c;
}

vector<int> binpow(vector<int>& p, int n){
	if (n == 1) return vector<int>(p.begin(), p.end());
	vector<int> p1 = prod(p, p);
	p1 = binpow(p1, n/2);
	if (n%2 == 0) return p1;
	else return prod(p1, p);
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i=0;i<n;++i) scanf("%d", &p[i]);
	for (int i=0;i<n;++i) p[i]--;
	int dc = n - set<int>(p.begin(), p.end()).size();
	vector<int> b(n);
	for (int i=0;i<n;++i) scanf("%d", &b[i]);
	int mx = *max_element(b.begin(), b.end());
	for (int i=0;i<n;++i) b[i]--;
	int l = (mx - n) / dc;
	if (l == 0){
		for (int i=0;i<n;++i){
			printf("%d ", b[i] + 1);
		}
		cout << endl;
		return;
	}
	// l lessons
	// (1..n) need to satisfy in b
	// p ^ l = b
	vector<int> p1 = binpow(p, l);
	// for (int i: p1) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// cout << endl;
	// cout << endl;
	map<int, vector<int> > mp;
	for (int i=0;i<n;++i){
		mp[p1[i]].push_back(i);
	}
	vector<pair<int, int> > v;
	for (int i=0;i<n;++i){
		if (b[i] < n){
			v.emplace_back(b[i], i);
			// b[i] in mp[i];
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	// for (auto &p: v){
	// 	cout << p.first << " " << p.second << endl;;
	// }
	// cout << endl;
	set<int> v1;
	vector<int> a(n, -1);
	for (int i=0;i<n;++i){
		if (v.back().first == i){
			for (int i: mp[v.back().second])
				v1.insert(i);
			int ind = mp[v.back().second].front();
			a[ind] = i;
			v1.erase(ind);
			v.pop_back();
		} else {
			a[*v1.begin()] = i;
			v1.erase(v1.begin());
		}
	}
	for (int i: a) cout << i + 1 << " ";
	cout << endl;
	// b[i] and larger in mp[i]
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}