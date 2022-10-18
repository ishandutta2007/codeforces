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

int h, w, k, color[1005][1005];
char hcons[1005][1005], vcons[1005][1005];

int calc_correct(){
    int ret = 0;
    for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++){
        if(j + 1 < w)ret += (hcons[i][j] == 'N') ^ (color[i][j] == color[i][j + 1]);
        if(i + 1 < h)ret += (vcons[i][j] == 'N') ^ (color[i][j] == color[i + 1][j]);
    }
    return ret;
}

void fill_row(int row, int st){
    color[row][0] = st;
    for(int j = 1; j < w; j++){
        if(hcons[row][j - 1] == 'E')color[row][j] = color[row][j - 1];
        else color[row][j] = ((color[row][j - 1] - 1) ^ 1) + 1;
    }
}
void fill_col(int col, int st){
    color[0][col] = st;
    for(int i = 1; i < h; i++){
        if(vcons[i - 1][col] == 'E')color[i][col] = color[i - 1][col];
        else color[i][col] = ((color[i - 1][col] - 1) ^ 1) + 1;
    }
}
int wrong_row(int row){
    int ret = 0;
    for(int j = 0; j < w; j++)
        ret += (vcons[row - 1][j] == 'E') ^ (color[row][j] == color[row - 1][j]);
    return ret;
}
int wrong_col(int col){
    int ret = 0;
    for(int i = 0; i < h; i++)
        ret += (hcons[i][col - 1] == 'E') ^ (color[i][col] == color[i][col - 1]);
    return ret;
}

int main(){
    scanf("%d %d %d", &h, &w, &k);
    for(int i = 0; i < (2 * h - 1); i++){
        if(i % 2 == 0)scanf("%s", hcons[i / 2]);
        else scanf("%s", vcons[i / 2]);
    }
    
    int total = (h - 1) * w + (w - 1) * h;
    if(k == 1){
        for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            color[i][j] = 1;
        
        int res = calc_correct();
        if(res * 4 >= total * 3){
            printf("YES\n");
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(j > 0)printf(" ");
                    printf("%d", color[i][j]);
                }
                printf("\n");
            }
        }else printf("NO\n");
    }else{
        if(w >= h){
            fill_row(0, 1);
            for(int i = 1; i < h; i++){
                fill_row(i, 1);
                if(wrong_row(i) * 2 > w)fill_row(i, 2);
            }
            
            printf("YES\n");
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(j > 0)printf(" ");
                    printf("%d", color[i][j]);
                }
                printf("\n");
            }
        }else{
            fill_col(0, 1);
            for(int j = 1; j < w; j++){
                fill_col(j, 1);
                if(wrong_col(j) * 2 > h)fill_col(j, 2);
            }
            
            printf("YES\n");
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(j > 0)printf(" ");
                    printf("%d", color[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}