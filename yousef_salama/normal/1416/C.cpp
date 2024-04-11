#include <bits/stdc++.h>
using namespace std;

long long r[30][2];

void solve(const vector <int>& a, int bit){
	if(a.empty())return;
	
	vector <int> a0, a1;
	
	for(auto x : a){
		if(x & (1 << bit)){
			r[bit][1] += (int)a0.size();
			a1.push_back(x);
		}else{
			r[bit][0] += (int)a1.size();
			a0.push_back(x);
		}
	}
	
	if(bit > 0){
		solve(a0, bit - 1);
		solve(a1, bit - 1);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	vector <int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	solve(a, 29);
	
	int x = 0;
	long long b = 0;
	
	for(int i = 29; i >= 0; i--){
		if(r[i][0] <= r[i][1]){
			b += r[i][0];
		}else{
			x |= (1 << i);
			b += r[i][1];
		}
	}
	
	printf("%lld %d\n", b, x);
	
	return 0;
}