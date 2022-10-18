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
int n, a[305], b[305];
vector <int> moves;
void push(int i, int j){
    while(j != i){
        moves.push_back(--j);
        swap(b[j], b[j + 1]);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)if(a[i] == b[j]){
            push(i, j);
            break;
        }
    printf("%d\n", moves.size());
    for(int i = 0; i < moves.size(); i++)
        printf("%d %d\n", moves[i] + 1, moves[i] + 2);
    return 0;
}