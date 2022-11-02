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
#include <random>
#include <chrono>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << -1 << endl;
        }else{
            for(int i = n;i > 2;i--){
                printf("%d", 9);
            }
            printf("89\n");
        }
    }
    return 0;
}