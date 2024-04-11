#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, k, ct, trie[MAXN][26], dpN[MAXN], dpM[MAXN];
char s[MAXN];

struct matrix{
	int A[2][2];
};

matrix operator *(matrix a, matrix b){
	matrix c;
	memset(c.A, 0, sizeof c.A);

	for(int k = 0; k < 2; k++)
	for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
		c.A[i][j] |= a.A[i][k] && b.A[k][j];
	return c;
}
matrix mpow(matrix a, int p){
	if(p == 0){
		matrix c;
		c.A[0][0] = 1; c.A[0][1] = 0;
		c.A[1][0] = 0; c.A[1][1] = 1;
		return c;
	}else if(p % 2 == 1)return (a * mpow(a, p - 1));
	else{
		matrix r = mpow(a, p / 2);
		return r * r;
	}
}

int calcN(int r){
    if(dpN[r] != -1)return dpN[r];

    int A = 0;
    for(int c = 0; c < 26; c++)if(trie[r][c] != -1)
        A |= !calcN(trie[r][c]);
    return dpN[r] = A;
}
int calcM(int r){
    if(dpM[r] != -1)return dpM[r];

    bool ok = true;
    int B = 0;

    for(int c = 0; c < 26; c++)if(trie[r][c] != -1){
        ok = false;
        B |= !calcM(trie[r][c]);
    }
    return dpM[r] = (B || ok);
}
int main(){
    scanf("%d %d", &n, &k);

    memset(trie[ct], -1, sizeof trie[ct]);
    ct++;

    for(int i = 0; i < n; i++){
        scanf("%s", s);

        int r = 0;
        for(int j = 0; s[j]; j++){
            if(trie[r][s[j] - 'a'] == -1){
                memset(trie[ct], -1, sizeof trie[ct]);
                trie[r][s[j] - 'a'] = ct++;
            }
            r = trie[r][s[j] - 'a'];
        }
    }

    memset(dpN, -1, sizeof dpN);
    memset(dpM, -1, sizeof dpM);

    int A = calcN(0);
    int B = calcM(0);

    matrix T;
    T.A[0][0] = B; T.A[0][1] = A;
    T.A[1][0] = !B; T.A[1][1] = !A;

    if(mpow(T, k).A[0][1])printf("First\n");
    else printf("Second\n");

    return 0;
}