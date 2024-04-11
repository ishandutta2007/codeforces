#include <cstdio>
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define N 205

int n, m, k, p, a[7], c[N][N], z[N][N], d[128][N], h[128][N], f[128][N], A = 1 << 29, R;
char o[N];

void fp(int i, int j){
//	o[i] = o[j] = 'X';
	int t = z[i][j];
	if(t < 0) return;
	o[t] = 'X';
	fp(i, t);
	fp(t, j);
}

void trace(int i, int j){
	o[j] = 'X';
	if(h[i][j] >= 0){
		trace(h[i][j], j);
		trace(i ^ h[i][j], j);
	}
	if(f[i][j] >= 0 && f[i][j] != j){
		fp(j, f[i][j]);
		trace(i, f[i][j]);
	}
	return;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	fi(i, 0, n * m) fi(j, 0, n * m) c[i][j] = 1 << 29, z[i][j] = -1;
	fi(i, 0, 1 << k) fi(j, 0, n * m) d[i][j] = 1 << 29, h[i][j] = f[i][j] = -1;
	fi(i, 0, n * m) o[i] = '.';
	
	fi(i, 0, n) fi(j, 0, m){
		scanf("%d", &c[p][p]);
		p++;
	}
	p = 0;
	fi(i, 0, n) fi(j, 0, m){
		if(j < m - 1) c[p][p + 1] = c[p + 1][p] = c[p][p] + c[p + 1][p + 1];
		if(i < n - 1) c[p][p + m] = c[p + m][p] = c[p][p] + c[p + m][p + m];
		p++;
	}
	
	fi(t, 0, p) fi(i, 0, p) fi(j, i + 1, p)
		if(c[i][j] > c[i][t] + c[t][j] - c[t][t])
			c[i][j] = c[j][i] = c[i][t] + c[t][j] - c[t][t], z[i][j] = z[j][i] = t;
	
	fi(i, 0, k){
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = (x - 1) * m + y - 1;
		fi(j, 0, p) d[1 << i][j] = c[a[i]][j], f[1 << i][j] = a[i];
	}
	
	fi(i, 3, 1 << k){
		if((i & -i) == i) continue;
		
		fi(j, 0, p) for(int t = i - 1 & i; t; t = t - 1 & i)
			if(d[i][j] > d[t][j] + d[t ^ i][j] - c[j][j])
				d[i][j] = d[t][j] + d[t ^ i][j] - c[j][j], h[i][j] = t;
		
		fi(j, 0, p) fi(t, 0, p) 
			if(d[i][j] > d[i][t] + c[t][j] - c[t][t])
				d[i][j] = d[i][t] + c[t][j] - c[t][t], f[i][j] = t, h[i][j] = -1;
	}
	
	printf("%d\n", d[(1 << k) - 1][a[0]]);
	trace((1 << k) - 1, a[0]);
	fi(i, 0, p){
		putchar(o[i]);
		if(i % m == m - 1) putchar('\n');
	}
	scanf("\n");
}