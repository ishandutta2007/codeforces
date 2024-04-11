#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

int n, c[MAXN], deg[MAXN], cdeg[MAXN], ki, ai;
vector <int> G[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
		c[i]--;
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &ki);
		for(int j = 0; j < ki; j++){
			scanf("%d", &ai);

			G[ai - 1].push_back(i);
			deg[i]++;
		}
	}


	int r = 1 << 20;
	for(int s = 0; s <= 2; s++){
		memcpy(cdeg, deg, sizeof deg);

		int cs = s, m = 0, cr = 0;
		while(true){
			while(true){
				bool found = false;
				for(int i = 0; i < n; i++)if(cdeg[i] == 0 && c[i] == cs){
					cr++;
					m++;
					for(int j : G[i])cdeg[j]--;
					cdeg[i]--;


					found = true;
					break;
				}
				if(!found)break;
			}

			if(m < n){
				cs = (cs + 1) % 3;
				cr++;
			}else break;
		}
		r = min(r, cr);
	}
	printf("%d\n", r);

	return 0;
}