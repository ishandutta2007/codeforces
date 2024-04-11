#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<int,int> mp;

const int maxn = 5005;

int n,k;
int a[maxn];
int x[maxn];

int main(){
	cin >> n >> k;
	mp.clear();
	for(int i = 1;i <= n;i++){
		scanf("%d",a + i);
	}
	int q;
	cin >> q;
	for(int i = 1;i <= q;i++){
		int ans = 21;
		scanf("%d",&x[i]);
		mp.clear();
		for(int j = 1;j <= n;j++){
			if(x[i] % a[j] == 0){
				ans = min(ans,x[i] / a[j]);
			}
		}
		for(int j = 1;j <= n;j++){
			for(int l = 1;l <= k;l++){
				if(mp.count(x[i] - l * a[j])){
					ans = min(ans,l + mp[x[i] - l * a[j]]);
				}
			}for(int l = 1;l <= k;l++){
				mp[a[j] * l] = l;
			}
		}
		if(ans <= k) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}