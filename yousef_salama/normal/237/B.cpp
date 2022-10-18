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
using namespace std;
int n, c[55], a[55][55], opr_num, a1[55 * 55], a2[55 * 55], a3[55 * 55], a4[55 * 55], indi[55 * 55], indj[55 * 55];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < c[i]; j++){
        scanf("%d", &a[i][j]);
        indi[a[i][j]] = i;
        indj[a[i][j]] = j;
    }
    for(int i = 0, cur = 1; i < n; i++)
    for(int j = 0; j < c[i]; j++, cur++){
        if(a[i][j] != cur){
            a1[opr_num] = i + 1;
            a2[opr_num] = j + 1;
            a3[opr_num] = indi[cur] + 1;
            a4[opr_num] = indj[cur] + 1;

            int xi = indi[cur];
            int xj = indj[cur];
            swap(indi[a[i][j]], indi[cur]);
            swap(indj[a[i][j]], indj[cur]);
            swap(a[i][j], a[xi][xj]);
            opr_num++;
        }
    }
    printf("%d\n", opr_num);
    for(int i = 0; i < opr_num; i++)
        printf("%d %d %d %d\n", a1[i], a2[i], a3[i], a4[i]);
    return 0;
}