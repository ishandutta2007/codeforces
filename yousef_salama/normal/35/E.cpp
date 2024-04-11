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

struct event{
    int x, y, type;
    event(){}
    event(int x_, int y_, int type_){
        x = x_;
        y = y_;
        type = type_;
    }
    bool operator <(const event &a) const{
        if(x != a.x)return x < a.x;
        if(type != a.type)return type < a.type;
        return y < a.y;
    }
};

int n, hi, li, ri;
vector <event> evs;
vector <int> x, y, ansX, ansY;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &hi, &li, &ri);
        
        evs.push_back(event(li, hi, 0));
        evs.push_back(event(ri, hi, 1));
    }
    sort(evs.begin(), evs.end());
    
    multiset <int> s;
    s.insert(0);
    
    for(int i = 0; i < evs.size(); ){
        int cx = evs[i].x;
    
        while(i < evs.size() && evs[i].x == cx){
            if(evs[i].type == 0)s.insert(evs[i].y);
            else s.erase(s.find(evs[i].y));
            
            i++;
        }
        
        x.push_back(cx);
        y.push_back(*s.rbegin());
    }
    
    int py = 0;
    for(int i = 0; i < x.size(); i++){
        if(py != y[i]){
            ansX.push_back(x[i]);
            ansY.push_back(py);
            
            ansX.push_back(x[i]);
            ansY.push_back(y[i]);
        }
        
        py = y[i];
    }
    
    printf("%d\n", ansX.size());
    for(int i = 0; i < ansX.size(); i++)
        printf("%d %d\n", ansX[i], ansY[i]);
    return 0;
}