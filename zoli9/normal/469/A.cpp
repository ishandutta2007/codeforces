#include <iostream>
using namespace std;
int n;
int x1, y1;
int x[101];
int y[101];
int w[101];
int main()
{
   cin>>n;
   for(int i=1; i<=n; i++)
   {
       w[i]=0;
   }
   cin>>x1;
   for(int i=1; i<=x1; i++)
   {
       cin>>x[i];
       w[x[i]]++;
   }
   cin>>y1;
   for(int i=1; i<=y1; i++)
   {
       cin>>y[i];
       w[y[i]]++;
   }

   for(int i=1; i<=n; i++)
   {
       if(w[i]==0)
       {
           cout<<"Oh, my keyboard!";
           return 0;
       }
   }
   cout<<"I become the guy.";

    return 0;
}