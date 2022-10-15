#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

using pii=pair<int, int>;

bool online(pii a, pii b, pii c){
	if (a.first == c.first)
			return a.first == b.first;
	if (a.second == c.second)
			return a.second == b.second;
	return (b.first - a.first) * 1ll * (c.second - a.second) ==
		   (b.second - a.second) * 1ll * (c.first - a.first);
}

long double sq(long double a){return a*a;}

long double dist(pii a, pii b){
	return sqrt(sq(a.first - b.first) + sq(a.second - b.second));
}

long double mmin(long double a, long double b){
	return a<b?a:b;
}

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	k--;
	vector<pii> v(n);
	for (int i=0;i<n;++i)
		scanf("%d%d", &v[i].first, &v[i].second);

	if (n == 3) {
		pii a = v[k];
		v.erase(v.begin() + k);
		long double d1 = dist(v[0], v[1]);
		printf("%.12Lf", mmin(dist(v[0], a), dist(v[1], a)) + d1);
		return;
	}
	
	int out;

	if (!online(v[0], v[1], v[2])){
		if (online(v[1], v[2], v[3])){
			out = 0;
		}
		else if (online(v[1], v[3], v[0])){
			out = 2;
		}
		else
			out = 1;
	}
	else {
		for (int i=3;i<n;++i)
			if (!online(v[0], v[1], v[i])) {
				out = i;
				break;
			}
	}

	pii outpoint = v[out];
	pii kpoint = v[k];

	if (k == out){
    v.erase(v.begin() + k);
    sort(v.begin(), v.end());
		printf("%.12Lf", mmin(dist(v[0], kpoint), dist(v.back(), kpoint)) + dist(v[0], v.back()));
		return;
	}

	int mik = min(k, out), mak = max(k, out);

	v.erase(v.begin() + mak);
	v.erase(v.begin() + mik);

	sort(v.begin(), v.end());

	int gind = v.size();
	for (int i=0;i<v.size();++i){
		if (v[i] > kpoint){
				gind = i;
				break;
		}
	}

	long double Adist = dist(kpoint, v.back()) + dist(v.back(), v[0]);
	if (gind == v.size())
			Adist = dist(kpoint, v[0]);
	if (gind == 0)
			Adist = dist(kpoint, v.back());

	long double Bdist = dist(kpoint, v[0]) + dist(v.back(), v[0]);
	if (gind == v.size())
			Bdist = dist(kpoint, v[0]);
	if (gind == 0)
			Bdist = dist(kpoint, v.back());

	vector<pii> A, B;
	A.push_back(kpoint);
	B.push_back(kpoint);

	for (int i=gind;i<v.size();++i)
		A.push_back(v[i]);
	for (int i=gind-1;i>=0;--i)
		A.push_back(v[i]);

	for (int i=gind-1;i>=0;--i)
		B.push_back(v[i]);
	for (int i=gind;i<v.size();++i)
		B.push_back(v[i]);

	long double d = mmin(Adist + dist(A.back(), outpoint), Bdist + dist(B.back(), outpoint));

	for (int i=1;i<A.size();++i){
		d = mmin(d, Adist + dist(A[i-1], outpoint) + dist(A[i], outpoint) - dist(A[i], A[i-1]));
	}
	
	for (int i=1;i<B.size();++i){
		d = mmin(d, Bdist + dist(B[i-1], outpoint) + dist(B[i], outpoint) - dist(B[i], B[i-1]));
	}

	printf("%.12Lf", d);
}

int main() {
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}