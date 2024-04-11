#include<bits/stdc++.h>
using namespace std;
int main()  {
    int T;
    cin>>T;
    while (T--) {
        string s;
        cin>>s;
        int a=0,b=0;
        for (char c:s)
            if (c=='0')
                ++a;
            else
                ++b;
        int cnt=min(a,b);
        cout<<(cnt&1?"DA":"NET")<<endl;
    }
    return 0;
}