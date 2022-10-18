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
#include <string.h>
using namespace std;
int main(){
    string g[8];
    for(int i = 0; i < 8; i++)
        cin >> g[i];
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        bool can = true;
        for(int j = 0; j < 8; j++)
            if(g[i][j] == 'W')can = false;
        if(can)cnt++;
    }
    if(cnt == 8)goto print;
    for(int i = 0; i < 8; i++){
        bool can = true;
        for(int j = 0; j < 8; j++)
            if(g[j][i] == 'W')can = false;
        if(can)cnt++;
    }
    print:
    cout << cnt << endl;    
    return 0;
}