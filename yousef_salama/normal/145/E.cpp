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
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <numeric>
using namespace std;
int n, m, x[4 * 1000005], L, R;
char s[1000005];
struct node{
    int c4, c7, c47, c74;
    node(){
        c4 = c7 = c47 = c74 = 0;
    }
};
vector <node> tree;
void push(int i){
    if(x[i]){
        x[i] = 0;

        swap(tree[i].c4, tree[i].c7);
        swap(tree[i].c47, tree[i].c74);
        if(2 * i < 4 * n + 5)x[2 * i] ^= 1;
        if(2 * i + 1 < 4 * n + 5)x[2 * i + 1] ^= 1;
    }
}
void update(int i, int left, int right, int a, int b){
    push(i);
    if(b < left || right < a)return;
    if(a <= left && right <= b){
        x[i] ^= 1;
        push(i);
        
        return;
    }
    int mid = (left + right) / 2;
    update(2 * i, left, mid, a, b);
    update(2 * i + 1, mid + 1, right, a, b);
    
    tree[i].c4 = tree[2 * i].c4 + tree[2 * i + 1].c4;
    tree[i].c7 = tree[2 * i].c7 + tree[2 * i + 1].c7;
    tree[i].c47 = max((tree[2 * i].c4 + tree[2 * i + 1].c47), (tree[2 * i].c47 + tree[2 * i + 1].c7));
    tree[i].c74 = max((tree[2 * i].c74 + tree[2 * i + 1].c4), (tree[2 * i].c7 + tree[2 * i + 1].c74));
}
void build(int i, int left, int right){
    if(left == right){
        tree[i].c4 = 1;
        tree[i].c7 = 0;
        tree[i].c47 = 1;
        tree[i].c74 = 1;
    }else{
        int mid = (left + right) / 2;
        build(2 * i, left, mid);
        build(2 * i + 1, mid + 1, right);

        tree[i].c4 = right - left + 1;
        tree[i].c7 = 0;
        tree[i].c47 = right - left + 1;
        tree[i].c74 = right - left + 1;
    }
}
int main(){
    scanf("%d %d %s", &n, &m, s);
    tree.resize(4 * n + 5);    

    build(1, 0, n - 1);
    for(int i = 0; i < n; i++)
        if(s[i] == '7')update(1, 0, n - 1, i, i);
    
    while(m--){
        scanf("%s", s);
        if(s[0] == 'c')printf("%d\n", tree[1].c47);
        else{
            scanf("%d %d", &L, &R);
            L--, R--;
            update(1, 0, n - 1, L, R);
        }
    }
    return 0;
}