//Solution by Tima
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    

const int N = (int)5e5 + 110, mod = int(1e9)  + 7; 

char s[N];
int n, m, a[N], b[N], ans;
map<int, map<int, int> > was;
int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", &s);
		m = strlen(s);
		for(int j = 0; j < m; j++){
			if(s[j] == '(')
				a[i]++;
			else
				a[i]--;
			if(a[i] < 0)
				break;
		}
        for(int j = m - 1; j >= 0; j--){
			if(s[j] == ')')
				b[i]++;
			else
				b[i]--;
			if(b[i] < 0)
				break;
		}
		if(b[i] == -1 && a[i] == -1)
			continue;
		if(was[b[i]][a[i]] > 0){
			was[b[i]][a[i]]--;
			ans++;
		}else
			was[a[i]][b[i]]++;
	}	
	printf("%d", ans);
}