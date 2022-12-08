#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <string> numbers(N);

    for(int i=0; i<N; i++)
    cin >> numbers[i];

    sort(numbers.begin(),numbers.end());

    int c=0;
    while(c<numbers[0].size() && numbers[0][c]==numbers[N-1][c])
    c++;

    cout << c << endl;
}