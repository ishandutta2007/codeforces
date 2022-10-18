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
struct v{
    int a, b, c, cost;
};
int main(){
    int n, a, b, c, d;
    cin >> n;
    vector <v> v(n);
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        v[i].a = a;
        v[i].b = b;
        v[i].c = c;
        v[i].cost = d;
    }
    bool mark[n];
    memset(mark, 0, sizeof mark);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i].a < v[j].a && v[i].b < v[j].b && v[i].c < v[j].c){
                mark[i] = 1;
            }
            else if(v[i].a > v[j].a && v[i].b > v[j].b && v[i].c > v[j].c)
                mark[j] = 1;
        }
    }
    int index, minX = 1 << 25;
    for(int i = 0; i < n; i++)if(!mark[i]){
        if(v[i].cost < minX){
            minX = v[i].cost;
            index = i;
        }
    }
    cout << index + 1 << endl;
    return 0;
}