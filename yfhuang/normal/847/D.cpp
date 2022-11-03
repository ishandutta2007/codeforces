#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;

int n;
const int maxn = 2e5 + 5;
int T;
int t[maxn];
int a[maxn];

multiset<int> s;
int main() {
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        a[i] = t[i] - i;
    }
    int ans = 0;
    for(int now = 1;now <= n && now <= T - 1;now++){
        s.insert(t[now] - now);
        multiset<int> ::iterator it;
        while(s.size() > 0){
            it = s.end();
            it--;
            if(*it > T - 1 - now) s.erase(it);
            else break;
        }
        ans = max(ans,(int)s.size());
    }
    cout << ans << endl;

    return 0;
}