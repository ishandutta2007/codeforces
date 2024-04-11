#include <bits/stdc++.h>
using namespace std;

void solve(vector < pair <int, int> > &p, int l, int r){
	if(l == r)return;
	
	int mid = (l + r) / 2;
	
	solve(p, l, mid);
	solve(p, mid + 1, r);
	
	for(int i = l; i <= mid; i++)
		p.push_back({i, i + (mid + 1 - l)});
}

int main(){
	int n;
	scanf("%d", &n);
	
	int m = 1;
	while((m << 1) <= n)m <<= 1;
	
	vector < pair <int, int> > p;
	
	solve(p, 0, m - 1);
	if(m != n)solve(p, n - m, n - 1);
	
	printf("%d\n", (int)p.size());
	for(auto tp : p)
		printf("%d %d\n", tp.first + 1, tp.second + 1);
	
	return 0;
}