//In the name of allah
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#define v for(int i=0;i<n;i++)
using namespace std;
int main(){
    int n,ans=0;
    cin >> n;
    string bad[] = { "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    string a;
    v{
        int wrong = 0;
        cin >> a;
        if (isalpha(a[0])){
            for (int j=0;j<11;j++){
                if(a == bad[j])
                    wrong = 1;
            }
            if (wrong)
                ans ++;
        }
        else{
            int r;
            r = atoi(a.c_str());
            if(r < 18)
                ans++;
        }
    }
    cout << ans;
}