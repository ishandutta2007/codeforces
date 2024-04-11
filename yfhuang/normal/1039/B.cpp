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
#include <ctime>
using namespace std;

typedef long long LL;

LL n;
int k;

string ask(LL l, LL r){
    cout << l << " " << r << endl;
    fflush(stdout);
    string ret;
    cin >> ret;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    string ans = "haha";
    LL l = 1, r = n;
    srand(time(NULL));
    for(int i = 1;i <= 4500;i++){
        if(r - l + 1 <= 5 * k + 10){
            int offset = rand() % (r - l + 1);
            LL id = l + offset; 
            ans = ask(id, id);
            if(ans == "Yes"){
                break;
            }
        }else{
            LL mid = (l + r) / 2;
            ans = ask(l, mid);
            if(ans == "Yes"){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        l = max(1LL, l - k);
        r = min(n, r + k);
    }
    return 0;
}