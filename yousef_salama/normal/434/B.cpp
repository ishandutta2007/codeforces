#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m, q, g[MAXN][MAXN], U[MAXN][MAXN], D[MAXN][MAXN], L[MAXN][MAXN], R[MAXN][MAXN];

int op, x, y;
int main(){
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		scanf("%d", &g[i][j]);

	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		if(g[i][j] == 0){
			L[i][j] = 0;
			U[i][j] = 0;
	    }else{
			if(j == 0)L[i][j] = 1;
			else L[i][j] = 1 + L[i][j - 1];

			if(i == 0)U[i][j] = 1;
			else U[i][j] = 1 + U[i - 1][j];
		}
	}
	for(int i = n - 1; i >= 0; i--)
	for(int j = m - 1; j >= 0; j--){
		if(g[i][j] == 0){
			R[i][j] = 0;
			D[i][j] = 0;
		}else{
			if(j == m - 1)R[i][j] = 1;
			else R[i][j] = 1 + R[i][j + 1];

			if(i == n - 1)D[i][j] = 1;
			else D[i][j] = 1 + D[i + 1][j];
		}
	}

	while(q--){
		scanf("%d %d %d", &op, &x, &y);
		x--, y--;

		if(op == 1){
			g[x][y] ^= 1;
			for(int i = 0; i < n; i++){
				if(g[i][y] == 0)U[i][y] = 0;
				else if(i == 0)U[i][y] = 1;
				else U[i][y] = 1 + U[i - 1][y];
			}
			for(int i = n - 1; i >= 0; i--){
				if(g[i][y] == 0)D[i][y] = 0;
				else if(i == n - 1)D[i][y] = 1;
				else D[i][y] = 1 + D[i + 1][y];
			}
			for(int j = 0; j < m; j++){
				if(g[x][j] == 0)L[x][j] = 0;
				else if(j == 0)L[x][j] = 1;
				else L[x][j] = 1 + L[x][j - 1];
			}
			for(int j = m - 1; j >= 0; j--){
				if(g[x][j] == 0)R[x][j] = 0;
				else if(j == m - 1)R[x][j] = 1;
				else R[x][j] = 1 + R[x][j + 1];
			}
		}else{
			int res = max(max(U[x][y], D[x][y]), max(L[x][y], R[x][y]));

			int l = y, r = y, h = U[x][y];
			while((l > 0) || (r < m - 1)){
				if(l == 0){
					r++;
					h = min(h, U[x][r]);
				}else if(r == m - 1){
					l--;
					h = min(h, U[x][l]);
				}else{
					if(U[x][l - 1] >= U[x][r + 1]){
						l--;
						h = min(h, U[x][l]);
					}else{
						r++;
						h = min(h, U[x][r]);
					}
				}
				res = max(res, (r - l + 1) * h);
			}
			l = y, r = y, h = D[x][y];
			while((l > 0) || (r < m - 1)){
				if(l == 0){
					r++;
					h = min(h, D[x][r]);
				}else if(r == m - 1){
					l--;
					h = min(h, D[x][l]);
				}else{
					if(D[x][l - 1] >= D[x][r + 1]){
						l--;
						h = min(h, D[x][l]);
					}else{
						r++;
						h = min(h, D[x][r]);
					}
				}
				res = max(res, (r - l + 1) * h);
			}
			l = x, r = x, h = L[x][y];
			while((l > 0) || (r < n - 1)){
				if(l == 0){
					r++;
					h = min(h, L[r][y]);
				}else if(r == n - 1){
					l--;
					h = min(h, L[l][y]);
				}else{
					if(L[l - 1][y] >= L[r + 1][y]){
						l--;
						h = min(h, L[l][y]);
					}else{
						r++;
						h = min(h, L[r][y]);
					}
				}
				res = max(res, (r - l + 1) * h);
			}
			l = x, r = x, h = R[x][y];
			while((l > 0) || (r < n - 1)){
				if(l == 0){
					r++;
					h = min(h, R[r][y]);
				}else if(r == n - 1){
					l--;
					h = min(h, R[l][y]);
				}else{
					if(R[l - 1][y] >= R[r + 1][y]){
						l--;
						h = min(h, R[l][y]);
					}else{
						r++;
						h = min(h, R[r][y]);
					}
				}
				res = max(res, (r - l + 1) * h);
			}

			printf("%d\n", res);
		}

		/*cout << "----------" << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << R[i][j] << ' ';
			cout << endl;
		}
		cout << "----------" << endl;*/
	}

	return 0;
}