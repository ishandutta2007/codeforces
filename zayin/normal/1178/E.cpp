#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n;
char s[maxn];

deque<char> L,R;

int main()  {
    scanf("%s",s+1);
    n=strlen(s+1);
    int l=1,r=n;
    while (l<r) {
        // cout<<l<<" "<<r<<endl;
        if (s[l]==s[r])
            L.push_back(s[l++]),
            R.push_front(s[r--]);
        else    {
            if (l<r-1&&s[l]==s[r-1])
                L.push_back(s[l++]),--r,
                R.push_front(s[r--]);
            else
            if (l+1<r&&s[l+1]==s[r])
                ++l,L.push_back(s[l++]),
                R.push_front(s[r--]);
            else 
            if (l+1<r-1&&s[l+1]==s[r-1])    
                ++l,L.push_back(s[l++]),
                --r,R.push_front(s[r--]);
            else  break;  
        }
    }
    for (char c:L)  putchar(c);
    if (l<=r)   putchar(s[l]);
    for (char c:R)  putchar(c);
    return 0;
}