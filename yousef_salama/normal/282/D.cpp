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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

int n, a[3];
bool win[2][300][300][5];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(int x = 0; x <= a[0]; x++)
    for(int y = 0; y <= a[1]; y++)
    for(int z = 0; z <= a[2]; z++)
    for(int opr = 4; opr >= 0; opr--){
        win[x & 1][y][z][opr] = false;
        if(opr == 4){
            
            if(x == 0 && y == 0 && z == 0)
                continue;
            
            if(x > 0 && (y > 0 || n < 2) && (z > 0 || n < 3))
                win[x & 1][y][z][opr] |= win[(x - 1) & 1][y - (n < 2 ? 0 : 1)][z - (n < 3 ? 0 : 1)][3];
            if(x > 0)win[x & 1][y][z][opr] |= win[(x - 1) & 1][y][z][0];
            if(y > 0)win[x & 1][y][z][opr] |= win[x & 1][y - 1][z][1];
            if(z > 0)win[x & 1][y][z][opr] |= win[x & 1][y][z - 1][2];

        }else if(opr == 3){
            
            if(x > 0 && (y > 0 || n < 2) && (z > 0 || n < 3))
                win[x & 1][y][z][opr] |= win[(x - 1) & 1][y - (n < 2 ? 0 : 1)][z - (n < 3 ? 0 : 1)][3];
            
            win[x & 1][y][z][opr] |= !win[x & 1][y][z][4];
            
        }else{

            if(opr == 0){
                if(x > 0)win[x & 1][y][z][opr] |= win[(x - 1) & 1][y][z][0];
            }
            if(opr == 1){
                if(y > 0)win[x & 1][y][z][opr] |= win[x & 1][y - 1][z][1];
            }
            if(opr == 2){
                if(z > 0)win[x & 1][y][z][opr] |= win[x & 1][y][z - 1][2];
            }
            win[x & 1][y][z][opr] |= !win[x & 1][y][z][4];
        }
    }
    
    if(win[a[0] & 1][a[1]][a[2]][4])printf("BitLGM\n");
    else printf("BitAryo\n");
    return 0;
}