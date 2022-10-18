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
int cur, A[100005], x[100005], N, suf[100005], group[30][100005], sorGroup[100005], sz[100005], v[100005][15];
pair <int, int> B[100005];
struct comp{
    int h;
    comp(int h):h(h){}
    bool operator ()(int i, int j){
        return group[cur][i] < group[cur][j] || group[cur][i] == group[cur][j] && group[cur][i + h] < group[cur][j + h];
    }
};
void Build_Suffix_Array(){
    N++;
    for(int i = 0; i < N; i++){
        suf[i] = i;
        group[0][i] = A[i];
    }
    sort(suf, suf + N, comp(0));
    sorGroup[0] = sorGroup[N - 1] = 0;
    cur = 0;
    for(int h = 1; h <= N; h <<= 1){
        sort(suf, suf + N, comp(h));
        for(int i = 1; i < N; i++)
            sorGroup[i] = sorGroup[i - 1] + comp(h)(suf[i - 1], suf[i]);
        cur++;
        for(int i = 0; i < N; i++)
            group[cur][suf[i]] = sorGroup[i];
    }
    N--;
}
int lcp(int i, int j){
    int ret = 0;
    for(int k = 20; k >= 0; k--){
        if(i + (1 << k) <= N && j + (1 << k) <= N){
            if(group[k][i] == group[k][j])i += 1 << k, j += 1 << k, ret += 1 << k;
        }
    }
    return ret;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &B[i].first);
        B[i].second = i;
        x[i] = B[i].first;
    }
    sort(B, B + N);
    for(int i = 0; i < N; i++){
        if(i > 0 && B[i].first == B[i - 1].first)A[B[i].second] = A[B[i - 1].second];
        else A[B[i].second] = i + 1;
    }
    for(int i = 0; i < N; i++)
        v[A[i]][sz[A[i]]++] = i;

    Build_Suffix_Array();
    int st = 0;
    for(int i = 0; i < N; ){
        int found = -1;
        for(int j2 = 0; j2 < sz[A[i]]; j2++){
            int u = v[A[i]][j2];
            if(u > i){
                int len = u - i;
                if(u + len <= N){
                    if(lcp(i, u) >= len){
                        found = len;
                        break;
                    }
                }
            }
        }
        if(found != -1){
            i += found;
            st = i;
        }else i++;
    }
    printf("%d\n", N - st);
    for(int i = st; i < N; i++){
        if(i > st)printf(" ");
        printf("%d", x[i]);
    }
    printf("\n");
    return 0;
}