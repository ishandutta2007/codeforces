#include <bits/stdc++.h>
using namespace std;

int n, q;
char a[40][2], b[40];

char s[10], r[10];
bool check(){
	memcpy(r, s, sizeof s);

	for(int i = 0; i < n - 1; i++){
		bool found = false;
		for(int j = 0; j < q; j++){
			if(a[j][0] == r[i] && a[j][1] == r[i + 1]){
				r[i + 1] = b[j];

				found = true;
				break;
			}
		}
		if(!found)return false;
	}
	if(r[n - 1] == 'a')return true;
	else return false;
}
int gen(int i){
	if(i == n)return check();

	int r = 0;
	for(char c = 'a'; c <= 'f'; c++){
		s[i] = c;
		r += gen(i + 1);
	}
	return r;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 0; i < q; i++)
		scanf("%s %c", a[i], &b[i]);
	printf("%d\n", gen(0));

	return 0;
}