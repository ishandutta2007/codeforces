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
int N, K;
string s;
int main(){
    cin >> N >> K >> s;
    for(int i = 0; i < N; i++){
        if(K == 0)break;
        if((i + 1) % 2 != 0){
            if(i < N - 1 && s[i] == '4' && s[i + 1] == '7'){
                s[i] = s[i + 1] = '4';
                K--;
            }
        }else{
            if(i < N - 1 && s[i] == '4' && s[i + 1] == '7'){
                if(i > 0 && s[i - 1] == '4'){
                    if(K % 2 != 0)s[i] = s[i + 1] = '7';
                    break;
                }else{
                    s[i] = s[i + 1] = '7';
                    K--;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}