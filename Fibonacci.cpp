#include<bits/stdc++.h>
using namespace std;

int get_fibonacci(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return get_fibonacci(n-1)+get_fibonacci(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<get_fibonacci(n)<<endl;
    return 0;
}
