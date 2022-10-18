#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
using namespace std;
char a[105], b[105], c[105];
int cnt[26];
int main(){
    scanf("%s %s %s", &a, &b, &c);
    for(int i = 0; i < strlen(a); i++)
        cnt[a[i] - 'A']++;
    for(int i = 0; i < strlen(b); i++)
        cnt[b[i] - 'A']++;
    for(int i = 0; i < strlen(c); i++){
        if(cnt[c[i] - 'A'] <= 0){
            printf("NO\n");
            return 0;
        }
        cnt[c[i] - 'A']--;
    }
    bool flag = 0;
    for(int i = 0; i < 26; i++)
        flag |= !(cnt[i] == 0);
    if(flag)printf("NO\n");
    else printf("YES\n");
    return 0;
}