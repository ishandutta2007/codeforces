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
int N, a, b, c;
int main(){
//    while(true){
        cin >> N >> a >> b >> c;
        int ans = 0;
        for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
            if(a * i + b * j <= N)
                if((N - (a * i + b * j)) % c == 0)
                    ans = max(ans, i + j + (N - (a * i + b * j)) / c);

        cout << ans << endl;
//    }
    return 0;
}