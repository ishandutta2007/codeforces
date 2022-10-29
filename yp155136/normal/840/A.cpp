#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

int a[MAX_N];
int ans[MAX_N];

int main () {
    int n;
    scanf("%d",&n);
    vector<pii> va,vb;
    for (int i=1;n>=i;i++) {
        int x;
        scanf("%d",&x);
        va.push_back(make_pair(x,i));
        a[i] = x;
    }
    for (int i=1;n>=i;i++) {
        int x;
        scanf("%d",&x);
        vb.push_back(make_pair(x,i));
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    reverse(vb.begin(),vb.end());
    for (int i=0;n>i;i++) {
        ans[vb[i].second] = va[i].second;
    }
    for (int i=1;n>=i;i++) {
        if (i!=1) printf(" ");
        printf("%d",a[ans[i]]);
    }
    puts("");
}