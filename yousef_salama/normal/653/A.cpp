#include <bits/stdc++.h>
using namespace std;

int n, t[55];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);

	for(int i = 0; i < n; i++)
	for(int j = i + 1; j < n; j++)
	for(int k = j + 1; k < n; k++){
		if(t[i] == t[j] || t[j] == t[k] || t[i] == t[k])continue;
		if(abs(t[i] - t[j]) > 2)continue;
		if(abs(t[i] - t[k]) > 2)continue;
		if(abs(t[j] - t[k]) > 2)continue;

		printf("YES\n");
		return 0;
	}

	printf("NO\n");
	return 0;
}