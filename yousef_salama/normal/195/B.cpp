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
int n, m, Mid, a, b;
vector <int> v;
int main(){
    cin >> n >> m;
    Mid = (m + 1) / 2, a = 1, b = 1;
    v.push_back(Mid);
    for(int i = (m + 1) % 2; i < m - (1 - ((m + 1) % 2)); i++){
        if(i % 2 == 0){
            v.push_back(Mid - a);
            a++;
        }else{
            v.push_back(Mid + b);
            b++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << v[i % m] << endl;
    return 0;
}