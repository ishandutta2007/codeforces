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

int n, m, aj, bj, xi[100005], yi[100005];
int main(){
    scanf("%d %d", &n, &m);
    
    vector < pair <int, int> > ms, rem;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &aj, &bj);
        if(bj == 0){
            rem.push_back(make_pair(aj, i));
        }else{
            ms.push_back(make_pair(aj, i));
        }
    }
    sort(ms.begin(), ms.end());
    sort(rem.begin(), rem.end());

    for(int i = 0; i < ms.size(); i++){
        xi[ms[i].second] = i + 1;
        yi[ms[i].second] = i + 2;
    }

    reverse(rem.begin(), rem.end());
    for(int i = 2; i < n; i++){
        int j = i - 2;
        while((!rem.empty()) && (rem.back().first >= ms[i - 1].first)){
            if(j < 0)break;

            xi[rem.back().second] = i + 1;
            yi[rem.back().second] = j + 1;

            rem.pop_back();
            j--;
        }
    }
    if(!rem.empty()){
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < m; i++)
        printf("%d %d\n", xi[i], yi[i]);
    
    return 0;
}