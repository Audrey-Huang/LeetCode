#include<iostream>
#include<set>
using namespace std;
void dfs(int row, int n, int &ans, set<int> col, set<int> d1, set<int> d2)
{
    if (row == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (col.find(i) != col.end())
            continue;
        int a = row - i;
        if (d1.find(a) != d1.end())
            continue;
        int b = row + i;
        if (d2.find(b) != d2.end())
            continue;
        col.insert(i);
        d1.insert(row - i);
        d2.insert(row + i);
        dfs(row + 1, n, ans, col, d1, d2);
        col.erase(i);
        d1.erase(row - i);
        d2.erase(row + i);
    }
}
int main()
{
    int n=4;
    if (n == 1)
        return 1;
    int ans;
    set<int> col;
    set<int> d1;
    set<int> d2;
    dfs(0, n, ans, col, d1, d2);
    return ans;
}