#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int x,y;
   while (cin >> x >> y) {
       int num[3] = {y,y,y};
       int ans=0;
       while (num[0] < x) {
           ans++;
           sort(num,num+3);
           num[0]=num[1]+num[2]-1;
           sort(num,num+3);
       }
       cout<<ans<<endl;
   }
}