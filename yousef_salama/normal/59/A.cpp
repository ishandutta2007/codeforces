//in the name of allah
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string word;
    cin >> word;
    int s=0,b=0;
    int n = word.size();
    for (int i=0;i<n;i++){
        if (isupper(word[i]))
            b++;
        else if (islower(word[i]))
            s++;
    }
    if (b > s){
        for (int i=0;i<n;i++){
            word[i] = toupper(word[i]);
        }
    }
    else{
        for (int i=0;i<n;i++){
            word[i] = tolower(word[i]);
        }
    }
    cout << word;
}