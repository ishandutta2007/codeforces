#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int t, n, a[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < 2 * n; i++)
			scanf("%d", &a[i]);
			
		int s = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == 1)s++;
			else s--;
		}
		
		map <int, int> mp;
		mp[s] = 0;
		
		for(int i = n - 1; i >= 0; i--){
			if(a[i] == 1)s--;
			else s++;
			
			if(!mp.count(s))mp[s] = n - i;
		}
		
		int res = mp[0] + n;
		
		s = 0;
		for(int i = 0; i < n; i++){
			if(a[2 * n - 1 - i] == 1)s++;
			else s--;
			
			if(mp.count(-s))res = min(res, mp[-s] + n - i - 1);
		}
		
		printf("%d\n", res);
	}
	return 0;
}