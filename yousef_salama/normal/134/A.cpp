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
    int a[N];
    for(int i = 0; i < N; i++)
        cin >> a[i];
    vector <int> ans;
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += a[i];
    for(int i = 0; i < N; i++){
        if((sum - a[i])% (N - 1) == 0 && (sum - a[i]) / (N - 1) == a[i]){
            ans.push_back(i);
        }
    }
    if(ans.empty())cout << 0 << endl;
    else{
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << ' ';
        cout << endl;
    }
    return 0;
}