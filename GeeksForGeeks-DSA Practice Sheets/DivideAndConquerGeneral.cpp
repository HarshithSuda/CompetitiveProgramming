#include <bits/stdc++.h>
using namespace std;

template <typename T>
T max3(T a, T b, T c)
{
    return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d)
{
    return max(max(a, b), max(c, d));
}

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void PrintVectorOfVector(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> temp = v[0];
        for (int j = 0; j < temp.size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
// https://www.geeksforgeeks.org/tiling-problem-using-divide-and-conquer-algorithm/
int cnt = 0;
void place(vector<vector<int>> &m, int a, int b, int c, int p, int q, int r)
{
    //-->placing the L
    cnt++;
    // cout<<"x coordinate :"<<a<<"y coordinate :"<<b<<"\n";
    m[a][p] = cnt;
    m[b][q] = cnt;
    m[c][r] = cnt;
}
void tile(vector<vector<int>> &m, int n, int x, int y)
{
    // m-->matrix,(x,y)-->starting point of cube
    //(r,c)-->empty cell -->marked by -1
    // cnt--> maintaning L shaped cnt throughout the recursion
    // n-->size of matrix(n==2^k form)

    if (n == 2)
    { // base case
        // cout<<"base case triggered"<<endl;
        // cout<<"here x is"<<x<<"y is "<<y<<"count is"<<cnt<<endl;
        cnt++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[x + i][y + j] == 0)
                {
                    m[x + i][y + j] = cnt;
                }
            }
        }
        return;
    }
    int r, c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[x + i][y + j] != 0)
            {
                r = x + i;
                c = y + j;
                break;
            }
        }
    }

    // placing the L shaped tile in the opposite direction of the empty tile
    if (r < x + n / 2 && c < y + n / 2)
    { // 1st quad
        // cout<<"1st quad"<<endl;
        place(m, x + n / 2, x + n / 2, x + n / 2 - 1, y + n / 2, y + n / 2 - 1, y + n / 2);
    }
    else if (r >= x + n / 2 && c < n / 2)
    { // 2nd quad
        // cout<<"2nd quad"<<endl;
        place(m, x + n / 2 - 1, x + n / 2 - 1, x + n / 2, y + n / 2 - 1, y + n / 2, y + n / 2);
    }
    else if (r < x + n / 2 && c >= n / 2)
    { // 4th
        // cout<<"4th quad"<<endl;
        place(m, x + n / 2, x + n / 2, x + n / 2 - 1, y + n / 2, y + n / 2 - 1, y + n / 2 - 1);
    }
    else if (r >= x + n / 2 && c >= n / 2)
    { // 3rd
        // cout<<"3rd quad"<<endl;
        place(m, x + n / 2 - 1, x + n / 2, x + n / 2 - 1, y + n / 2 - 1, y + n / 2 - 1, y + n / 2);
    }

    tile(m, n / 2, x + n / 2, y);
    tile(m, n / 2, x, y);
    tile(m, n / 2, x + n / 2, y + n / 2);
    tile(m, n / 2, x, y + n / 2);
}
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
int mergeCount(vector<int> &arr, int low, int mid, int high)
{
    int c = 0;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> temp1(n1 + 1), temp2(n2 + 1);
    temp1[n1] = INT_MAX;
    temp2[n2] = INT_MAX;

    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }
    int a = 0, b = 0;
    for (int i = low; i <= high; i++)
    {
        if (temp1[a] > temp2[b])
        {
            arr[i] = temp2[b++];
            c += (n1 - a);
        }
        else
        {
            arr[i] = temp1[a++];
        }
    }
    return c;
}

