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

int t;

typedef long long LL;

LL k;

LL calc(vector<int> digit){
    int j = 0;
    LL ans = 1;
    for(int i = 2;i < 2 + digit.size();i++){
        while(j < digit.size() and digit[j] < i){
           j++; 
        }
        int cur = i - 2;
        int num = max(0, j - cur);
        //cout << num << " " << ans << endl;
        ans = ans * num;
        //cout << ans << endl;
    }
    //cout << ans << endl;
    for(int i = 0, j = 0;i < digit.size();i = j + 1, j = i){
        while(j + 1 < digit.size() and digit[j + 1] == digit[i]){
            j++;
        }
        LL div = 1;
        for(int k = i;k <= j;k++){
            div *= (k - i + 1);
        }
        //cout << div << endl;
        ans /= div;
    }
    return ans;
}

int main(){
    cin >> t;
    while(t--){
        cin >> k;
        vector<int> digit(0);
        for(int i = 2;k != 0;i++){
            int dig = k % i;
            k /= i;
            digit.push_back(dig);
        }
        sort(digit.begin(), digit.end());
        LL ans = calc(digit);
        if(digit[0] == 0){
            vector<int> digit1 = digit;
            digit1.erase(digit1.begin());
            ans -= calc(digit1);
        }
        cout <<  ans - 1 << endl;
    }
    return 0;
}