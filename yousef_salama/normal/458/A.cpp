#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100025;

char a[MAXN], b[MAXN];
int n, m, av[MAXN], bv[MAXN];

void findrep(int *v, int l){
	if(l == 1)return;

	if(v[l - 1] == 0)findrep(v, l - 1);
	else{
		if(v[l - 2] == 1){
			v[l] = 1;
			v[l - 1] = 0;
			v[l - 2] = 0;
			findrep(v, l - 1);
		}else{
			findrep(v, l - 1);
			if(v[l - 2] == 1){
				v[l] = 1;
				v[l - 1] = 0;
				v[l - 2] = 0;
			}
		}
	}
}

int main(){
	scanf("%s %s", a, b);

	n = strlen(a);
	m = strlen(b);

	reverse(a, a + n);
	reverse(b, b + m);

	int l = max(n, m) + 5;
	for(int i = 0; i < l; i++){
		if(i < n)av[i] = a[i] - '0';
		else av[i] = 0;

		if(i < m)bv[i] = b[i] - '0';
		else bv[i] = 0;
	}

	findrep(av, l);
	findrep(bv, l);

	for(int i = l - 1; i >= 0; i--){
		if(av[i] > bv[i]){
			printf(">\n");
			return 0;
		}
		if(av[i] < bv[i]){
			printf("<\n");
			return 0;
		}
	}
	printf("=\n");

	return 0;
}