#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500;

int n, m, a[N];
bool check(int k){
	int last = 0;
	for(int i = 0; i < n; i++){
		if(a[i] + k < m){
			if(a[i] + k < last)
				return 0;
			last = max(last, a[i]);
		}else{
			if((a[i] + k) % m < last)
				last = max(last, a[i]);
		} 
	}
	return 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = 0, r = m + 50;
	while(l <= r){
		int m = (l + r) >> 1;
		if(check(m))
			r = m - 1;
		else
			l = m + 1;
	}
	printf("%d", l);
	return 0;
}