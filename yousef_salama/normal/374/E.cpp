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
using namespace std;

struct segment{
    int minX, minY, maxX, maxY;
};

int n, m, xi, yi;
vector < pair <int, int> > blue, red;
bool f[2005][2005];

bool cmpXY(segment a, segment b){
    if(a.minX != b.minX)return a.minX < b.minX;
    return a.minY < b.minY;
}
bool cmpYX(segment a, segment b){
    if(a.minY != b.minY)return a.minY < b.minY;
    return a.minX < b.minX;
}

bool can(int X){
    vector <segment> vert, horz, vertU, horzU;
    for(int i = 0; i < blue.size(); i++){
        segment a;
        a.minX = blue[i].first;
        a.maxX = blue[i].first;
        
        a.minY = blue[i].second - 2 * X;
        a.maxY = blue[i].second + 2 * X;

        vert.push_back(a);
    }
    sort(vert.begin(), vert.end(), cmpXY);
    
    for(int i = 0; i < vert.size(); i++){
        if(vertU.empty())vertU.push_back(vert[i]);
        else{
            if(vertU.back().minX == vert[i].minX && vertU.back().maxY >= vert[i].minY)
                vertU.back().maxY = max(vertU.back().maxY, vert[i].maxY);
            else vertU.push_back(vert[i]);
        }
    }
    
    for(int i = 0; i < red.size(); i++){
        segment a;
        a.minY = red[i].second;
        a.maxY = red[i].second;
        
        a.minX = red[i].first - 2 * X;
        a.maxX = red[i].first + 2 * X;
        
        horz.push_back(a);
    }
    sort(horz.begin(), horz.end(), cmpYX);
    
    for(int i = 0; i < horz.size(); i++){
        if(horzU.empty())horzU.push_back(horz[i]);
        else{
            if(horzU.back().minY == horz[i].minY && horzU.back().maxX >= horz[i].minX)
                horzU.back().maxX = max(horzU.back().maxX, horz[i].maxX);
            else horzU.push_back(horz[i]);
        }
    }
    
    memset(f, false, sizeof f);
    for(int i = 0; i < horzU.size(); i++){
        vector <int> involved;
        for(int j = 0; j < vertU.size(); j++){
            if(horzU[i].minX <= vertU[j].minX && vertU[j].minX <= horzU[i].maxX){
                if(vertU[j].minY <= horzU[i].minY && horzU[i].minY <= vertU[j].maxY)
                        involved.push_back(j);
            }
        }
        
        for(int x1 = 0; x1 < involved.size(); x1++)
        for(int x2 = x1 + 1; x2 < involved.size(); x2++){
            if(f[involved[x1]][involved[x2]] || f[involved[x1]][involved[x2]])return true;
            
            f[involved[x1]][involved[x2]] = true;
            f[involved[x2]][involved[x1]] = true;
        }
    }
    
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &xi, &yi);
        blue.push_back(make_pair(xi + yi, xi - yi));
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &xi, &yi);
        red.push_back(make_pair(xi + yi, xi - yi));
    }

    int L = 0, R = 1 << 30;
    while(L < R){
        int M = (L + R) >> 1;
        if(can(M))R = M;
        else L = M + 1;
    }
    
    if(!can(L))printf("Poor Sereja!\n");
    else printf("%d\n", L);
    
    return 0;
}