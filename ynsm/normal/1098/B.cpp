#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9;
const ll INF = 1e18;
const char mt[] = {'A', 'G', 'C', 'T'};

int read(){
	char ch = getchar();
	while(ch != 'A' && ch != 'G'  && ch != 'C'  && ch != 'T')
		ch = getchar();
	if(ch == 'A')
		return 0;
	if(ch == 'G')
		return 1;
	if(ch == 'C')
		return 2;
	if(ch == 'T')
		return 3;
}
int mex(int a, int b, int c = -1){
	for(int i = 0;;i++)
		if(a != i && b != i && c != i)
			return i;
}
int n, m, cnt[N][2][4], dp[N][4][4], ans = -inf;
pii pr[N][4][4];
vector< vector< int > > s;

void solve(int i, int j, bool flag = 0){
	int a = i;
	int b = j;        
	int c = mex(i, j);
	int d = mex(i, j, c);
	int cur = 0;
	for(int i = 0; i < n; i++){
		int p1 = 0, p2 = 0;

		for(int j = 0; j < m; j++)
			if(j & 1)
				p1 += (s[i][j] == a);
			else
				p1 += (s[i][j] == b);
		
		for(int j = 0; j < m; j++)
			if(j & 1)
				p2 += (s[i][j] == b);
			else
				p2 += (s[i][j] == a);
		
		cur += max(p1, p2);
		swap(a, c);
		swap(b, d);
	}
	if(flag){
		if(ans != cur)
			return;
		int a = i;
		int b = j;        
		int c = mex(i, j);
		int d = mex(i, j, c);
		for(int i = 0; i < n; i++){
			int p1 = 0, p2 = 0;
			
			for(int j = 0; j < m; j++)
				if(j & 1)
					p1 += (s[i][j] == a);
				else
					p1 += (s[i][j] == b);
			
			for(int j = 0; j < m; j++)
				if(j & 1)
					p2 += (s[i][j] == b);
				else
					p2 += (s[i][j] == a);
		    if(p1 > p2){
		    	for(int j = 0; j < m; j++)
					if(j & 1)
						printf("%c", mt[a]);
	    			else
						printf("%c", mt[b]);
			}else{
		    	for(int j = 0; j < m; j++)
					if(j & 1)
						printf("%c", mt[b]);
	    			else
						printf("%c", mt[a]);
			}
			printf("\n");
			swap(a, c);
			swap(b, d);
		}
    	exit(0);
	}
	ans = max(ans, cur);
}
int main(){
	scanf("%d%d", &n, &m);
	s.resize(n, vector< int > (m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			s[i][j] = read();
	
	for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 4; j++)
			solve(i, j);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cnt[j][i & 1][s[i][j]]++;
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			for(int q = 0; q < m; q++)
				dp[q][i][j] = -inf;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(i != j)
				dp[0][i][j] = cnt[0][0][i] + cnt[0][1][j];	
	for(int q = 1; q < m; q++){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(i == j)
					continue;
				int a = mex(i, j);
				int b = mex(i, j, a);
				if(dp[q][a][b] < dp[q - 1][i][j] + cnt[q][0][a] + cnt[q][1][b]){
            		dp[q][a][b] = dp[q - 1][i][j] + cnt[q][0][a] + cnt[q][1][b];
            		pr[q][a][b] = {i, j};
            	}
                swap(a, b);
            	if(dp[q][a][b] < dp[q - 1][i][j] + cnt[q][0][a] + cnt[q][1][b]){
            		dp[q][a][b] = dp[q - 1][i][j] + cnt[q][0][a] + cnt[q][1][b];
            		pr[q][a][b] = {i, j};
            	}
			}
		}
	}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(i != j)
				ans = max(ans, dp[m - 1][i][j]);
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++){
			if(i == j || dp[m - 1][i][j] != ans)
				continue;
	    	vector< int > a, b;
	    	for(int q = m - 1; q >= 0; q--){
	    		a.pb(i);
	    		b.pb(j);
	    		pii p = pr[q][i][j];
	    		i = p.f;
	    		j = p.s;
	    	}                           
	    	reverse(a.begin(), a.end());
	    	reverse(b.begin(), b.end());
	    	for(int q = 0; q < n; q++){
	    		if(q & 1){
	    			for(auto it : b)
	    				printf("%c", mt[it]);
	    			printf("\n");
	    		}else{
	    			for(auto it : a)
	    				printf("%c", mt[it]);
	    			printf("\n");
	    		}
	    	}
	    	return 0;
		}
	
	for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 4; j++)
			solve(i, j, 1);
		
}