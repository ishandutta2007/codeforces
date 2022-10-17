#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

int n, a[N], b[N], pos[N];
bool was[N];
void solve(){
	int ans = 0;
	for(int i = 1; i <= n; i++)
		was[a[i]] = 1;
	for(int i = 1, j = 1; i <= n; i++){
		while(!was[i])
			ans++, was[b[j++]] = 1;
		ans++;                          
		was[b[j++]] = 1;
	}
	printf("%d", ans);
	exit(0);
}
int main()
{
	scanf("%d", &n);           
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		pos[a[i]] = -1;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		pos[b[i]] = i;
	}
	if(pos[1] == -1)
		solve();
	for(int i = pos[1]; i <= n; i++)
		if(b[i] != i - pos[1] + 1){
		    solve();
			exit(0);
		}	
	for(int i = 1, j = n - pos[1] + 2; i < pos[1]; i++, j++)
		if(b[i] > 0 && b[i] <= j){
		    solve();
			exit(0);
		}	
	
	printf("%d", pos[1] - 1);
	return 0;
}