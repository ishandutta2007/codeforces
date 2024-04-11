#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, p[MAXN];
int main(){
	scanf("%d", &n);

	vector <int> vx;
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		if(p[i] < 0)p[i] = -p[i];

		vx.push_back(p[i]);
	}

	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

	int r = 0, t = 0;
	for(int i = 0; i < (int)vx.size(); i++){
		int k = 0, c = 0;
		for(int j = 0; j < n; j++){
			if(p[j] < vx[i])k++;
			else if(p[j] == vx[i]){
				r += min(k, t - k);
				c++;
			}
		}
		t += c;
	}
	printf("%d\n", r);

	return 0;
}