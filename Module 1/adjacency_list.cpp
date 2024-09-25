#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, e;
    cin >> n >> e;
    vector<int> lst[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }

    /* এখানে lst[3] বলতে array 3 index এর সাথে কারা কারা connect আছে সেগুলো দেখবো যেহেতু আমাদের array 
    প্রতিতি index এর মধ্যে একটি করে vector আছে এর জন্য lst[3].size() আমরা যদি 1 index এর মধ্যে কারা আছে সেগুলো
    বের করতে চাইতাম তাহলে lst[1].size() ব্যাবহার করতাম 
    ।
     */
    for (int i = 0; i < lst[3].size(); i++)
    {
        cout << lst[3][i] << " ";
    }

    return 0;
}