#include<iostream>
#include<vector>
using namespace std;
void dfs(int index, vector<int> temp, int n, int k, vector<vector<int>> &ans, vector<bool> visited)
{
    if (temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i <= n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        temp.push_back(i);
        dfs(i + 1, temp, n, k, ans, visited);
        temp.pop_back();
        visited[i] = false;
        cout<<i<<endl;
    }
}
int main()
{
    int n,k;
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(n + 1, false);
    cin>>n>>k;
    if (n == k){
        for(int i=1;i<=n;i++){
            temp.push_back(i);
        }
        return 0;
    }
    dfs(1, temp, n, k, ans, visited);
    return 0;
}