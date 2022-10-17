#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9;
const ll INF = 1e18;


int n, q, t[3][N];
char s[N];
set< int > st[3];

int sum (int r, int id)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[id][r];
	return result;
}
void inc (int i, int delta, int id)
{
	for (; i < N; i = (i | (i+1)))
		t[id][i] += delta;
}
int sum (int l, int r, int id)
{
	if(l > r)
		return 0;
	return sum (r, id) - sum (l-1, id);
}

int get(int id){
	int a = id;          
	int b = (id + 1) % 3;
	int c = (id + 2) % 3;
	if(!st[c].empty()){
		if(!st[b].empty()){          
			int lb = *st[b].begin();
			int rb = *st[b].rbegin();
			int lc = *st[c].begin();
			int rc = *st[c].rbegin();
			return sum(max(lb, lc), min(rb, rc), id) + sum(1, min(rb, lc), id) + sum(max(lb, rc), n, id);
		}
		return 0;
	}
	return sum(1, n, id);
}
void calc(){
	printf("%d\n", get(0) + get(1) + get(2));
}
int main(){
	map<int, int> mt;     
	mt['R'] = 0;
	mt['S'] = 1;
	mt['P'] = 2;
	
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++){
		st[mt[s[i]]].insert(i);
		inc(i, 1, mt[s[i]]);
	}
	calc();
	while(q--){
		int p;
		char ch;
		scanf("%d %c", &p, &ch);
		
		st[mt[s[p]]].erase(p);
		inc(p, -1, mt[s[p]]);

		s[p] = ch;
		
		st[mt[s[p]]].insert(p);
		inc(p, 1, mt[s[p]]);

		calc();
	}
	return 0;
}