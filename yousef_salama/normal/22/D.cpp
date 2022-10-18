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
using namespace std;
int n, en, st;
pair <int, pair <int, int> > a[2005];
stack <int> s;
bool removed[1005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &st, &en);
        if(en < st)swap(st, en);
        a[2 * i] = make_pair(st, make_pair(0, i));
        a[2 * i + 1] = make_pair(en, make_pair(1, i));
    }
    sort(a, a + (2 * n));
    vector <int> ans;
    for(int i = 0; i < 2 * n; i++)if(!removed[a[i].second.second]){
        if(a[i].second.first){
            ans.push_back(a[i].first);
            while(!s.empty()){
                int t = s.top();
                s.pop();
                
                removed[t] = true;
            }
        }else s.push(a[i].second.second);
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}