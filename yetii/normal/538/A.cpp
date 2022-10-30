//
//         ."".    ."",
//         |  |   /  /
//         |  |  /  /
//         |  | /  /
//         |  |/  ;-._ 
//         }  ` _/  / ;
//         |  /` ) /  /
//         | /  /_/\_/\
//         |/  /      |
//         (  ' \ '-  |
//          \    `.  /
//           |      |
//           |      |
//

#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <numeric>
using namespace std;
typedef long long ll;

int main()
{
    string s, T="CODEFORCES", rs="NO";
    cin>>s;
    for (int l=0;l<s.size();++l) for (int r=l+1;r<=s.size();++r)
    {
        string z;
        for (int i=0;i<l;++i) z+=s[i];
        for (int i=r;i<s.size();++i) z+=s[i];
        if (z==T) rs="YES";
    }
    cout<<rs<<endl;
    return 0;
}