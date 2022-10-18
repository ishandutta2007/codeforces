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
#include <string.h>
using namespace std;
int n, m, c[100015], tree[100015];
bool can[100015];
int update(int i, int val){
    while(i < 100015){
        tree[i] += val;
        i += i & (-i);
    }
}
int query(int i){
    int ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= i & (-i);
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        if(c[i] > 0){
            int j = abs(c[i]);
            update(j, 1);
            update(j + 1, -1);
        }else{
            int j = abs(c[i]);
            update(1, 1);
            update(j, -1);
            update(j + 1, 1);
        }
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        if(query(i + 1) == m){
            can[i] = true;
            num++;
        }else can[i] = false;
    }
    for(int i = 0; i < n; i++){
        if(c[i] > 0){
            int j = abs(c[i]) - 1;
            if(can[j]){
                if(num == 1)cout << "Truth" << endl;
                else cout << "Not defined" << endl;
            }else{
                cout << "Lie" << endl;
            }
        }else{
            int j = abs(c[i]) - 1;
            if(can[j]){
                if(num == 1)cout << "Lie" << endl;
                else cout << "Not defined" << endl;
            }
            else{
                cout << "Truth" << endl;
            }
        }
    }
    return 0;
}