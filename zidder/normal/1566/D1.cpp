#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 301;

int T[N][4 * N];
int n, m;

void insert(int row, int col, int l=0, int r=-1, int v=1){
	if (r==-1) r = m;
	if (col >= r) return;
	if (col <= l) {T[row][v]++;return;}
	if (r==l+1)return;
	int mid = (l+r) / 2;
	insert(row, col, l, mid, 2*v);
	insert(row, col, mid, r, 2*v+1);
}

int get(int row, int col, int l=0, int r=-1, int v=1){
	if (r==-1) r=m;
	if (l==r-1) return T[row][v];
	int mid = (l+r) / 2;
	if (mid > col)
		return get(row, col, l, mid, 2*v) + T[row][v];
	else
		return get(row, col, mid, r, 2*v+1) + T[row][v];
}

int end(int col){
	return col / m * m + m - 1;
}

void solve(int test_ind){
	for (int i=0;i<N;++i)
		for (int j=0;j<N*4;++j)
			T[i][j] = 0;
	cin >> n >> m;
	vector<int> a(n*m), b;
	for (int i=0;i<a.size();++i) cin>>a[i];
	b = a;
	sort(b.begin(), b.end());
	map<int, pair<int, int> > lr;
	for (int i = 0;i<b.size();++i){
		if (lr.find(b[i]) == lr.end()){
			lr[b[i]] = make_pair(i, i);
			continue;
		}
		lr[b[i]].second = i;
	}
	
	long long ans = 0;
	for (int i:a){
		int ind = lr[i].first;
		int row = ind / m;
		int col = ind % m;
		ans += get(row, col);
		if (lr[i].second < end(ind)){
			insert(row, col + lr[i].second - lr[i].first);
			lr[i].second--;
		}
		else lr[i].first++;
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}