//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <unordered_map>
using namespace std;

double h[10], x[10], e[10][10];
int emask[10];
void gauss(){
  /*  for(int i = 0; i < 6; i++){
        for(int j = 1; j < 7; j++)
            cout << e[j][i] << ' ';
        cout << endl;
    }
    
    cout << "------------" << endl;
*/
    for(int i = 0, l = 6; i < 6; i++, l--){
        for(int j = i; j < 6; j++)if(fabs(e[l][j]) > 1e-3){
            for(int k = 0; k < 7; k++)swap(e[k][i], e[k][j]);
            
            double m = e[l][i];
            for(int k = 0; k < 7; k++)e[k][i] /= m;
            h[i] /= m;

            break;
        }
        for(int j = i + 1; j < 6; j++)if(fabs(e[l][j]) > 1e-6){
            double m = e[l][j] / e[l][i];
            
            for(int k = 0; k < 7; k++)e[k][j] -= m * e[k][i];
            h[j] -= m * h[i];
        }
    }

    /*for(int i = 0; i < 7; i++){
        for(int j = 0; j < 6; j++)
            cout << e[i][j] << ' ';
        cout << endl;
    }*/
}

char p[4][1000005];
int main(){
    for(int i = 0; i < 6; i++)
        scanf("%lf", &h[i]);

    int ind = 0;
    for(int mask = 1; mask < (1 << 4); mask++){
        if(mask & 1)continue;
        
        for(int i = 0, k = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++, k++){
            e[ind][k] = ((mask & (1 << i)) != 0) ^ ((mask & (1 << j)) != 0);
        }
        emask[ind++] = mask;
    }

    gauss();
    
    int x0 = -1, ms = 0;
    for(int x_ = 0; x_ <= 100000; x_++){
        x[0] = x_;
        for(int i = 5, l = 1; i >= 0; i--, l++){
            x[l] = h[i];
            for(int j = 0; j < l; j++)x[l] -= x[j] * e[j][i];
        }
        bool ok = true;

        int s = 0;
        for(int k = 0; k < 7; k++){    
            if(x[k] < 0)ok = false;
            if(fabs(x[k] - floor(x[k])) > 1e-6)ok = false;

            s += x[k];
        }
        
        if(ok){
            if((x0 == -1) || (s < ms)){
                x0 = x[0];
                ms = s;
            }
        }
   }

    if((x0 == -1))printf("-1\n");
    else{
        x[0] = x0;
        for(int i = 5, l = 1; i >= 0; i--, l++){
            x[l] = h[i];
            for(int j = 0; j < l; j++)x[l] -= x[j] * e[j][i];
        }
        
        printf("%d\n", ms);

        int kj = 0;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < x[i]; j++){
                for(int k = 0; k < 4; k++){
                    if(emask[i] & (1 << k))p[k][kj] = 'b';
                    else p[k][kj] = 'a';
                }
                kj++;
            }
        }
        p[0][kj] = p[1][kj] = p[2][kj] = p[3][kj] = 0;

        for(int i = 0; i < 4; i++)
            printf("%s\n", p[i]);
    }

    return 0;
}