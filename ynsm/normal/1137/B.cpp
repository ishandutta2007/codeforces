#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

char s[N], t[N];
int n, m, k, z[N], cnt[2], need[2];
int main()
{                         
	scanf("%s", &s);      
	scanf("%s", &t);
	n = strlen(s);
	m = strlen(t);

	for (int i=1, l=0, r=0; i < m; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && t[z[i]] == t[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}

	k = m;
	for(int i = 1; i < m; i++)
		if(i + z[i] == m){
			k = i;
			break;
		}
	cerr << k << endl;

	for(int i = 0; i < n; i++)
		cnt[s[i] - '0']++;

	for(int i = 0; i < m; i++)
		need[t[i] - '0']++;
	
	if(cnt[0] >= need[0] && cnt[1] >= need[1]){
		cnt[0] -= need[0];
		cnt[1] -= need[1];
		for(int i = 0; i < m; i++)
			printf("%c", t[i]);		
	}
	
	need[0] = need[1] = 0;
	for(int i = z[k]; i < m; i++)
		need[t[i] - '0']++;
	 
	
	while(cnt[0] >= need[0] && cnt[1] >= need[1]){
		cnt[0] -= need[0];
		cnt[1] -= need[1];     
		for(int i = z[k]; i < m; i++)
			printf("%c", t[i]);		
	}		        
	while(cnt[0]--)
		printf("0");
	while(cnt[1]--)
		printf("1");
	return 0;
}