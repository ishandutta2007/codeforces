#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int maxhossz;
int calculation(char x)
{
    int maxh=0;
    int veg=0;
    int db=0;
    for(int i=0; i<s.size(); i++)
    {
        while(veg<s.size() && db<=k)
        {
            if(s[veg]==x) db++;
            veg++;
        }
        int meddig=veg-1;
        if(db<=k) meddig=s.size();
        if(s[i]==x) db--;
        int h=meddig-i;
        maxh=max(maxh, h);
    }
    return maxh;
}
int main() {
    cin>>n>>k;
    cin>>s;
    cout<<max(calculation('a'), calculation('b'))<<endl;
    return 0;
}