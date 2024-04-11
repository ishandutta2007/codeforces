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
int N, a;
set <int> A;
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        A.insert(a);
    }
    if(A.size() == 1)printf("NO\n");
    else{
        set <int> :: iterator it = A.begin();
        printf("%d\n", *++it);
    }
    return 0;
}