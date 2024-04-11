#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e6 + 100;
const int C = 1e7 + 100;
const int K = 30;

int cnt[C];
int go[C][2];
int len = 0;

int n;
int a[N], p[N];

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
    	scanf("%d", &p[i]);
    }
    int root = len++;
    for (int i = 0; i < n; i++) {
    	int cur = root;
    	for (int j = K - 1; j >= 0; j--) {
    		cnt[cur]++;
    		int c = (p[i] & (1 << j)) > 0;
    		if (go[cur][c] == 0) {
    			go[cur][c] = len++;
    		}
    		cur = go[cur][c];
    	}
    	cnt[cur]++;
    }
    for (int i = 0; i < n; i++) {
    	int result = 0, cur = root;
    	for (int j = K - 1; j >= 0; j--) {
    		int c = (a[i] & (1 << j)) > 0;
    		cnt[cur]--;
    		if (go[cur][c] != 0 && cnt[go[cur][c]] > 0) {
    			cur = go[cur][c];
    			result = result * 2 + c;
    		} else {
    			assert(go[cur][c ^ 1] != 0 && cnt[go[cur][c ^ 1]] > 0);
    			cur = go[cur][c ^ 1];
    			result = result * 2 + (c ^ 1);
    		}
    	}
    	cnt[cur]--;
    	printf("%d%c", result ^ a[i], " \n"[i + 1 == n]);
    }
    return 0;
}