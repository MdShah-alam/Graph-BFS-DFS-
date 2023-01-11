#include<bits/stdc++.h>
using namespace std;

void int_to_binary(int n)
{
    if(n==0 || n==1)
    {
        cout<<n;
        return ;
    }
    int_to_binary(n/2);
    int_to_binary(n%2);
}

int main()
{
    int n;
    cin>>n;
    int_to_binary(n);
    return 0;
}
