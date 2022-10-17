#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair < int , int > pii;
#define mp make_pair

const int MN = 2e6 + 5;

set < pii > s;
queue < pii > qq;
int ban[MN] , tim;

int main() {
    
    int q; scanf("%d" , &q);
    for (int i = 1; i <= q; ++i) {
       int op , x;
       scanf("%d" , &op); if (op == 1) scanf("%d" , &x);
       if (op == 1) { ++tim;
          qq.push(mp(x , -tim));
          s.insert(mp(x , -tim));
       } else if (op == 2) {
          while (ban[-qq.front().second]) qq.pop();
          printf("%d " , -qq.front().second);
          ban[-qq.front().second] = 1;
          qq.pop();
       } else {
          while (ban[abs((*s.rbegin()).second)]) s.erase(*s.rbegin());
	  ban[abs((*s.rbegin()).second)] = 1;
          printf("%d " ,  -(*s.rbegin()).second);
          s.erase(*s.rbegin());
       }
    } 
    return 0;
}