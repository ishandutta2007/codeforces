#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector < pair <int, int> > v(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i].first);
		v[i].second = i;
	}
	sort(v.rbegin(), v.rend());
	
	vector <int> a(n), ind(n);
	for(int i = 0; i < n; i++){
		a[i] = v[i].first;
		ind[i] = v[i].second;
	}
	
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum -= a[i];
	
	int j = 0, cnt = 0;	
	if(n % 3 == 0){
		sum += 2LL * a[0] + 2LL * a[1];
		cnt += (ind[0] % 2 == 0) + (ind[1] % 2 == 0);
		j += 2;
	}else if(n % 3 == 1){
		sum += 2LL * a[0];
		cnt += (ind[0] % 2 == 0);
		j += 1;
	}
	
	if(n == 1){
		printf("%d\n", a[0]);
		return 0;
	}
	
	if(n % 2 == 1){
		long long res = -1LL << 50;
		for(int i = j; i <= n; i += 3){
			if(i == n / 2 + 1 && cnt == n / 2 + 1){
				res = max(res, sum - 2LL * a[i - 1] + 2LL * a[i]);
			}else res = max(res, sum);
			
			if(i + 3 <= n){
				sum += 2LL * a[i] + 2LL * a[i + 1] + 2LL * a[i + 2];
				cnt += (ind[i] % 2 == 0) + (ind[i + 1] % 2 == 0) + (ind[i + 2] % 2 == 0);
			}
		}
		
		printf("%lld\n", res);
		return 0;
	}
	
	long long res = sum;
	
	while(j + 3 <= n){
		sum += 2LL * a[j] + 2LL * a[j + 1] + 2LL * a[j + 2];
		j += 3;
		
		res = max(res, sum);
	}
	
	printf("%lld\n", res);
	
	return 0;
}