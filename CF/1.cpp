#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    stack<int> st;
    vector<int> pos;
    vector<int> ans(n);
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            st.push(A[i] * A[i]);
        }
        else
            pos.push_back(A[i] * A[i]);
    }
    while (!st.empty())
    {
        int x = st.top();
        neg.push_back(x);
        st.pop();
    }
    int j = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (pos[k] < neg[j])
        {
            ans[i] = pos[k];
            k++;
        }
        else
        {
            ans[i] = neg[j];
            j++;
        }
    }
    // if (m == pos.size())
    // {
    //     for (int i = m; i < max(pos.size(), neg.size()); i++)
    //     {
    //         ans[j] = neg[i];
    //         j++;
    //     }
    // }
    // if (m == neg.size())
    // {
    //     for (int i = m; i < max(pos.size(), neg.size()); i++)
    //     {
    //         ans[j] = pos[i];
    //         j++;
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}