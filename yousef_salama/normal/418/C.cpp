#include <bits/stdc++.h>
using namespace std;

vector <int> construct(int k){
	vector <int> r(k, 1);
	if(k == 1){
		return r;
	}else if(k == 2){
		r[0] = 3;
		r[1] = 4;
		return r;
	}else if(k % 2 == 0){
		r[0] = (k - 1) / 2;
		return r;
	}else{
		r[0] = (k + 1) / 2;
		r[1] = 2;
		return r;
	}
}

int n, m;
int main(){
	scanf("%d %d", &n, &m);

	vector <int> a = construct(n);
	vector <int> b = construct(m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(j > 0)printf(" ");
			printf("%d", a[i] * b[j]);
		}
		printf("\n");
	}

	return 0;
}