#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string s, t;

int main()
{
    int i, j, cnt, len, t1, t2;
    cin >> s;
    j = cnt = 0;
    len = s.size();
    for (i = 0; i < len; i++)
    {
        t = s.substr(i, 4); 
        if (t == "bear")
        {
            cnt++;   
            if (i == 0)     
                t1 = len-1-(i+3);  
            else
            {
                t2 = len-1-(i+3);        
                t1 = (i-j) * t2 + i-j + t2;  
            }
            cnt += t1;
            j = i+1;    
            i += 3;    
        }
    }
    printf("%d\n", cnt);
    return 0;
}