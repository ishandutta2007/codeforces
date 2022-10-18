//In the name of allah
#include <iostream>
#include <string>

using namespace std;
int main ()
{
    string a;
    cin >> a;
    a.replace((int)a.find("at",1),2,"@");
    for (int i =1;i<a.size()-3;i++)if (a[i] == 'd' && a[i+1] == 'o' && a[i+2] == 't')a.replace(i,3,".");
    cout << a;
}