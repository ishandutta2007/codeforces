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
int N;
pair <int, int> A[1000005];
long long cnt[5][1000005], tree[2][1000005];
void update(int lev, int idx, long long val){
    while(idx <= 1000005){
        tree[lev][idx] += val;
        idx += idx & (-idx);
    }
}
long long query(int lev, int idx){
    long long ans = 0;
    while(idx > 0){
        ans += tree[lev][idx];
        idx -= idx & (-idx);
    }
    return ans;
}
bool Rev(pair <int, int> a, pair <int, int> b){
    return a.first > b.first;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i].first);
        A[i].second = i;
    }
    sort(A, A + N, Rev);
    for(int i = 0; i < N; i++)
        A[A[i].second].first = i + 1;
    for(int i = 0; i < N; i++)
        cnt[0][i] = cnt[1][i] = 1;
    for(int len = 2; len <= 3; len++){
        for(int i = 0; i < N; i++){
            cnt[len][i] = query((len - 1)&1, A[i].first + 1);
            update((len - 1)&1, A[i].first + 2, cnt[len - 1][i]);
        }
        memset(tree[len&1], 0, sizeof tree[len&1]);
    }
    long long Sum = 0;
    for(int i = 0; i < N; i++)
        Sum += cnt[3][i];
    cout << Sum << endl;
    return 0;
}