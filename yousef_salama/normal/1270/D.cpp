#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n, k, pos, apos;
int main(){
	scanf("%d %d", &n, &k);
	
	map <int, int> mp;
	for(int i = 1; i <= k + 1; i++){
		printf("?");
		for(int j = 1; j <= k + 1; j++)
			if(i != j)printf(" %d", j);
		printf("\n");
		fflush(stdout);
		
		scanf("%d %d", &pos, &apos);
		mp[apos]++;
	}
	
	printf("! %d\n", next(mp.begin())->second);
	
	return 0;
}