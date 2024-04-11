#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 300000 + 5;
int n;
int p[maxn];
char c[maxn];

vector<int> G,R,B;
typedef long long LL;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		char str[3];
		scanf("%d",&p[i]);
		scanf("%s",str);
		c[i] = str[0];
		if(c[i] == 'G') G.push_back(i);
		if(c[i] == 'B') B.push_back(i);
		if(c[i] == 'R') R.push_back(i);
	}

	LL ans = 0;
	if(G.size() == 0){
		if(B.size() > 0) ans += p[B[B.size() - 1]] - p[B[0]];
		if(R.size() > 0) ans += p[R[R.size() - 1]] - p[R[0]];	
	}else{
		if(B.size() > 0){
			if(p[B[0]] < p[G[0]]) ans += p[G[0]] - p[B[0]];
			if(p[B[B.size() - 1]] > p[G[G.size() - 1]]) ans += p[B[B.size() - 1]] - p[G[G.size() - 1]];
		}
		if(R.size() > 0){
			if(p[R[0]] < p[G[0]]) ans += p[G[0]] - p[R[0]];
			if(p[R[R.size() - 1]] > p[G[G.size() - 1]]) ans += p[R[R.size() - 1]] - p[G[G.size() - 1]];
		}
		for(int i = 1;i < G.size();i++){
			int l = G[i - 1],r = G[i];
			LL ans1 = 2LL * (p[r] - p[l]);
			LL ans2 = 3LL * (p[r] - p[l]);

			int tmp = 0;
			for(int j = l + 1,k = l;j <= r;j++){
				if(c[j] == 'R' || c[j] == 'G'){
					tmp = max(tmp,p[j] - p[k]);
					k = j;
				}
			}
			ans2 -= tmp;
			tmp = 0;
			for(int j = l + 1,k = l;j <= r;j++){
				if(c[j] == 'B' || c[j] == 'G'){
					tmp = max(tmp,p[j] - p[k]);
					k = j;
				}
			}
			ans2 -= tmp;
			ans += min(ans1,ans2);
		}
	}
	cout << ans << endl;
	return 0;
}