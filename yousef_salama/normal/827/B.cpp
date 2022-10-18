#include <bits/stdc++.h>
using namespace std;

int n, k;
int main(){
	scanf("%d %d", &n, &k);

	int d = 2;
	while(true){
		if((n - (d + 1) + (d / 2) - 1) / (d / 2) <= k - 2)break;
		else d++;
	}

	printf("%d\n", d);
	for(int i = 1; i <= d; i++)
		printf("%d %d\n", i, i + 1);

	k -= 2;

	int m = d + 1;
	for(int i = 0; i < k; i++){
		int x = min((n - m) - (k - i - 1), d / 2);

		for(int j = 0; j < x; j++){
			if(j == 0){
				printf("%d %d\n", d / 2 + 1, m + 1);
				m++;
			}else{
				printf("%d %d\n", m, m + 1);
				m++;
			}
		}
	}

	return 0;
}