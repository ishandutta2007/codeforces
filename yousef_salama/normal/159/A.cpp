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
int n, d, t[1005], id = 0;
bool g[1005][1005];
string A[1005], B[1005];
set < pair <string, string> > S;
int main(){
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> t[i];
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
        if(A[i] == B[j] && B[i] == A[j])
            if(0 < t[j] - t[i] && t[j] - t[i] <= d){
                if(A[i] < B[i])S.insert(make_pair(A[i], B[i]));
                else S.insert(make_pair(B[i], A[i]));
            }
    cout << S.size() << endl;
    for(set < pair <string, string> > :: iterator it = S.begin(); it != S.end(); it++)
        cout << it->first << ' ' << it->second << endl;
    return 0;
}