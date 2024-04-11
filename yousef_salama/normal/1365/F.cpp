#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int t, n, a[MAXN], b[MAXN];
map < pair <int, int>, int> mp;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		
		if(n % 2 == 1 && a[n / 2] != b[n / 2]){
			printf("No\n");
			continue;
		}
		
		mp.clear();
		for(int i = 0; i < n / 2; i++){
			if(a[i] > a[n - i - 1])swap(a[i], a[n - i - 1]);
			mp[make_pair(a[i], a[n - i - 1])]++;
		}
		
		bool ok = true;
		for(int i = 0; i < n / 2; i++){
			if(b[i] > b[n - i - 1])swap(b[i], b[n - i - 1]);
			
			if(mp[make_pair(b[i], b[n - i - 1])] == 0){
				ok = false;
				break;
			}
			mp[make_pair(b[i], b[n - i - 1])]--;
		}
		
		if(ok)printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}