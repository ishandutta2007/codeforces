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
#define oo 1 << 25
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int bet[m][4];
    for(int i = 0; i < m; i++)
        cin >> bet[i][0] >> bet[i][1] >> bet[i][2] >> bet[i][3];
    int profit = 0;
    for(int i = 1; i <= n; i++){
        int bestI = -1;
        for(int j = 0; j < m; j++)
            if(bet[j][0] <= i && i <= bet[j][1]){
                if(bestI == -1)bestI = j;
                else if(bet[bestI][2] > bet[j][2])bestI = j;
            }
        if(bestI != -1)profit += bet[bestI][3];
    }
    cout << profit << endl;
    return 0;
}