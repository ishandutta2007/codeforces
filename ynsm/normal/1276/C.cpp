#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 800500;

int n, a[N], b[N], v[N], cnt[N], c[N], id[N];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		if(i == 0 || a[i] != a[i - 1])
			b[i] = i;
		else
			b[i] = b[i - 1];
	for(int i = 0; i < n; i++){
		v[cnt[b[i]]]++;
		cnt[b[i]]++;
	}
	int s = n;
	pair<int, pii> ans = {-1,{0, 0}};
	for(int a = n; a >= 1; a--){
		s -= v[a];
		int b = s / a;
		if(b >= a)
			ans = max(ans, {a * b, {a, b}});					
	}
	int A = ans.s.f;
	int B = ans.s.s;
	int k = 0;
	int kk = 0;
	for(int j = 0; j < B; j++){
		for(int i = 0; i < A; i++)
			id[kk++] = i * B + (j + i) % B;
	}
	vector< pii > v;
	for(int i = 0, j = 0; i < n; i = j){
		while(j < n && a[i] == a[j])
			j++;	
		if(j - i >= A){
			for(int q = 0; q < A; q++)
				c[id[k++]] = a[i];	
		}else		
			v.pb({j - i, a[i]});
	} 
	for(auto it : v)
		for(int i = 0; i < it.f; i++)
			c[id[k++]] = it.s;
	printf("%d\n%d %d\n", ans.f, ans.s.f, ans.s.s);
	for(int i = 0; i < A; i++){
		for(int j = 0; j < B; j++)
			printf("%d ", c[i * B + j]);
		printf("\n");
	}
	return 0;
}