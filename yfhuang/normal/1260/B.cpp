#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int a, b;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a >> b;
        bool flag = true;
        if((a + b) % 3)
            flag = false;
        if(a > 2 * b or b > 2 * a)
            flag = false;
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}