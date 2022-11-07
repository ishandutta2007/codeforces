#include <iostream>

using namespace std;

char vstup[100];
int n, cis[10];

void nacti();
void vyres();

int main()
{
    nacti();
    vyres();
    return 0;
}
void nacti()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>vstup[i];
}
void vyres()
{
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        if(vstup[i] == '1')
            x++;
        else
        {
            cout<<x;
            x = 0;
        }
    }
    cout<<x<<endl;
}