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
int main(){
    string a, b;
    cin >> a >> b;
    vector <int> v[26];
    for(int i = 0; i < a.size(); i++)
        v[a[i] - 'a'].push_back(i);
    int cost = 1, p = -1;
    for(int i = 0; i < b.size(); i++){
        int cur = upper_bound(v[b[i] - 'a'].begin(), v[b[i] - 'a'].end(), p) - v[b[i] - 'a'].begin();
        if(cur == v[b[i] - 'a'].size()){
            if(p == -1){
                cout << -1 << endl;
                return 0;
            }
            else{
                i--;
                cost++;
                p = -1;
            }
        }
        else p = v[b[i] - 'a'][cur];
    }
    cout << cost << endl;
    return 0;
}