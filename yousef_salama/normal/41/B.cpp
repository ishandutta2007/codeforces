#include <iostream>
using namespace std;
int main(){
    int n, b;
    cin >> n >> b;
    int a[n], Max = b;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        int martian = b / a[i];
        int bourles = b - (martian * a[i]);
        for (int j = i; j < n; j++)
            Max = max(Max, bourles + (martian * a[j]));
    }
    cout << Max << endl;
}