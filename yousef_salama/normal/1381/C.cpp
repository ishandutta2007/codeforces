#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int t, n, x, y, b[MAXN];
vector <int> c[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &x, &y);
		
		for(int i = 0; i <= n; i++)
			c[i].clear();
		for(int i = 0; i < n; i++){
			scanf("%d", &b[i]);
			b[i]--;
			
			c[b[i]].push_back(i);
		}
		
		int m = n - x;
		y = n - y;
		
		int rem = m;
		vector < pair <int, int> > v;
		
		int emp = -1;
		for(int i = 0; i <= n; i++){
			int k = min(rem, min((int)c[i].size(), (m + y) / 2));
			rem -= k;
			
			if(k == 0){
				emp = i;
			}
			
			for(int j = 0; j < k; j++)
				v.push_back(make_pair(i, c[i][j]));
		}
		
		if(rem > 0){
			printf("NO\n");
			continue;
		}
		
		sort(v.begin(), v.end());
		
		for(int i = m - 1; i >= 0; i--){
			if(b[v[i].second] == v[(i + m / 2) % m].first && y > 0){
				v[(i + m / 2) % m].first = emp;
				y--;
			}
		}
		
		for(int i = 0; i < (int)v.size(); i++){
			b[v[i].second] = v[(i + m / 2) % m].first;
		}
		
		for(int i = 0; i < (int)v.size() && y > 0; i++){
			if(b[v[i].second] != emp){
				b[v[i].second] = emp;
				y--;
			}
		}
		
		
		printf("YES\n");
		for(int i = 0; i < n; i++){
			if(i > 0)printf(" ");
			printf("%d", b[i] + 1);
		}
		printf("\n");
	}
	return 0;
}