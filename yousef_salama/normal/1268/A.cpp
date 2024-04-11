#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, k;
char s[MAXN], d[MAXN];

int main(){
	scanf("%d %d %s", &n, &k, s);
	
	printf("%d\n", n);

	for(int i = 0; i < k; i++)
	for(int j = i; j < n; j += k)
		d[j] = s[i];
	
	if(strcmp(s, d) <= 0){
		for(int i = 0; i < k; i++)
		for(int j = i + k; j < n; j += k)
			s[j] = s[i];
		printf("%s\n", s);
	}else{
		for(int i = k - 1; i >= 0; i--){
			if(s[i] == '9'){
				s[i] = '0';
			}else{
				s[i]++;
				break;
			}
		}
		
		for(int i = 0; i < k; i++)
		for(int j = i + k; j < n; j += k)
			s[j] = s[i];
		printf("%s\n", s);
	}
	
	return 0;
}