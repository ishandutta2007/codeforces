#include <iostream>
#include <string>
using namespace std;

int main()
{
    string names[40]={"Washington","Adams","Jefferson","Madison","Monroe","Adams","Jackson",
    "Van Buren","Harrison","Tyler","Polk","Taylor","Fillmore","Pierce","Buchanan","Lincoln",
    "Johnson","Grant","Hayes","Garfield","Arthur","Cleveland","Harrison","Cleveland","McKinley",
    "Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt","Truman","Eisenhower",
    "Kennedy","Johnson","Nixon","Ford","Carter","Reagan"};

    int k;
    cin >> k;
    cout << names[k-1] << endl;
}