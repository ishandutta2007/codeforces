#include <iostream>
#include <map>
using namespace std;

map<int, int> numbers;

int main()
{
    int n, k;
    cin >> n >> k;
    //memset(metido, 0, sizeof(metido));
    
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        numbers[a]=1;
    }
    
    map<int, int>::iterator it;
    int ans=0;
    for(it=numbers.begin(); it!=numbers.end(); it++)
    {
        if((it->first)%k!=0 || numbers[(it->first)/k]!=2)
        {
            ans++;
            numbers[it->first]=2;
        }
    }
    cout << ans << endl;
}