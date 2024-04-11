#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e6 + 123, inf = 1e9;
const ll INF = 1e18;

int n, k, p[50];
bool used[50], ans;
char s[N], l[N], r[N];
void any(){
	vector< int > v;
	for(int i = 0; i < k; i++)
		if(!used[i])
			v.pb(i);
	for(int i = 0; i < k; i++)
		if(p[i] == -1){
			p[i] = v.back();
			v.pop_back();
		}
	ans = 1;
}
bool go(int i, int j){
	if(p[i] == -1 && !used[j]){
		used[j] = 1;
		p[i] = j;
	}
	return p[i] == j;
}
void solvel(int i, int n, int k){
	if(i == n){
		any();
		return;
	}
	for(int j = l[i] + 1; j < k; j++){
		if(go(s[i], j)){
			any();
			return;
		}
	}
	if(go(s[i], l[i]))
    	solvel(i + 1, n, k);
}
void solver(int i, int n, int k){
	if(i == n){
		any();
		return;
	}
	for(int j = 0; j < r[i]; j++){
		if(go(s[i], j)){
			any();
			return;
		}
	}
	if(go(s[i], r[i]))
    	solver(i + 1, n, k);
}

void solve(int i, int n, int k, bool flag){
	if(i == n){
		any();
		return;
	}
	if(l[i] == r[i]){
		if(go(s[i], l[i]))
			solve(i + 1, n, k, flag);
		return;
	}
    
    for(int j = l[i] + 1; j < r[i]; j++){
		if(go(s[i], j)){
			any();
			return;
		}
	}
    
    if(flag){
		if(go(s[i], l[i]))
			solvel(i + 1, n, k);
	}else{
		if(go(s[i], r[i]))
			solver(i + 1, n, k);
	}
}
void solve(){
	scanf("%d", &k);
	scanf("%s", &s);
	scanf("%s", &l);
	scanf("%s", &r);	
	n = strlen(s);
	for(int i = 0; i < n; i++){
		s[i] -= 'a';
		l[i] -= 'a';
		r[i] -= 'a';
	}
	
	for(int i = 0; i < k; i++)
		used[i] = 0, p[i] = -1;
	ans = 0;
	solve(0, n, k, 0);
	if(ans){
		puts("YES");              
		for(int i = 0; i < k; i++)
			printf("%c", p[i] + 'a');
		printf("\n");
		return;
	}
	
	for(int i = 0; i < k; i++)
		used[i] = 0, p[i] = -1;
	ans = 0;
	solve(0, n, k, 1);
	if(ans){
		puts("YES");              
		for(int i = 0; i < k; i++)
			printf("%c", p[i] + 'a');
		printf("\n");
		return;
	}
	
	puts("NO");
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}