//In the name of allah
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    int a;
    cin >> a;
    for (int i =a;i>0;i--)
        if (a%i == 0){
            cout << i << ' ';
            a = i;
    }
}