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
using namespace std;
int n, x;
char comm[20][1050];
vector <int> v;
bool backtrack(int i){
    if(i == x){
        if(v[i] == n)return true;
        else return false;
    }

    for(int a = -1; a <= i; a++)
    for(int b = 0; b <= i; b++)
        for(int k = 1; k <= 8; k *= 2){
            int next = (a == -1?0:v[a]) + v[b] * k;
            v.push_back(next);

            if(backtrack(i + 1)){
                if(a == -1)
                    snprintf(comm[i], sizeof comm[i], "lea e%cx, [%d*e%cx]", 'a' + i + 1, k, 'a' + b);
                else
                    snprintf(comm[i], sizeof comm[i], "lea e%cx, [e%cx + %d*e%cx]",
                            'a' + i + 1, 'a' + a, k, 'a' + b);
                return true;
            }

            v.pop_back();
        }
    return false;
}
int main(){
    scanf("%d", &n);
    v.push_back(1);
    for(x = 0 ; ; x++)
        if(backtrack(0))
            break;
    printf("%d\n", x);
    for(int i = 0; i < x; i++)
        printf("%s\n", comm[i]);
    return 0;
}