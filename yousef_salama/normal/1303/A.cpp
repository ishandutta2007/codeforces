#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int t;
char s[MAXN];
bool a[MAXN], b[MAXN];

int main(){
	scanf("%d", &t);
	
	while(t--){
		scanf("%s", s);
		int n = strlen(s);
		
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		
		for(int i = 0; i < n; i++){
			if(s[i] == '1')a[i] = true;
			if(i > 0)a[i] |= a[i - 1];
		}
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == '1')b[i] = true;
			if(i < n - 1)b[i] |= b[i + 1];
		}
		
		int res = 0;
		for(int i = 0; i < n; i++)
			if(s[i] == '0' && a[i] && b[i])res++;
		printf("%d\n", res);
	}
	return 0;
}