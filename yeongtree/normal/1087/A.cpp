#include <iostream>
#include <string>

using namespace std;

int main()
{
    string t; cin>>t;
    int n = t.size();
    int left=0; int right=n-1;
    bool isLeft = (n % 2);
    string ans;
    while(left<=right)
    {
        if(isLeft) {ans = t[left] + ans; ++left;}
        else {ans = t[right] + ans; --right;}
        isLeft = !isLeft;
    }
    cout<<ans<<endl;
    return 0;
}