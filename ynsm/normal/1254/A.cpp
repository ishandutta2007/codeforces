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

int n, m, k, ans[1000][1000];
char s[1000][1000], id[1000];
int main()
{                   
	for(int i = '0'; i <= '9'; i++)
		id[k++] = i;
	for(int i = 'a'; i <= 'z'; i++)
		id[k++] = i;
	for(int i = 'A'; i <= 'Z'; i++)
		id[k++] = i;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
	    int cnt = 0;
		for(int i = 0; i < n; i++){
			scanf("%s", &s[i]);
			for(int j = 0; j < m; j++)
				if(s[i][j] == 'R')
					cnt++;
		}
		int a, b, ca, cb;
		queue< int > q;
		a = cnt / k + 1;
		ca = cnt % k;
		b = cnt / k;
		cb = k - ca;   
		while(ca--)
			q.push(a);
		while(cb--)
			q.push(b);
		int cur = 0;
		int c = 0;
		for(int i = 0; i < n; i++){
			if(i & 1){
				for(int j = 0; j < m; j++){
					if(s[i][j] == '.'){
						ans[i][j] = c;
						continue;
					}	
					cur++;
					ans[i][j] = c;
					if(q.size() > 1 && cur == q.front()){
						q.pop();
						cur = 0;
						c++;
					}
				}
			}else{
				for(int j = m - 1; j >= 0; j--){
					if(s[i][j] == '.'){
						ans[i][j] = c;
						continue;
					}	
					cur++;
					ans[i][j] = c;
					if(q.size() > 1 && cur == q.front()){
						q.pop();
						cur = 0;
						c++;
					}
				}
			}
		}	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				printf("%c", id[ans[i][j]]);
			printf("\n");
		}
	}
	return 0;
}