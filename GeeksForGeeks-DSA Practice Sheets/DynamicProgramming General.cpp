#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
// Naive Method
// Time Complexity - O(nk)
// Space Complexity - O(nk)
int M1ComputeCombination(int n, int k)
{
    if (n < k)
    {
        return -1;
    }
    if (n == k || k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }
    vector<vector<int>> T(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    { // why from 0 --> 0c0 1c0 2c0 till n-1c0 all must be 1
        T[i][0] = 1;
    }
    for (int i = 1; i <= k; i++)
    { // why from 1--> 0c0 (already filled in previous for loop)
      // 1c1 2c2 .. n-1cn-1 set as 1
        T[i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (j > k)
            {
                continue;
            }
            T[i][j] = T[i - 1][j] + T[i - 1][j - 1];
        }
    }
    return T[n][k];
}
int M2ComputeCombination(int n, int k)
{
    if (n < k)
    {
        return 0;
    }
    if (n == k || k == 0)
    {
        return 1;
    }
    if (k == 1 || n - k == 1)
    {
        return n;
    }
    vector<int> T(k + 1, 1);
    int temp1, temp2;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (j > k)
            {
                continue;
            }
            if (j == 1)
            {
                temp1 = T[1];
                T[1] += T[0];
            }
            else
            {
                temp2 = T[j];
                T[j] += temp1;
                temp1 = temp2;
            }
        }
    }
    return T[k];
}

int M3computeCombination(int n, int k)
{
    // small optimisations
    if (k > n)
    {
        return 0;
    }
    if (k == 0 || n == k)
    {
        return 1;
    }
    if (k == 1 || n - k == 1)
    {
        return n;
    }
    k = min(n - k, k); // symmetric property -->nCk=nC(n-k)
    vector<int> T(k + 1, 0);
    T[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
        { // using reverse iteration to prevent storing values
            // min(i,k)-->prevent uncessary computations
            T[j] += T[j - 1];
        }
    }
    return T[k];
}

// NOTE DISPENSING PROBLEM
vector<vector<int>> fillTable(vector<int> D, int amount)
{
    vector<vector<int>> T(D.size(), vector<int>(amount + 1));
    for (int i = 0; i < D.size(); i++)
    {
        T[i][0] = 0; // if amount=0 ->no need to dispense any notes
    }
    for (int i = 0; i < D.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (i == 0 && j < D[i])
            {
                T[i][j] = INT_MAX; // if amount is less than minimum denomination(we can't dispense any note)
            }
            else if (i == 0)
            {
                if (T[i][j - D[i]] == INT_MAX)
                {
                    T[i][j - D[i]] -= 1;
                }
                T[i][j] = T[i][j - D[i]] + 1;
                // the note+previous count of notes(for amount-D[i])
            }
            else if (j < D[i])
            {
                T[i][j] = T[i - 1][j];
            }
            else
            {
                // if(T[i][j-D[i]]==INT_MAX){
                //    T[i][j-D[i]]-=1; //no need of this here because +1 occurs only one time
                // all values are INT_MAX-1 -->adding 1 makes it INT_MAX
                // }
                T[i][j] = min(T[i][j - D[i]] + 1, T[i - 1][j]);
            }
        }
    }
    for (int i = 0; i < D.size(); i++)
    {
        printVector(T[i]);
    }
    // if we want to return the total note count then
    // return (T[D.size()-1][amount]>=INT_MAX-4000)?-1:T[D.size()-1][amount];
    return T;
}

void DispenseNotes(vector<vector<int>> &T, vector<int> &D, int row, int amount, vector<int> &Tray)
{
    if (T[row][amount] == 0)
    {
        return;
    }

    if (1 + T[row][amount - D[row]] == T[row][amount])
    {
        Tray.push_back(D[row]);
        return DispenseNotes(T, D, row, amount - D[row], Tray);
    }
    else
    {
        return DispenseNotes(T, D, row - 1, amount, Tray);
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> D = {2, 6, 9, 11, 13};
    vector<vector<int>> T = fillTable(D, 11);
    vector<int> Tray;
    DispenseNotes(T, D, D.size() - 1, 11, Tray);
    printVector(Tray);
    return 0;
}