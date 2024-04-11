#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int t, n, k;
char s[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %s", &n, &k, s);
		
		vector < pair <int, int> > v;
		for(int i = 0; i < n; i++){
			char target;
			if(i < 2 * (k - 1)){
				if(i % 2 == 0)target = '(';
				else target = ')';
			}else{
				if(i - 2 * (k - 1) < (n - 2 * (k - 1)) / 2)target = '(';
				else target = ')';
			}
			
			if(s[i] == target)continue;
			
			int j = i + 1;
			for(; j < n; j++)if(s[j] == target)break;
			
			v.push_back(make_pair(i + 1, j + 1));
			reverse(s + i, s + j + 1);
		}
		
		printf("%d\n", (int)v.size());
		for(pair <int, int> p : v)
			printf("%d %d\n", p.first, p.second);
	}
	return 0;
}