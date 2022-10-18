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
#include <bitset>
using namespace std;
int N, cnt[2];
string s;
int main(){
    scanf("%d", &N);
    cin >> s;
    for(int d = 0; d <= 1; d++)
        for(int i = 0; i < N; i++)
            if(s[i] != (((i + d)&1) + '0'))cnt[d]++;
    cout << min(cnt[0], cnt[1]) << endl;
    return 0;
}