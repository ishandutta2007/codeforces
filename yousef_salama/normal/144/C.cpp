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
#include <string.h>
using namespace std;
char a[100005], p[100005];
int N, M, cntA[26], cntP[26], ans = 0, q = 0;
int check(){
    int temp = q;
    for(int i = 0; i < 26; i++){
        if(cntA[i] > cntP[i])return 0;
        if(cntA[i] < cntP[i]){
            if(cntP[i] - cntA[i] <= temp)temp -= cntP[i] - cntA[i];
            else return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%s %s", &a, &p);
    N = strlen(a);
    M = strlen(p);
    if(M > N)printf("0\n");
    else{
        for(int i = 0; i < M; i++){
            if(a[i] == '?')q++;
            else cntA[a[i] - 'a']++;
            cntP[p[i] - 'a']++;
        }
        ans += check();
        for(int i = M; i < N; i++){
            if(a[i - M] == '?')q--;
            else cntA[a[i - M] - 'a']--;
            if(a[i] == '?')q++;
            else cntA[a[i] - 'a']++;
            ans += check();
        }
        printf("%d\n", ans);
    }
    return 0;
}