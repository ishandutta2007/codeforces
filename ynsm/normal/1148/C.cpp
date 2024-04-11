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

int n, p[N], pp[N];
vector< pii > ans;
void gg(int i, int j){
	ans.pb({i, j});
	swap(p[i], p[j]);
	swap(pp[p[i]], pp[p[j]]);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		pp[p[i]] = i;
	}
	for(int i = 1; i <= n / 2; i++){
		int a = i, b = pp[i];
		if(a == b)
			continue;
		if(abs(a - b) >= n / 2){
			gg(a, b);
			continue;
		}
		if(i == 1){
			gg(b, n);
			gg(a, n);
			gg(b, n);
		}
		if(b <= n / 2){
			gg(b, n);
			gg(a, n);
			gg(b, n);
		}else{
			gg(a, n);
			gg(1, b);
			gg(1, n);
			gg(a, n);
			gg(1, b);
		}
	}
    for(int i = n; i > n / 2; i--){
		int a = i, b = pp[i];
		if(a == b)
			continue;
		if(abs(a - b) >= n / 2){
			gg(a, b);
			continue;
		}
		gg(b, 1);
		gg(a, 1);
		gg(b, 1);
	}	
	printf("%d\n", ans.size());
	for(auto it : ans)
		printf("%d %d \n", it.f, it.s);
	return 0;
}