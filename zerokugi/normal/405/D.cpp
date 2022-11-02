#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n;
int d[1000001];
main(){
    scanf("%d", &n);
    REP(i, n){
        int x;
        scanf("%d", &x);
        d[x] = 1;
    }
    int t=0;
    REP(i, 1000000){
        if(d[i+1]==1){
            if(d[1000000-i]==1) t++;
            else d[1000000-i] = -1;
        }
    }
    REP(i, 1000000){
        if(!t) continue;
        if(!d[i+1]){
            d[i+1] = d[1000000-i] = -1;
            t-=2;
        }
    }
    printf("%d\n", n);
    REP(i, 1000000){
        if(d[i+1] == -1) printf("%d ", i+1);
    }
    puts("");
    return 0;
}