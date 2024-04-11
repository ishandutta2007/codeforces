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
int n, m, k, t, x, y;
int index(int i, int j){
    return ((i * m) + j);
}
int main(){
//    freopen("a.in", "r", stdin);
    cin >> n >> m >> k >> t;
    vector <int> w;
    string ans[] = {"Carrots", "Kiwis", "Grapes"};
    while(k--){
        cin >> x >> y;
        w.push_back(index(x - 1, y - 1));
    }
    sort(w.begin(), w.end());
    while(t--){
        cin >> x >> y;
        x--;y--;
        if(binary_search(w.begin(), w.end(), index(x, y)))cout << "Waste" << endl;
        else{
            int j = lower_bound(w.begin(), w.end(), index(x, y)) - w.begin();
            cout << ans[((index(x, y) - j) % 3)] << endl;
        }
    }
    return 0;
}