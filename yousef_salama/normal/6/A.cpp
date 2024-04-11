
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
    int a[4];
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a, a + 4);
    bool seg = 0;
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++)
            for(int k = j + 1; k < 4; k++){
                if(a[i] + a[j] > a[k]){
                    cout << "TRIANGLE" << endl;
                    return 0;
                }
                if(a[i] + a[j] == a[k])seg = 1;
            }
    if(seg)cout << "SEGMENT" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}