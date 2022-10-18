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
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++)
        if(v[i] * 2 > v[i + 1] && v[i] != v[i + 1]){
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}