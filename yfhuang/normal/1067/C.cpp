#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        if(i % 3 == 0){
            int x = (i / 3) * 2;
            int y = 0;
            cout << x << " " << y << endl;
        }else if(i % 3 == 1){
            int x = (i / 3) * 2 + 1;
            int y = 0;
            cout << x << " " << y << endl;
        }else{
            int x = (i / 3) * 2 + 1;
            int y = 3;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}