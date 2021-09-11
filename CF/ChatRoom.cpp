#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;
    cin >> s;
    stack<char> st;
    int n = s.length();
    st.push('o');
    st.push('l');
    st.push('l');
    st.push('e');
    st.push('h');
    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
    }
    if (st.empty() == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

// 4 7 44 47 74 77 444 447 474 477 744 747 774 777