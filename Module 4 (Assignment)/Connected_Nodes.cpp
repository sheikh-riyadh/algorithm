#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    vector<int> nodes;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        nodes.clear();
        int src;
        cin >> src;

        if (v[src].size() == 0)
        {
            cout << -1;
        }

        for (int children : v[src])
        {
            nodes.push_back(children);
        }

        sort(nodes.begin(), nodes.end(), greater<int>());

        for (int result : nodes)
        {
            cout << result << " ";
        }
        cout << endl;
    }

    return 0;
}