int countInversions(vector<int> &arr, int low, int high)
{
    int res = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        res += countInversions(arr, low, mid);
        res += countInversions(arr, mid + 1, high);
        res += mergeCount(arr, low, mid, high);
    }
    return res;
}
// https://www.geeksforgeeks.org/the-skyline-problem-using-divide-and-conquer-algorithm/
// SKYLINE QUESTION MODIFIED FOR LEETCODE
// GFG-->(X,H,Y)
// LEETCODE-->(X,Y,Z)
// SOLUTION FOR SKYLINE PROBLEM
// M1-->ITERATIVE
vector<vector<int>> findingCornerMinAndMax(vector<vector<int>> arr)
{
    vector<vector<int>> minAndMax;
    minAndMax.push_back({arr[0][0], arr[0][1]}); // 0 and 2 indexes are starting and ending point respectively
    for (int i = 1; i < arr.size(); i++)
    {
        vector<int> t = minAndMax.back();
        if (minAndMax.back()[1] < arr[i][0])
        {
            minAndMax.push_back({arr[i][0], arr[i][1]});
        }
        else
        {
            if (arr[i][1] > minAndMax.back()[1])
            {
                minAndMax.back()[1] = arr[i][1];
            }
        }
    }
    return minAndMax;
}
void CreationOfHeightArray(vector<vector<int>> arr, vector<int> &height, int minn, int maxx)
{
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> t = arr[i];
        for (int j = t[0]; j < t[1]; j++)
        {
            height[j] = max(t[2], height[j]);
        }
    }
    return;
}
vector<vector<int>> skylineProblemMain(vector<vector<int>> arr)
{
    vector<vector<int>> temp = findingCornerMinAndMax(arr);
    int minn = temp[0][0];
    int maxx = temp[temp.size() - 1][1];
    vector<int> height(maxx, 0);
    height.push_back(0);
    CreationOfHeightArray(arr, height, minn, maxx);
    // for(int i=0;i<height.size();i++){
    //     cout<<i<<" "<<height[i]<<" \n";
    // }
    vector<vector<int>> ans;
    for (int i = minn; i <= maxx; i++)
    {
        if (i == 0 && height[0] > 0)
        {
            ans.push_back({i, height[0]});
        }
        else if (height[i] != height[i - 1])
        {
            ans.push_back({i, height[i]});
        }
    }
    return ans;
}

// M2-->DIVIDE AND CONQUER

// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
// DIVIDE AND CONQUER
// M1-efficient but is not 100% optimised(we are starting from index )
pair<int, int> binarySearchForMatrix(vector<int> arr, int x, int low, int high, int q)
{ // x represents row and q represents number to be searched
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == q)
        {
            return {x, mid};
        }
        else if (arr[mid] > q)
        {
            return binarySearchForMatrix(arr, x, low, mid - 1, q);
        }
        else
        {
            return binarySearchForMatrix(arr, x, mid + 1, high, q);
        }
    }
    return {-1, -1};
}
pair<int, int> BetterIndex(pair<int, int> a, pair<int, int> b)
{
    if (a.first == -1)
    {
        return b;
    }
    return a;
}
pair<int, int> matrixSearch(vector<vector<int>> mat, int m, int n, int x, int y, int q)
{ // we need not start from zero all the time
    if (x > m - 1 || y < 0)
    {
        return {-1, -1};
    }
    if (mat[x][y] < q)
    {
        // cout<<" x: "<<x<<" y: "<<y<<endl;
        pair<int, int> index1 = binarySearchForMatrix(mat[x], x, y + 1, n, q);
        pair<int, int> index2 = matrixSearch(mat, m, n, x + 1, y, q);
        return BetterIndex(index1, index2);
    }
    else if (mat[x][y] > q)
    {
        // cout<<" x: "<<x<<" y: "<<y<<endl;
        pair<int, int> index3 = binarySearchForMatrix(mat[x], x, 0, y - 1, q);
        pair<int, int> index4 = matrixSearch(mat, m, y - 1, x + 1, y - 1, q);
        return BetterIndex(index3, index4);
    }
    else
    {
        return {x, y};
    }
}
// M2-->write a for loop for each row and if  key is in the range then perform binary search on that row
// N=MAX(ROW,COL)
// Time Complexity - O(ROW*log(COL))
// Space Complexity - O(1)
pair<int, int> M2binarySearchForMatrix(vector<int> arr, int m, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return {m, mid};
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
pair<int, int> M2MainFunction(vector<vector<int>> &mat, int key)
{
    int n = mat[0].size();
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][0] <= key && mat[i][n - 1] >= key)
        {
            pair<int, int> p = M2binarySearchForMatrix(mat[i], i, 0, n - 1, key);
            if (p.first != -1)
            {
                return p;
            }
        }
    }
    return {-1, -1};
}
// M3->Divide And Conquer Recursion
// Time Complexity - O(n^(log2 3)==O(n^1.53))-->T(n)=3T(n/2)+O(1)
// Space Complexity - O(logn)
pair<int, int> M3searchInSortedMatrix(vector<vector<int>> mat, int fromRow, int toRow, int fromCol, int tocol, int key)
{

    int i = fromRow + (toRow - fromRow) / 2;
    int j = fromCol + (tocol - fromCol) / 2;
    if (mat[i][j] == key)
    {
        return {i, j};
    }
    else
    {
        if (i != toRow || j != fromCol)
        {
            pair<int, int> p1 = M3searchInSortedMatrix(mat, fromRow, i, j, tocol, key);
            if (p1.first != -1)
            {
                return p1;
            }
        }
        // special case-->of(1x2 matrix -->has to be handled explicitly)
        // arr[fromrow][fromcol] wouldve been handled by mat[i][j]==key
        // hence we handle the other case mat[i][j+1]==key
        // this case is accessed only when the above case is not accessed-->can be proved mathematically
        if (toRow == fromRow && fromCol + 1 == tocol)
        {
            if (mat[fromRow][tocol] == key)
            {
                return {fromRow, tocol};
            }
        }
        if (mat[i][j] > key)
        {
            if (j - 1 >= fromCol)
            {
                pair<int, int> p2 = M3searchInSortedMatrix(mat, fromRow, toRow, fromCol, j - 1, key);
                if (p2.first != -1)
                {
                    return p2;
                }
            }
        }
        else
        {
            if (i + 1 <= toRow)
            {
                pair<int, int> p3 = M3searchInSortedMatrix(mat, i + 1, toRow, fromCol, tocol, key);
                if (p3.first != -1)
                {
                    return p3;
                }
            }
        }
    }
    return {-1, -1};
}

// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
long long PowModIterative(long long int x, long long int n, long long int M)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x % M;
    }
    x = x % M;
    long long int res = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            res = (res * x) % M;
        }
        n = n / 2;
        x = (x * x) % M;
    }
    return res;
}
long long PowModRecursive(long long int x, long long int n, long long int M)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x % M;
    }
    int val = PowModRecursive(x, n / 2, M);
    if (n % 2 == 0)
    {

        return ((val % M) * (val % M)) % M;
    }
    else
    {
        long long temp = ((val % M) * (val % M)) % M;
        return (temp * (x % M)) % M;
    }
}

// https://www.geeksforgeeks.org/strassens-matrix-multiplication/

vector<vector<int>> MatrixAddition(vector<vector<int>> A, vector<vector<int>> B)
{ // pass matrices of same order
    int row = A.size();
    int col = A[0].size();
    vector<vector<int>> C(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
vector<vector<int>> NaiveMatrixMulti(vector<vector<int>> A, vector<vector<int>> B)
{ // my code for square matrices
    int row_1 = A.size();
    int col_1 = A[0].size();
    int row_2 = B.size();
    int col_2 = B[0].size();
    if (row_2 != col_1)
    {
        return {};
    }
    int max_size = max4(row_1, row_2, col_1, col_2);
    int n = pow(2, ceil(log2(max_size)));
    vector<vector<int>> padded_A(n, vector<int>(n, 0)), padded_B(n, vector<int>(n, 0));
    for (int i = 0; i < row_1; i++)
    {
        for (int j = 0; j < col_1; j++)
        {
            padded_A[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < row_2; i++)
    {
        for (int j = 0; j < col_2; j++)
        {
            padded_B[i][j] = B[i][j];
        }
    }

    vector<vector<int>> result_matrix(n, vector<int>(n, 0));

    if (n == 1)
    {
        result_matrix[0][0] = padded_A[0][0] * padded_B[0][0];
        return result_matrix;
    }
    else
    {
        int mid = n / 2;
        vector<vector<int>> C11(mid, vector<int>(mid, 0));
        vector<vector<int>> C12(mid, vector<int>(mid, 0));
        vector<vector<int>> C21(mid, vector<int>(mid, 0));
        vector<vector<int>> C22(mid, vector<int>(mid, 0));
        vector<vector<int>> a11(mid, vector<int>(mid, 0));
        vector<vector<int>> a12(mid, vector<int>(mid, 0));
        vector<vector<int>> a21(mid, vector<int>(mid, 0));
        vector<vector<int>> a22(mid, vector<int>(mid, 0));
        vector<vector<int>> b11(mid, vector<int>(mid, 0));
        vector<vector<int>> b12(mid, vector<int>(mid, 0));
        vector<vector<int>> b21(mid, vector<int>(mid, 0));
        vector<vector<int>> b22(mid, vector<int>(mid, 0));
        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                a11[i][j] = padded_A[i][j];
                a12[i][j] = padded_A[i][j + mid];
                a21[i][j] = padded_A[i + mid][j];
                a22[i][j] = padded_A[i + mid][j + mid];
                b11[i][j] = padded_B[i][j];
                b12[i][j] = padded_B[i][j + mid];
                b21[i][j] = padded_B[i + mid][j];
                b22[i][j] = padded_B[i + mid][j + mid];
            }
        }
        C11 = MatrixAddition(NaiveMatrixMulti(a11, b11), NaiveMatrixMulti(a12, b21));
        C12 = MatrixAddition(NaiveMatrixMulti(a11, b12), NaiveMatrixMulti(a12, b22));
        C21 = MatrixAddition(NaiveMatrixMulti(a21, b11), NaiveMatrixMulti(a22, b21));
        C22 = MatrixAddition(NaiveMatrixMulti(a21, b12), NaiveMatrixMulti(a22, b22));

        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                result_matrix[i][j] = C11[i][j];
                result_matrix[i][j + mid] = C12[i][j];
                result_matrix[i + mid][j] = C21[i][j];
                result_matrix[i + mid][j + mid] = C22[i][j];
            }
        }

        return result_matrix;
    }
    return {};
}
// https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
void M1mergeArrays(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    while (a[n1 - 1] > b[0])
    {
        int largestInA = a[n1 - 1];
        int i = n1 - 2, smallestInB = b[0];
        while (a[i] > smallestInB && i >= 0)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = smallestInB;
        i = 1;
        while (b[i] < largestInA && i < n2)
        {
            b[i - 1] = b[i];
            i++;
        }
        b[i - 1] = largestInA;
    }
    return;
}
void solve1()
{
    int n;
    cin >> n;
    if ((n - 1) % 3 == 0)
    {
        cout << "YES\n";
        return;
    }
    else
    {
        cout << "NO\n";
        return;
    }
}
void solve2()
{
    int n;
    cin >> n;
    if (n == 1 || n == 0)
    {
        cout << "-1\n";
    }
    else
    {
        int i = 1;
        while (i <= n)
        {
            if (i == 2)
            {
                cout << 1 << " ";
                i++;
                continue;
            }
            if (i == 1)
            {
                cout << 2 << " ";
                i++;
                continue;
            }
            cout << i << " ";
            i++;
        }
        cout << "\n";
        return;
    }
}
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/
// METHOD-1
bool checkMinPageLength(vector<int> &arr, int k, int p)
{
    int s = 0, cnt = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s + arr[i] > p)
        {
            cnt++;
            s = arr[i];
        }
        else
        {
            s += arr[i];
        }
    }
    return (cnt <= k); // Because if we can split into less than k(then we can split into exactly k)
    // how? --> take any chunk and just remove 1 element from it and now we have cnt+1 chunks
}
int M1findPages(vector<int> &arr, int k)
{
    if (k > arr.size())
    {
        return -1;
    }
    int minPageLimit = *max_element(arr.begin(), arr.end());
    if (arr.size() == k)
    {
        return minPageLimit;
    }
    int MaxPageLimit = accumulate(arr.begin(), arr.end(), 0);
    for (int i = minPageLimit; i <= MaxPageLimit; i++)
    {
        if (checkMinPageLength(arr, k, i))
        {
            return i;
        }
    }
    return -1;
}
// METHOD-2
int M2findPages(vector<int> &arr, int k)
{ // TLE ERROR
    if (k > arr.size())
    {
        return -1;
    }
    int minPageLimit = *max_element(arr.begin(), arr.end());
    cout << minPageLimit << "\n";
    if (arr.size() == k)
    {
        return minPageLimit;
    }
    vector<int> prefix_v(arr.begin(), arr.end());
    for (int i = 1; i < prefix_v.size(); i++)
    {
        prefix_v[i] += prefix_v[i - 1];
    }
    unordered_set<int> PossibleMinSums;
    PossibleMinSums.insert(minPageLimit);
    for (int i = 0; i < prefix_v.size(); i++)
    {
        if (prefix_v[i] >= minPageLimit)
        {
            PossibleMinSums.insert(prefix_v[i]);
        }
    }
    // The minPageLimit wouldve been added in the above step(hence we can take upper bound)
    int prefixindexGreaterThanMinPageLimit = upper_bound(prefix_v.begin(), prefix_v.end(), minPageLimit) - prefix_v.begin();

    // ERROR MADE (FORGOT THAT IT MUST BE CONTIGOUS BLOCK SUM)
    //  for(int i=prefixindexGreaterThanMinPageLimit;i<prefix_v.size();i++){
    //      for(int j=0;j<=i;j++){
    //          if(prefix_v[i]-prefix_v[j]>minPageLimit){
    //              PossibleMinSums.insert(prefix_v[i]-prefix_v[j]);
    //          }
    //          else{
    //              break; // if the diff of prefix sums of i and k (where k lies in between 0 and i) is less than min page limit
    //              //then all  diff of  prefix sums of i and (k to j) will be less than minpage limit

    //         }
    //     }
    // }
    for (int i = prefix_v.size() - 1; i >= prefixindexGreaterThanMinPageLimit; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (prefix_v[i] - prefix_v[j] > minPageLimit)
            {
                // cout<<" index i and j are "<<i<<" "<<i<<" "<<j<<" "<<prefix_v[i]-prefix_v[j]<<"\n";
                PossibleMinSums.insert(prefix_v[i] - prefix_v[j]);
            }
        }
    }
    vector<int> PossibleMinSumsVector(PossibleMinSums.begin(), PossibleMinSums.end());
    sort(PossibleMinSumsVector.begin(), PossibleMinSumsVector.end());
    // printVector(PossibleMinSumsVector);
    for (int i = 0; i < PossibleMinSumsVector.size(); i++)
    {
        if (checkMinPageLength(arr, k, PossibleMinSumsVector[i]))
        {
            return PossibleMinSumsVector[i];
        }
    }
    return -1;
}
// METHOD-3
int M3findPages(vector<int> &arr, int k)
{
    if (k > arr.size())
    {
        return -1;
    }
    int minPageLimit = *max_element(arr.begin(), arr.end());
    if (k == arr.size())
    {
        return minPageLimit;
    }
    int MaxPageLimit = accumulate(arr.begin(), arr.end(), 0);
    int low = minPageLimit, high = MaxPageLimit, res = 0;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        if (checkMinPageLength(arr, k, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

// LEETCODE-278
// isbadVersion  is an api which is defined in leetcode problem
bool isBadVersion(int n)
{
    if (n == 2)
    {
        return true;
    }
    return false;
}
int firstBadVersion(int n)
{
    int low = 1, high = n;
    while (low < high)
    {
        int mid = (high - low) / 2 + low;
        if (isBadVersion(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

// 1011. Capacity To Ship Packages Within D Days
bool checkDandWeights(vector<int> &weights, int days, int x)
{
    // helper function
    // to check if the weights can be transported in given days with max cap of ship as x
    int s = 0, cnt = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        if (s + weights[i] > x)
        {
            cnt++;
            s = weights[i];
        }
        else
        {
            s += weights[i];
        }
    }
    return (cnt <= days);
}
int shipWithinDays(vector<int> &weights, int days)
{
    int maxShipCap = accumulate(weights.begin(), weights.end(), 0); // ship cap<=sum(weights)-->1 day 1 shot
    int MinShipCap = *max_element(weights.begin(), weights.end());  // the ship cap>=max(weights)
    int low = MinShipCap, high = maxShipCap;
    while (low < high)
    {
        int mid = (high - low) / 2 + low;
        if (checkDandWeights(weights, days, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high; // or low(low==high breaking condition)
}

// 410. Split Array Largest Sum
bool checkMandSum(vector<int> &nums, int k, int m)
{
    // checking whether k -sub-array sums all less than m can be created
    int cnt = 1, s = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s + nums[i] > m)
        {
            cnt++;
            s = nums[i];
        }
        else
        {
            s += nums[i];
        }
    }
    return (cnt <= k);
}
int splitArray(vector<int> &nums, int k)
{
    int maxx = accumulate(nums.begin(), nums.end(), 0); // maximum possible subarray is the entire array itself(sum of array elements)
    int minn = *max_element(nums.begin(), nums.end());  // no negative nos (or else it would be very different)
    int low = minn, high = maxx;
    while (low < high)
    {
        int mid = (high - low) / 2 + low;
        if (checkMandSum(nums, k, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}
// 875. Koko Eating Bananas
int minCount(vector<int> &piles, int h, int x)
{
    int cnt = 0, s = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        cnt += ceil((float)piles[i] / x); // why ceil- 11 banans at 5banana/per hr (soo 11/5=2.1) -->3 hrs to finish the entire set
    }
    return (cnt <= h);
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int maxx = *max_element(piles.begin(), piles.end());
    // cout<<"max"<<maxx<<"\n";
    if (piles.size() == h)
    {
        return maxx;
    }
    int minn = 1; // 1 banana per hour
    int low = minn, high = maxx;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (minCount(piles, h, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> arr1 = {3, 6, 7, 11};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> arr3 = {1, 5, 9, 10, 15, 20};
    vector<int> arr4 = {2, 3, 8, 13};
    vector<int> arr5 = {0, 1};
    vector<int> arr6 = {2, 3};
    int arr[] = {1, 2, 3, 4, 5};
    cout << 3 [arr] << endl;
    // cout << minEatingSpeed(arr1, 8) << endl;

    return 0;
}