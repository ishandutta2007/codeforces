#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, m;
char s[1000][1000];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		vector< pair<int, int> > ans;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%s", &s[i]);
		for(int i = n - 1; i > 1; i--){
			for(int j = m - 1; j >= 0; j--){
				if(s[i][j] == '1'){
					ans.pb({i, j});    
					ans.pb({i - 1, j});    
					if(j)
						ans.pb({i - 1, j - 1});
					else
						ans.pb({i - 1, j + 1});
					for(int i = 0; i < 3; i++)
						s[ans[ans.size() - 1 - i].f][ans[ans.size() - 1 - i].s] ^= 1;
		    	}
			}
		}
		for(int j = m - 1; j > 1; j--){
			if(s[0][j] == '1'){
				ans.pb({0, j});
				ans.pb({0, j - 1});
				ans.pb({1, j - 1});
				for(int i = 0; i < 3; i++)
					s[ans[ans.size() - 1 - i].f][ans[ans.size() - 1 - i].s] ^= 1;
		    }
			if(s[1][j] == '1'){
				ans.pb({1, j});
				ans.pb({0, j - 1});
				ans.pb({1, j - 1});
				for(int i = 0; i < 3; i++)
					s[ans[ans.size() - 1 - i].f][ans[ans.size() - 1 - i].s] ^= 1;
			}
		}	
		while(true){
			int cnt = 0;
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++)
					if(s[i][j] == '1')
						cnt++;
			if(cnt == 0)
				break;
			if(cnt == 1){
				int c = 0;
				for(int i = 0; i < 2; i++)
					for(int j = 0; j < 2; j++)
			    		if(s[i][j] == '1')
				    		ans.pb({i, j});
				for(int i = 0; i < 2; i++)
					for(int j = 0; j < 2; j++)
			    		if(s[i][j] == '0' && ans.size() % 3)
			    			ans.pb({i, j});
			}
			if(cnt == 2){
				int c = 0;
				for(int i = 0; i < 2; i++){
					for(int j = 0; j < 2; j++)
			    		if(s[i][j] == '1'){
				    		ans.pb({i, j});
				    		break;
				    	}
					if(ans.size() % 3)
						break;
				}
				for(int i = 0; i < 2; i++)
					for(int j = 0; j < 2; j++)
			    		if(s[i][j] == '0' && ans.size() % 3)
			    			ans.pb({i, j});
			}
			if(cnt == 3){
				int c = 0;
				for(int i = 0; i < 2; i++)
					for(int j = 0; j < 2; j++)
			    		if(s[i][j] == '1')
				    		ans.pb({i, j});
			}
			if(cnt == 4){      
				ans.pb({0, 0});
				ans.pb({0, 1});
				ans.pb({1, 1});
			}
			for(int i = 0; i < 3; i++)
				s[ans[ans.size() - 1 - i].f][ans[ans.size() - 1 - i].s] ^= 1;
		}
		printf("%d\n", ans.size() / 3);
		for(int i = 0; i < ans.size(); i += 3){
			for(int j = 0; j < 3; j++)
				printf("%d %d ", ans[i + j].f + 1, ans[i + j].s + 1);
			printf("\n");
		}
	}
}