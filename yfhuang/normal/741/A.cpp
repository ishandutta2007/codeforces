#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int n;

const int maxn = 105;
int f[maxn];
int d[maxn];
bool vis[maxn];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> f[i];
	}
	//int ans = -1;
	int cnt = 0;
	memset(vis,false,sizeof(vis));
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = true;
		int u = i;
		for(int j = 1;j <= n;j++){
			u = f[u];
			//cout << u << endl;
			if(vis[u] == true && u != i){
				printf("-1\n");
				return 0;
			}
			else if(vis[u]){
				d[cnt++] = j;
				break;
			}
			vis[u] = true;
		}
	}
	//for(int i = 0;i < cnt;i++){
	//	cout << d[i] << endl;
	//}
	//for(int i = 0;i < cnt;i++){
	//	if(d[i] & 1){
	//		printf("-1\n");
	long long ans = 1;
	for(int i = 0;i < cnt;i++){
		ans = ans * d[i] / __gcd(ans,(long long)d[i]);
	}
	if(ans & 1) cout << ans << endl;
	else cout << ans / 2 << endl;		
	return 0;
}