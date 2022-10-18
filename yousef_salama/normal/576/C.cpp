#include <bits/stdc++.h>
using namespace std;


int n, xi, yi;
vector < pair <int, int> > b[1005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &xi, &yi);
		b[xi / 1000].push_back({yi, i + 1});
	}

	int f = 1;
	for(int i = 0; i < 1005; i++){
		if(i % 2 == 0)sort(b[i].begin(), b[i].end());
		else sort(b[i].rbegin(), b[i].rend());

		for(pair <int, int> p : b[i]){
			if(f)f = 0;
			else printf(" ");

			printf("%d", p.second);
		}
	}
	printf("\n");

	return 0;
}