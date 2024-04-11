#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;
const int MAX_M = 1e5 + 6;

vector<int> edg[MAX_N];
int cnt[MAX_N];



int main (){
    int n,m;
    while (scanf("%d %d",&n,&m) != EOF) {
        for (int x=0;n>=x;x++) {
            edg[x].clear();
        }
        memset(cnt,0,sizeof(cnt));
        for (int x=0;m>x;x++) {
            int i,j;
            scanf("%d %d",&i,&j);
            cnt[i]++;
            cnt[j]++;
        }
        if (n == m+1) {
            int _1=0;
            int _2=0;
            for (int i=1;n>=i;i++) {
                if (cnt[i] == 1) _1++;
                if (cnt[i] == 2) _2++;
            }
            if (_2 == n-2) puts("bus topology");
            else if (_1 == n-1) puts("star topology");
            else puts("unknown topology");
        }
        else if (n==m){
            int _2=0;
            for (int i=1;n>=i;i++) {
                if (cnt[i] == 2) _2++;
            }
            if (_2 == n) puts("ring topology");
            else puts("unknown topology");
        }
        else puts("unknown topology");
    }
}