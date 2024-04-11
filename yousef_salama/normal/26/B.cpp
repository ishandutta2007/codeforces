//In the name of allah
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string a;
    int ans = 0;
    stack <int> moves;
    cin >> a;
    for (int i =0;i<a.size();i++){
        if (a[i] == '('){
            moves.push('(');
        }
        else{
            if (!moves.empty()){
            ans += 2;
            moves.pop();
        }
    }
    }
    cout << ans;
}