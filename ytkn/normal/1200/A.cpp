#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int N;
    cin >> N;
    int status = 0;
    for(int j = 0; j < N; j++){
        char s;
        cin >> s;
        if(s == 'L'){
            for(int i = 9; i >= 0; i--){
                int m = 1<<i;
                if(!(m&status)){
                    status |= m;
                    break;
                }
            }
        }else if(s == 'R'){
            for(int i = 0; i < 10; i++){
                int m = 1<<i;
                if(!(m&status)){
                    status |= m;
                    break;
                }
            }
        }else{
            int n = s-'0';
            int m = 1<<(9-n);
            status -= m;
        }
       // cout << bitset<10>(status) << endl;
    }
    cout << bitset<10>(status) << endl;
}