#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], b[N], c[N], p[N], q[N], was[N];
bool cmp(int i, int j){
	return a[i] < a[j] ||(a[i] == a[j] && b[i] < b[j]) || (a[i] == a[j] && b[i] == b[j] && c[i] < c[j]);
}
void add(int i, int j){
	was[i] = was[j] = 1;
	printf("%d %d\n", i + 1, j + 1);
}
void flex(){
	int k = 0;
	for(int i = 0; i < n; i++)
		if(!was[p[i]])
			q[k++] = p[i];
	n = k;
	for(int i = 0; i < n; i++)
		p[i] = q[i];
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		p[i] = i;
	}
	sort(p, p + n, cmp);
	for(int i = 0, j = 0; i < n; i = j){
		while(j < n && a[p[i]] == a[p[j]] && b[p[i]] == b[p[j]])
			j++;
		for(int q = 0; i + q  + 1 < j; q += 2)
			add(p[i + q], p[i + q + 1]); 	
	}	
	flex();
	for(int i = 0, j = 0; i < n; i = j){
		while(j < n && a[p[i]] == a[p[j]])
			j++;
		for(int q = 0; i + q  + 1 < j; q += 2)
			add(p[i + q], p[i + q + 1]); 	
	}	
	flex();
    for(int i = 0, j = 0; i < n; i = j){
		while(j < n)
			j++;
		for(int q = 0; i + q  + 1 < j; q += 2)
			add(p[i + q], p[i + q + 1]); 	
	}	
    return 0;
}