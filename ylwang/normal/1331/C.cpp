#include<bits/stdc++.h>
using namespace std;

    int s[69];
int main(){
    int n;
    cin >> n;
    while(n>0){     //
        s[++s[0]] = n%2;
        n/=2;
    }
    swap(s[1],s[5]);
    swap(s[3],s[4]);        //
    int ans=0;
    for(int i=64; i>0; i--)
        ans = ans*2+s[i];   //
    cout << ans << endl;
    return 0;
}