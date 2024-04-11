#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
const int maxn = 1005;

typedef pair<int, int> pii;

pii p[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        int sum = 0;
        for(int j = 0;j < 4;j++){
            int a;
            cin >> a;
            sum += a;
        }
        p[i] = make_pair(-sum, i);
    }
    sort(p + 1, p + 1 + n);
    for(int i = 1;i <= n;i++){
        if(p[i].second == 1){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}