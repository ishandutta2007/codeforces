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
int n, v[3005], a, b, d[3005], p[3005], q[3005], qs, qe, A[3005];
void calc(int i){
    if(A[i] == -1){
        calc(p[i]);
        A[i] = 1 + A[p[i]];
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        a--; b--;

        v[a] ^= b;
        v[b] ^= a;
        d[a]++;
        d[b]++;
    }
    for(int i = 0; i < n; i++)
        if(d[i] == 1)q[qe++] = i;
    while(qs < qe){
        int t = q[qs++];
        
        A[t] = -1;
        p[t] = v[t];
        v[p[t]] ^= t;
        d[p[t]]--;
        if(d[p[t]] == 1)
            q[qe++] = p[t];
    }
    for(int i = 0; i < n; i++){
        calc(i);
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}