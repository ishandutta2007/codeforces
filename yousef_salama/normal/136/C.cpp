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
    int a[N], Max = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] > a[Max])
            Max = i;
    }
    if(a[Max] == 1)a[Max] = 2;
    else a[Max] = 1;
    sort(a, a + N);
    for(int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}