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

int n;
set < pair <int, int> > s;
pair <int, int> a[10005];
void solve(int i, int j){
    if(j - i + 1 > 1){
        int mid = (i + j) / 2;
        for(int k = i; k <= j; k++)
            s.insert(make_pair(a[mid].first, a[k].second));
        
        solve(i, mid - 1);
        solve(mid + 1, j);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i].first, &a[i].second);
        s.insert(a[i]);
    }
    sort(a, a + n);
    
    solve(0, n - 1);
    printf("%d\n", s.size());
    for(set < pair <int, int> > :: iterator d = s.begin(); d != s.end(); d++)
        printf("%d %d\n", (*d).first, (*d).second);
    return 0;
}