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

char s[N];
int n, ban[N];
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%s", &s);
		n = strlen(s);
		for(int i = 0; i < n; i++){
			if(i + 4 < n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e')
				ban[i + 2] = 1;
			if(i + 2 < n && !ban[i] && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
				ban[i + 1] = 1;
			if(i + 2 < n && !ban[i + 2] && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
				ban[i + 1] = 1;
		}
		int cnt = 0;
		for(int i = 0; i < n; i++)
			cnt += ban[i];
		printf("%d\n", cnt);
		for(int i = 0; i < n; i++){
			if(ban[i])
				printf("%d ", i + 1);
			ban[i] = 0;
		}
		printf("\n");
	}
	return 0;
}