//In the name of allah
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main (){
    int n,x,found = 0;
    cin >> n;
    int a[n];
    for (int i =0;i<n;i++){
        cin >> x;
        a[i] = x;
    }
    for(int i =0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int s=0;s<n;s++){
                if((a[i] + a[j]) == a[s]){
                    cout << s+1 << " " << j+1 << " " << i+1;
                    found = 1;
                    break;
                }
            }
            if (found)break;
        }
        if (found)break;
    }
    if (!found)cout << -1;
}