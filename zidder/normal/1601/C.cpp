#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 1000007 * 2;

int fenw[2 * N];
int n, m;

void addd(int idx, int d=1){
    for (; idx <= n + m; idx = idx | (idx + 1))
	    fenw[idx] += d;
}

int sm(int r){
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += fenw[r];
    return ret;
}

// i < j and ci > cj
// remove previous inidces
// ci > cj

long long invs = 0;

struct S{
	int ind;
	int lftless=0;
	int rghtgreater=0;
};

S insrt(int v, vector<int> &a, int al, int ar) {
	S s;
	s.ind = al;
	for (int i=al;i<ar;++i){
		if (v < a[i])
			s.rghtgreater++;
	}
	S s1 = s;
	for (int i=al;i<ar;++i){
		s1.ind++;
		if (v > a[i])
			s1.lftless++;
		if (v < a[i])
			s1.rghtgreater--;
		if (s1.lftless + s1.rghtgreater > s.lftless + s.rghtgreater)
			s = s1;
	}
	return s;
}
vector<int> inds;

void merge(vector<int> &b, vector<int> &a,
		   int bl=0, int br=-1,
		   int al=0, int ar=-1){
	if (ar == -1) ar = n;
	if (br == -1) br = m;
	if (bl == br) return;

	int m = (br + bl) / 2;
	int nbr = m, nbl = m+1;

	while (nbr > bl && b[nbr - 1] == b[m])
		nbr--;

	while (nbl < br && b[nbl] == b[m])
		nbl++;

	S s = insrt(b[m], a, al, ar);
	for (int i=nbr;i<nbl;++i){
		inds[i] = s.ind;
	}

	merge(b, a, bl, nbr, al, s.ind);
	merge(b, a, nbl, br, s.ind, ar);
}

void solve(int test_ind){
	cin >> n >> m;
	inds = vector<int>(m);
	for (int i=0; i <= n+m;++i)
		fenw[i] = 0;

	vector<int> a(n), b(m);	
	for (int i=0;i<n;++i)scanf("%d", &a[i]);
	for (int i=0;i<m;++i)scanf("%d", &b[i]);
	sort(b.begin(), b.end());
	set<int> nums;
	for (int i: a) nums.insert(i);
	for (int i: b) nums.insert(i);
	int minind = 1;
	map<int, int> mp;
	for (int num: nums) mp[num] = minind++;

	for (int i=0;i<n;++i) a[i] = mp[a[i]];
	for (int i=0;i<m;++i) b[i] = mp[b[i]];

	merge(b, a);

	vector<int> ab;
	for (int ai=0, bi=0;ai<n||bi<m;){
		if (ai == n){
			ab.push_back(b[bi++]);
			continue;
		}
		if (bi == m){
			ab.push_back(a[ai++]);
			continue;
		}
		if (inds[bi] > ai){
			ab.push_back(a[ai++]);
			continue;
		}
		ab.push_back(b[bi++]);
	}
	invs = 0;
	for (int i: ab) {addd(i);}
	for (int i=0;i<ab.size();++i) {
		invs += sm(ab[i] - 1);
		addd(ab[i], -1);
	}
	cout << invs << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}