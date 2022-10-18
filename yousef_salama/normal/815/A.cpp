#include <bits/stdc++.h>
using namespace std;

int n, m, ga[105][105], g[105][105];
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		scanf("%d", &g[i][j]);
		ga[i][j] = g[i][j];
	}

	int k = -1;
	vector < pair <int, int> > rows, cols;
	for(int a = 0; a <= 500; a++){
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			g[i][j] = ga[i][j];

		vector < pair <int, int> > cr, cc;
		int ck = 0;

		cr.push_back({1, a});
		ck += a;

		bool ok = true;
		for(int j = 0; j < m; j++){
			if(g[0][j] < a)ok = false;
			else{
				g[0][j] -= a;

				cc.push_back({j + 1, g[0][j]});
				ck += g[0][j];

				for(int i = n - 1; i >= 0; i--){
					if(g[i][j] < g[0][j])ok = false;
					else g[i][j] -= g[0][j];
				}
			}
		}

		if(!ok)continue;

		for(int i = 1; i < n; i++){
			cr.push_back({i + 1, g[i][0]});
			ck += g[i][0];

			for(int j = m - 1; j >= 0; j--){
				if(g[i][j] < g[i][0])ok = false;
				else g[i][j] -= g[i][0];
			}
		}

		if(!ok)continue;

		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(g[i][j] != 0)ok = false;

		if(ok){
			if((k == -1) || (ck < k)){
				k = ck;
				rows = cr;
				cols = cc;
			}
		}
	}

	if(k == -1)printf("-1\n");
	else{
		printf("%d\n", k);
		for(int i = 0; i < rows.size(); i++){
			for(int j = 0; j < rows[i].second; j++)
				printf("row %d\n", rows[i].first);
		}
		for(int i = 0; i < cols.size(); i++){
			for(int j = 0; j < cols[i].second; j++)
				printf("col %d\n", cols[i].first);
		}
	}

	return 0;
}