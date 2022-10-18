//In the name of allah
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map <string,int> database;
    int n;
    cin >> n;
    string a[n],s;
    for (int i =0;i<n;i++){
        cin >> s;
        a[i] = s;
    }
    for (int i =0;i<n;i++){
        if(database.count(a[i])){
            cout << a[i] << database[a[i]] << '\n';
            database[a[i]]++;
        }
        else{
            cout << "OK" << '\n';
            database[a[i]] = 1;
        }
    }
}