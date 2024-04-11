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
int n;
bool allVis(bool v[]){
    for(int i = 0; i < n; i++)
        if(!v[i])return false;
    return true;
}
int main(){
    cin >> n;
    int jump = 1, index = 0;
    bool v[n];
    memset(v, 0, sizeof v);
    v[index] = 1;
    while(!allVis(v)){
        if(jump >= n){
            cout << "NO" << endl;
            return 0;
        }
        index = (index + jump++) % n;
        v[index] = 1;
    }
    cout << "YES" << endl;
    return 0;
}