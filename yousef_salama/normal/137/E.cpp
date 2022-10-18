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
#define MAXN 200005
using namespace std;
char s[MAXN];
int N, p[MAXN];
pair <int, int> b[MAXN], si[MAXN];
vector <int> ans;
bool isvowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void merge_sort(int i, int j){
    if(i == j)return;
    
    int mid = (i + j) / 2;
    merge_sort(i, mid);
    merge_sort(mid + 1, j);
    
    int en1 = mid + 1, en2 = j + 1, st1 = i, st2 = mid + 1, M = 1 << 30, k = i;
    while(st1 < en1 && st2 < en2){
        if(si[st1] < si[st2]){
            M = min(M, si[st1].second);
            b[k] = si[st1];
            st1++, k++;
        }else{
            b[k] = si[st2];
            if(M < 1 << 30)ans[si[st2].second] = max(ans[si[st2].second], si[st2].second - M);
            st2++, k++;
        }
    }
    while(st1 < en1){
        b[k] = si[st1];
        st1++, k++;
    }
    while(st2 < en2){
        b[k] = si[st2];
        if(M < 1 << 30)ans[si[st2].second] = max(ans[si[st2].second], si[st2].second - M);
        st2++, k++;
    }
    for(int x = i; x <= j; x++)si[x] = b[x];
}
int main(){
    scanf("%s", s);
    
    N = strlen(s);
    for(int i = 0; i < N; i++){
        if(isvowel(s[i]))p[i] = -1;
        else p[i] = 2;
    }
    si[0] = make_pair(0, 0);
    for(int i = 0; i < N; i++)
        si[i + 1] = make_pair(si[i].first + p[i], i + 1);
    ans.resize(N + 1);
    merge_sort(0, N);
    
    int best = *max_element(ans.begin(), ans.end());
    int c = count(ans.begin(), ans.end(), best);
    
    if(best == 0)printf("No solution\n");
    else printf("%d %d\n", best, c);
    return 0;
}