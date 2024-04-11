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

int n, m, Li, Ri, cnti, qpi, pi;
vector <int> v[1000005];

vector <int> tree[4 * 1000005];

void build_tree(int i, int L, int R){
    if(L == R){
        for(int j = 0; j < v[L].size(); j++)
            tree[i].push_back(v[L][j]);
        sort(tree[i].begin(), tree[i].end());
        return;
    }
    
    int mid = (L + R) / 2;
    build_tree(2 * i, L, mid);
    build_tree(2 * i + 1, mid + 1, R);
    
    merge(tree[2 * i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(), tree[2 * i + 1].end(), 
            back_inserter(tree[i]));
}

int query(int i, int L, int R, int qL, int qR, int k){
    if(qL <= L && R <= qR){
        return tree[i].size() - (lower_bound(tree[i].begin(), tree[i].end(), k) - tree[i].begin());
    }else if(R < qL || qR < L)return 0;
    else{
        int mid = (L + R) / 2;
        return query(2 * i, L, mid, qL, qR, k) + query(2 * i + 1, mid + 1, R, qL, qR, k);
    }
}
//void print(int i, int L, int R){
//    cout << L << ',' << R << ':';
//    for(int j = 0; j < tree[i].size(); j++)
//        cout << tree[i][j] << ' ';
//    cout << endl;
//    
//    if(L == R)return;
//    
//    int mid = (L + R) / 2;
//    print(2 * i, L, mid);
//    print(2 * i + 1, mid + 1, R);
//}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &Li, &Ri);
        Li--, Ri--;

        v[Li].push_back(Ri);
    }
    
    build_tree(1, 0, 1000003);
//    print(1, 0, 10);
    
    while(m--){
        qpi = -1;
        scanf("%d", &cnti);
        
        int res = 0;
        for(int i = 0; i < cnti; i++){
            scanf("%d", &pi);
            pi--;
            
            res += query(1, 0, 1000003, qpi + 1, pi, pi);
            qpi = pi;
        }
        printf("%d\n", res);
    }
    return 0;
}