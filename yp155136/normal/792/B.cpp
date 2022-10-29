#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX_N = 106;

int a[MAX_N];

int main () {
    int n,k;
    while (scanf("%d %d",&n,&k) != EOF) {
        vector<int> v;
        for (int i=1;n>=i;i++) {
            v.push_back(i);
        }
        for (int i=1;k>=i;i++) {
            scanf("%d",&a[i]);
        }
        int now=0;
        for (int i=1;k>=i;i++) {
            now += a[i];
            now %= v.size();
            printf("%d",v[now]);
            v.erase(v.begin()+now);
            if (i!=k) printf(" ");
        }
        puts("");
    }
}