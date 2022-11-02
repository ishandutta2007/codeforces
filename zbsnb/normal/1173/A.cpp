#include<iostream>
using namespace std;



int main() {
int a, b, c; cin >> a >> b >> c;
if (a > b + c)cout << "+" << endl;
else if (b > a + c)cout << "-" << endl;
else if (c == 0 && a == b)cout << "0" << endl;
else cout << "?" << endl;
}