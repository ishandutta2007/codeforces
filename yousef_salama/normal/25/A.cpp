//in the name of allah
#include <iostream>
#include <string>
#include <cctype>
#define v for(int i=0;i<n;i++)
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int indexi=-1,indexj=-1,wrong;
    v{
        int x;
        cin >> x;
        a[i] = x;
    }
    v{
        if (a[i] % 2 == 0){
            if (indexi == -1)
                indexi = i;
            else
                indexi = -2;
        }
        else{
            if (indexj == -1)
                indexj = i;
            else
                indexj = -2;
        }
    }
    int ans = max(indexi,indexj);
    cout << ans + 1;
}