#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 110;
int main() {
    int n;
    int sum = 0;
    cin >> n;
    vector<int> v[MAXN];
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            sum += a;
            v[i].push_back(a);
        }
    }
    vector<int> k;
    for (int i = 0; i < n; i++) {
        if (v[i].size()%2) {
            k.push_back(v[i][v[i].size()/2]);
        }
    }
    int cc = 0;
    sort(k.begin(), k.end(), greater<int>());
    for (int i = 0; i < k.size(); i++) {
        if (!(i%2)) cc += k[i];
    }
    for (int i = 0; i < n; i++) {
        int ss = v[i].size()/2;
        for (int j = 0; j < ss; j++) {
            cc += v[i][j];
        }
    }
    printf("%d %d\n", cc, sum-cc);
    return 0;
}