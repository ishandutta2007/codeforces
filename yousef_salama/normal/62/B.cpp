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
//    freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    string a, q;
    cin >> a;
    vector <int> v[26];
    for(int i = 0; i < a.size(); i++)
        v[a[i] - 'a'].push_back(i);
    while(n--){
        cin >> q;
        long long F = 0;
        for(int i = 0; i < q.size(); i++){
            int minX = -1;
            for(int j = 0; j < v[q[i] - 'a'].size(); j++)
                if(minX == -1 || abs(v[q[i] - 'a'][j] - i) < minX)
                    minX = abs(v[q[i] - 'a'][j] - i);
            if(minX == -1)F += q.size();
            else F += minX;
        }
//            if(!binary_search(v[q[i] - 'a'].begin(), v[q[i] - 'a'].end(), i)){
//                int j = lower_bound(v[q[i] - 'a'].begin(), v[q[i] - 'a'].end(), i) - v[q[i] - 'a'].begin();
//                if(j == v[q[i] - 'a'].size())F += q.size();
//                else if(v[q[i] - 'a'][j] - 1 >= 0){
//                    if(abs(v[q[i] - 'a'][j] - i) < abs((v[q[i] - 'a'][j] - 1) - i))F += abs(v[q[i] - 'a'][j] - i);
//                    else F += abs((v[q[i] - 'a'][j] - 1) - i);
//                }else F += abs(v[q[i] - 'a'][j] - i);
//            }
        cout << F << endl;
    }
    return 0;
}