#include <iostream>
#include <string>
using namespace std;
int main()
{
    char v[] = {'a','o','u','e','i'};
    string a;
    int time = 1;
    for (int j =0;j<3;j++){
        getline(cin,a);
        int ans = 0;
        for(int i =0;i<a.size();i++){
            if (a[i] == ' ')continue;
            else{
                for (int n = 0;n<5;n++){
                    if (v[n] == a[i]){
                        ans++;
                        break;
                    }
                }
            }
        }
        if (j == 0 || j == 2){
            if (ans == 5)continue;
            else {
                cout << "NO";
                return 0;
            }
        }
        else{
            if (ans == 7)continue;
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}