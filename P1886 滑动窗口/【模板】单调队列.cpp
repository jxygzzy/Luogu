#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int num, val;
};
deque<node> q_min, q_max;
vector<int> ans1, ans2;
int n, k, temp;
node now;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        now.num = i;
        now.val = temp;
        while (!q_min.empty() && temp <= q_min.back().val)
        {
            q_min.pop_back();
        }
        while (!q_max.empty() && temp >= q_max.back().val)
        {
            q_max.pop_back();
        }
        q_min.push_back(now);
        q_max.push_back(now);
        while (i - k >= q_min.front().num)
        {
            q_min.pop_front();
        }
        while (i - k >= q_max.front().num)
        {
            q_max.pop_front();
        }
        if (i >= k)
        {
            ans1.push_back(q_min.front().val);
            ans2.push_back(q_max.front().val);
        }
    }
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    return 0;
}