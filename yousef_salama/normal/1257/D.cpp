#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int t, n, m, a[MAXN];
pair <int, int> h[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
			scanf("%d %d", &h[i].first, &h[i].second);
		sort(h, h + m);
		
		vector < pair <int, int> > v;
		for(int i = 0; i < m; i++){
			while(!v.empty() && v.back().second <= h[i].second)v.pop_back();
			v.push_back(h[i]);
		}
		
		int ans = 0;
		for(int i = 0; i < n; ){
			int j = i, k = (int)v.size() - 1, mx = 0;
			while(j < n){
				mx = max(mx, a[j]);
				
				if(mx > v[k].first)break;
				else if(j - i + 1 > v[k].second){
					if(k > 0 && v[k - 1].first >= mx){
						k--;
						j++;
					}else break;
				}else{
					j++;
				}
			}
			
			if(i == j){
				ans = -1;
				break;
			}
			
			ans++;
			i = j;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}