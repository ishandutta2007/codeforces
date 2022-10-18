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
bool f[5][5];
int main(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            f[i][j] = 0;
    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        f[a - 1][b - 1] = 1;
        f[b - 1][a - 1] = 1;
    }
    for(int i = 0; i < 5; i++)
        for(int j = i + 1; j < 5; j++)
            for(int k = j + 1; k < 5; k++){
                if(f[i][j] && f[j][k] && f[i][k]){
                    cout << "WIN" << endl;
                    return 0;
                }
                if(!f[i][j] && !f[j][k] && !f[i][k]){
                    cout << "WIN" << endl;
                    return 0;
                }
            }
    cout << "FAIL" << endl;
    return 0;
}