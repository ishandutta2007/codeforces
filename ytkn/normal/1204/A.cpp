#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int l = s.size();
    int cnt = 0;
    if(s.size()%2 ==0){
        cout << s.size()/2 << endl;
        return 0;
    }
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '1') cnt++;
    }
    if(cnt == 0){
        cout << s.size()/2 << endl;
    }else{
        cout << (s.size()+1)/2 << endl;
    }
}