#include <bits/stdc++.h>
using namespace std;

long long calc(long long a, int m){
	long long x = a / m, r = a % m;
	long long ret = 1LL * (m - r) * x * x + 1LL * r * (x + 1) * (x + 1);
	return ret;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector <int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	long long res = 0;
	for(int i = 0; i < n; i++)
		res += 1LL * a[i] * a[i];
		
	set < pair <long long, int> > s;
	vector <int> c(n, 1);
	
	for(int i = 0; i < n; i++){
		if(a[i] == 1)continue;
		s.insert({calc(a[i], 2) - 1LL * a[i] * a[i], i});
	}
	
	for(int itr = 0; itr < k - n; itr++){
		auto[diff, ind] = *s.begin();
		s.erase(s.begin());
		
		res += diff;
		c[ind]++;
		
		if(c[ind] + 1 <= a[ind]){
			s.insert({calc(a[ind], c[ind] + 1) - calc(a[ind], c[ind]), ind});
		}
	}
	printf("%lld\n", res);
	
	return 0;
}