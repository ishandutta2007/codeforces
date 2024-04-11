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
int n, a, b;
map <int, int> U, D;
set <int> S;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;

        S.insert(a);
        S.insert(b);

        if(a != b){
            U[a]++;
            D[b]++;
        }else U[a]++;
    }
    int ans = -1, wanted = (n + 1) / 2;
    for(set <int> :: iterator it = S.begin(); it != S.end(); it++){
        int cur = *it;
        int x = U[cur], y = D[cur];

        if(x >= wanted)ans = 0;
        else{
            if(y >= wanted - x){
                if(ans == -1 || ans > wanted - x)
                    ans = wanted - x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}