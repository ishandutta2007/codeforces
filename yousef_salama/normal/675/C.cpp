//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int n;
long long a[100005];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
        
    map <long long, int> m;
        
    int x = 0;
    for(int i = 0; (i + 1) < n; i++){
        if(a[i] != 0)x++;
        
        //cout << a[i] << ' ';
        
        m[a[i]]++;
        a[i + 1] += a[i];
    }
    //cout << endl;
    
    int y = n - 1;
    for(map <long long, int> :: iterator d = m.begin(); d != m.end(); d++)
        y = min(y, (n - 1) - d->second);
        
    printf("%d\n", min(x, 1 + y));
    
    return 0;
}