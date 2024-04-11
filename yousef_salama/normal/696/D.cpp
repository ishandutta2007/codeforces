#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

int n, a[MAXN];
char s[MAXN];
long long l;

int M, trie[MAXN][26], parent[MAXN], last[MAXN], fail[MAXN], go[MAXN][26], c[MAXN];

int ffail(int i);
int fgo(int i, int j);

int ffail(int i){
	if(fail[i] != -1)return fail[i];

	if(parent[i] == -1 || parent[i] == 0)return fail[i] = 0;
	else return fail[i] = fgo(ffail(parent[i]), last[i]);
}
int fgo(int i, int j){
	if(go[i][j] != -1)return go[i][j];

	if(trie[i][j] != -1)return go[i][j] = trie[i][j];
	else{
		if(i == 0)return go[i][j] = 0;
		else return go[i][j] = fgo(ffail(i), j);
	}
}
void bfs(){
    queue <int> q;
    q.push(0);
    
    while(!q.empty()){
        int r = q.front();
        q.pop();
        
        c[r] += c[ffail(r)];
        for(int j = 0; j < 26; j++)
            if(trie[r][j] != -1)q.push(trie[r][j]);
    }
}

struct matrix{
	long long A[MAXN][MAXN];
};

matrix operator *(matrix a, matrix b){
	matrix C;
	memset(C.A, -1, sizeof C.A);

	for(int i = 0; i < M; i++)
	for(int j = 0; j < M; j++)
	for(int k = 0; k < M; k++){
		if(a.A[i][k] == -1 || b.A[k][j] == -1)continue;
		C.A[i][j] = max(C.A[i][j], a.A[i][k] + b.A[k][j]);
	}
	return C;
}
matrix mpow(matrix a, long long p){
	if(p == 0){
		matrix C;
		for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++){
			if(i == j)C.A[i][j] = 0;
			else C.A[i][j] = -1;
		}
		return C;
	}else if(p % 2 == 1)return a * mpow(a, p - 1);
	else{
		matrix r = mpow(a, p / 2);
		return r * r;
	}
}

int main(){
	scanf("%d %I64d", &n, &l);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	memset(trie[0], -1, sizeof trie[0]);
	parent[0] = -1;
	last[0] = -1;
	M = 1;

	for(int i = 0; i < n; i++){
		scanf("%s", s);

		int r = 0;
		for(int j = 0; s[j]; j++){
			if(trie[r][s[j] - 'a'] == -1){
				memset(trie[M], -1, sizeof trie[M]);
				parent[M] = r;
				last[M] = s[j] - 'a';
				trie[r][s[j] - 'a'] = M++;
			}
			r = trie[r][s[j] - 'a'];
		}
		c[r] += a[i];
	}
	
	/*for(int i = 0; i < M; i++){
	    cout << parent[i] << ',' << last[i] << ',' << ffail(i) << ',' << c[i] << ' ';
	}
	cout << endl;*/

	memset(fail, -1, sizeof fail);
	memset(go, -1, sizeof go);

    bfs();

	matrix T;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++)
			T.A[i][j] = -1;
		for(int j = 0; j < 26; j++){
			int k = fgo(i, j);
			T.A[i][k] = max(T.A[i][k], (long long)c[k]);
		}
	}
	T.A[0][0] = 0;

	T = mpow(T, l);

	long long res = 0;
	for(int i = 0; i < M; i++)
		res = max(res, T.A[0][i]);
	printf("%I64d\n", res);

	return 0;
}