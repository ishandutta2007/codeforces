#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;
bool vis[maxn];
int n;
int main(){
	for(int i = 0;i <= 1000;i++){
		vis[i * i] = 1;
	}
	cin >> n;
	int ans = -1e6 - 5;
	for(int i = 1;i <= n;i++){
		int a;
		scanf("%d",&a);
		if(a >= 0 && vis[a]) continue;
		ans = max(ans,a);
	}
	cout << ans << endl;
	return 0;
}