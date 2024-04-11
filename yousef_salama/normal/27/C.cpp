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
int n, a[100005], Pmax[100005], Pmin[100005], Smax[100005], Smin[100005];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ind = -1;
    for(int i = 0; i < n; i++){
        Pmin[i] = ind;
        if(ind == -1 || a[ind] > a[i])ind = i;
    }
    ind = -1;
    for(int i = 0; i < n; i++){
        Pmax[i] = ind;
        if(ind == -1 || a[ind] < a[i])ind = i;
    }
    ind = -1;
    for(int i = n - 1; i >= 0; i--){
        Smin[i] = ind;
        if(ind == -1 || a[ind] > a[i])ind = i;
    }
    ind = -1;
    for(int i = n - 1; i >= 0; i--){
        Smax[i] = ind;
        if(ind == -1 || a[ind] < a[i])ind = i;
    }

    bool found = false;
    for(int i = 1; i < n - 1; i++){
        if(a[Pmin[i]] < a[i] && a[Smin[i]] < a[i]){
            cout << 3 << endl << Pmin[i] + 1 << ' ' << i + 1 << ' ' << Smin[i] + 1 << endl;
            found = true;
            break;
        }
        if(a[Pmax[i]] > a[i] && a[Smax[i]] > a[i]){
            cout << 3 << endl << Pmax[i] + 1 << ' ' << i + 1 << ' ' << Smax[i] + 1 << endl;
            found = true;
            break;
        }
    }
    if(!found)cout << 0 << endl;
    return 0;
}