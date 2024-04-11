#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long tmp = n;
    vector<long long> div;
    for(int i = 2; 1LL * i * i <= n;i++){
        if(tmp % i == 0){
            while(tmp % i == 0){
                tmp /= i;
            }
            div.push_back(i);
        }
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(tmp > 1)
        div.push_back(tmp);
    if(div.size() > 1){
        cout << 1 << endl;
    }else{
        cout << div[0] << endl;
    }
    return 0;
}