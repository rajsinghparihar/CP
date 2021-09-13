#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int x[n];
    int y[n];
    set<pair<int, int>> points;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        pair<int, int> p = make_pair(x[i], y[i]);
        points.insert(p);
    }

    int answer = 0;

    for (auto i = points.begin(); i != std::prev(points.end()); i++)
    {
        for (auto j = i; j != points.end(); j++)
        {
            pair<int, int> p1 = *i;
            pair<int, int> p2 = *j;

            if (p1.first == p2.first || p1.second == p2.second)
                continue;

            pair<int, int> p3 = make_pair(p1.first, p2.second);
            pair<int, int> p4 = make_pair(p2.first, p1.second);

            if (points.find(p3) != points.end() && points.find(p4) != points.end())
                ++answer;
        }
    }

    cout << answer / 2 << endl;
    return 0;
}