#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
class cons{
public:
    pair <int, int> a[5];
    int r;
};
bool cmp(cons a, cons b){
    if(a.r != b.r)return a.r < b.r;
    if(a.a[0].first != b.a[0].first)return a.a[0].first < b.a[0].first;
    if(a.a[0].second != b.a[0].second)return a.a[0].second < b.a[0].second;
}
int main(){
    int n, m, index;
    cin >> n >> m >> index;
    string g[n];
    for(int i = 0; i < n; i++)
        cin >> g[i];
    int cnt = 0;
    cons c;
    c.r = -1;
    for(int k = 1; k < min(n, m); k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)if(g[i][j] == '*'){
                int maxN = min(i, min(j , min(n - i - 1, m - j - 1)));
                if(k > maxN)continue;
                if(g[i + k][j] == '*' && g[i][j + k] == '*' && g[i - k][j] == '*' && g[i][j - k] == '*'){
                    cnt++;
                    if(cnt == index){
                        c.a[0] = make_pair(i, j);
                        c.a[1] = make_pair(i - k, j);
                        c.a[2] = make_pair(i + k, j);
                        c.a[3] = make_pair(i, j - k);
                        c.a[4] = make_pair(i, j + k);
                        c.r = k;
                    }
                }
            }
    if(c.r == -1)cout << -1 << endl;
    else for(int i = 0; i < 5; i++)
            cout << c.a[i].first + 1 << ' ' << c.a[i].second + 1 << endl;
    return 0;
}