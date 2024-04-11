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

int n, s[105], c[105][105];
int main(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
        for(int j = 0; j < s[i]; j++)
            scanf("%d", &c[i][j]);
    }
    
    int sumC = 0, sumJ = 0;
    vector <int> middle;

    for(int i = 0; i < n; i++){
        if(s[i] % 2 == 0){
            for(int j = 0; j < (s[i] / 2); j++)
                sumC += c[i][j];
            for(int j = (s[i] / 2); j < s[i]; j++)
                sumJ += c[i][j];
        }else{
            for(int j = 0; j < (s[i] / 2); j++)
                sumC += c[i][j];
            for(int j = (s[i] / 2) + 1; j < s[i]; j++)
                sumJ += c[i][j];
            middle.push_back(c[i][s[i] / 2]);
        }
    }
    sort(middle.rbegin(), middle.rend());
    for(int i = 0; i < middle.size(); i++){
        if(i % 2 == 0)sumC += middle[i];
        else sumJ += middle[i];
    }
    printf("%d %d\n", sumC, sumJ);
    
    return 0;
}