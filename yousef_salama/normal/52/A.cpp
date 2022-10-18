#include <iostream>
#include <fstream>
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
#include <string.h>
using namespace std;
int main(){
    vector <int> v(3);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        v[x - 1]++;
    }
    sort(v.begin(), v.end());
    cout << v[0] + v[1] << endl;
    return 0;
}