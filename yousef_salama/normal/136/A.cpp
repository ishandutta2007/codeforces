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
#include <cstring>
#include <sstream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int a[N], P;
    memset(a, 0, sizeof a);
    for(int i = 0; i < N; i++){
        cin >> P;
        a[P - 1] = i + 1;
    }
    for(int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}