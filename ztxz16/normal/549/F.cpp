#include <set>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;
 
int FASTBUFFER;

const int N = 300005;

int f[N];

int find(int i) {
    return f[i] == i ? i : f[i] = find(f[i]);
}

map <int, int> s[N];
int n, k, val[N], sum[N], exist[N];
pair <int, int> v[N];
map <int, int> :: iterator it2;
long long ans;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
        sum[i] = (sum[i - 1] + val[i] % k) % k;
        v[i] = make_pair(val[i], i);
        f[i] = i;
        exist[i] = 0;
    }
    
    sort(v + 1, v + n + 1);
    for (int j = 1; j <= n; j++) {
        int i = v[j].second;
        if (exist[i - 1]) {
            if (exist[i + 1]) {
                int a = find(i - 1), b = find(i + 1);
                if ((int)s[a].size() < (int)s[b].size()) {
                    for (map <int, int> :: iterator it = s[a].begin(); it != s[a].end(); ++it) {
                        int x = (it->first + val[i] % k) % k;
                        it2 = s[b].find(x);
                        if (it2 != s[b].end()) {
                            ans += (long long)it->second * it2->second;
                        }
                    }
                    
                    for (map <int, int> :: iterator it = s[a].begin(); it != s[a].end(); ++it) {
                        s[b][it->first] += it->second;
                    }
                    
                    ans--;
                    s[a].clear();
                    f[a] = b;
                    f[i] = b;
                } else {
                    for (map <int, int> :: iterator it = s[b].begin(); it != s[b].end(); ++it) {
                        int x = (it->first - val[i] % k) % k;
                        while (x < 0) {
                            x += k;
                        }
                        
                        it2 = s[a].find(x);
                        if (it2 != s[a].end()) {
                            ans += (long long)it->second * it2->second;
                        }
                    }
                    
                    ans--;
                    for (map <int, int> :: iterator it = s[b].begin(); it != s[b].end(); ++it) {
                        s[a][it->first] += it->second;
                    }
                    
                    s[b].clear();
                    f[b] = a;
                    f[i] = a;
                }
            } else {
                int a = find(i - 1);
                it2 = s[a].find(sum[i - 1]);
                ans += (it2->second - 1);
                f[i] = a;
                s[a][sum[i]]++;
            }
        } else {
            if (exist[i + 1]) {
                int b = find(i + 1);
                it2 = s[b].find(sum[i]);
                ans += (it2->second - 1);
                f[i] = b;
                s[b][sum[i - 1]]++;
            } else {
                s[i][sum[i]]++;
                s[i][sum[i - 1]]++;
            }
        }
        
        exist[i] = 1;
        //cout << ans << endl;
    }
    
    cout << ans << endl;
    return 0;
}