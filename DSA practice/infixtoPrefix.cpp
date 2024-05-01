#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }

    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else{
        return -1; 
    }
}

string InfixToPrefix(string s)
{
    reverse(s.begin(),s.end());
    stack<char> st;
    string res;

    for(int idx =0;idx<s.length(); idx++)
    {
        if((s[idx] >= 'a' && s[idx] <= 'z') || (s[idx] >= 'A' && s[idx] <= 'Z'))
        {
            res+= s[idx];
        }
        else if(s[idx] == ')')
        {
            st.push(s[idx]);
        }
        else if(s[idx] == '(')
        {
            while(!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }

            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && prec(st.top()) > prec(s[idx]))
            {
                res += st.top();
                st.pop(); 
            }
            st.push(s[idx]);
        }

    }

    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
    return res;

}

int main()
{
    cout<<InfixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}