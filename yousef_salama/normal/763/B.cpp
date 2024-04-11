#include <bits/stdc++.h>
using namespace std;

int n, x1, y1, x2, y2;
int main(){
	scanf("%d", &n);

	printf("YES\n");
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", (abs(x1) % 2) + (abs(y1) % 2) * 2 + 1);
	}
	return 0;
}