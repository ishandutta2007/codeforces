#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

char s[MAXN];
int N;

int main(){
	scanf("%s", s);
	N = strlen(s);
	
	if(N == 1){
		printf("0\n");
		return 0;
	}
	
	bool flag = true;
	for(int i = 1; i < N; i++)
		if(s[i] != '0')flag = false;
	if(N % 2 == 0)flag = false;
	
	printf("%d\n", (N + 1) / 2 - flag);
	
	return 0;
}