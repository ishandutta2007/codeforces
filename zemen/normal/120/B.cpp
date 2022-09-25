#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>

#define INF (1000000000)
#define PI (acos(-1))
#define EPS (1e-8)

#define pb push_back
#define li long long

using namespace std;

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n, k, i, j, a[1010];
	cin >> n >> k;
	for (i=1; i<=n; i++) cin >> a[i];
	while (a[k] != 1){
	    k++;
	    if (k > n) k = 1;
	}
	cout << k << endl;
}