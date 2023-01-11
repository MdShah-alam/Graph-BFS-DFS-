#include<bits/stdc++.h>
using namespace std;

char first(string s, int i=0)
{
    if(s[i]=='\0')
        return 0;
    if(isupper(s[i]))
        return s[i];
    return first(s,++i);
}

int main()
{
    string s;
    cin>>s;
    char res=first(s);
    if(res==0)
        cout<<"There is no any upper case letter .";
    else
        cout<<res;
    return 0;
}
