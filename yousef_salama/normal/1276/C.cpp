#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

int n, a[MAXN];
pair <int, int> v[MAXN];
vector <int> r[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	
	int m = 0;
	for(int i = 0; i < n; i++){
		if(m == 0 || v[m - 1].second != a[i]){
			v[m++] = make_pair(1, a[i]);
		}else v[m - 1].first++;
	}
	sort(v, v + m);
	
	int cn = 0, j = 0, x = 0, p = -1, q = -1;
	for(int h = 1; h <= n; h++){
		while(j < m && v[j].first < h)j++;
		cn += m - j;
		
		int w = cn / h;
		if(w >= h && h * w > x){
			x = h * w;
			p = h;
			q = w;
		}
	}
	
	printf("%d\n%d %d\n", x, p, q);
	
	for(int i = 0; i < p; i++)
		r[i].resize(q);
	
	int k = m - 1, c = 0;
	for(int j = 0; j < q; j++)
	for(int i = 0; i < p; i++){
		if(c == min(p, v[k].first)){
			k = k - 1;
			c = 0;
		}
		r[i][(j + i) % q] = v[k].second;
		c = c + 1;
	}
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			if(j > 0)printf(" ");
			printf("%d", r[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}