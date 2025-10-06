#include<bits/stdc++.h>
using namespace std;
void solve()
{
   {
        if (n == 0) {
            return "Zero";
        }
        string arr_corner[] = {"Ten ",      "Eleven ",    "Twelve ",
                               "Thirteen ", "Fourteen ",  "Fifteen ",
                               "Sixteen ",  "Seventeen ", "Eighteen ",
                               "Nineteen ", "Twenty "};
        string arr1[] = {"One ", "Two ",   "Three ", "Four ", "Five ",
                         "Six ", "Seven ", "Eight ", "Nine "};
        string arr2[] = {"Twenty ", "Thirty ",  "Forty ",  "Fifty ",
                         "Sixty ",  "Seventy ", "Eighty ", "Ninety "};
        string arr3[] = {"", "Thousand ", "Million ", "Billion "};
        vector<int> test;
        while (n > 0) {
            int r = n % 10;
            n = n / 10;
            test.push_back(r);
        }
        int z = test.size();
        cout << z << endl;
        int arr_nums[z];

        for (int i = z - 1; i >= 0; i--) {
            arr_nums[z - 1 - i] = test[i];
        }
        cout << arr_nums[0] << endl;
        string arr_ans[4];
        int i;
        for (i = 0; i < z / 3; i++) {
            string s;
            int temp[3] = {arr_nums[z - 3 - i * 3], arr_nums[z - 2 - i * 3],
                           arr_nums[z - 1 - i * 3]};
            if (temp[0] == 0 && temp[1] == 0 && temp[2] == 0) {
                arr3[i] = "";

                continue;
            }
            if (temp[0] != 0) {
                s += arr1[temp[0] - 1] + "Hundred ";
            }
            if (temp[1] != 0 && temp[1] != 1) {
                s += arr2[temp[1] - 2];
                if (temp[2] != 0) {
                    s += arr1[temp[2] - 1];
                }
            }
            if (temp[1] == 0 && temp[2] == 0) {
                arr_ans[i] = s;
                continue;
            }
            if (temp[1] == 0) {
                s += arr1[temp[2] - 1];
            }
            if (temp[1] == 1) {
                s += arr_corner[temp[2]];
            }

            arr_ans[i] = s;
        }
        int t = z % 3;
        if (t == 1) {
            arr_ans[i] = arr1[arr_nums[0] - 1];
            i++;
        } else if (t == 2) {
            string s;
            if (arr_nums[0] != 0 && arr_nums[0] != 1) {
                s = arr2[arr_nums[0] - 2];
                if (arr_nums[1] != 0) {
                    s += arr1[arr_nums[1] - 1];
                }

            } else if (arr_nums[0] == 1) {
                s = arr_corner[arr_nums[1]];
            }
            arr_ans[i] = s;
            i++;
        }
        string ans;
        for (int k = i - 1; k >= 0; k--) {
            ans += arr_ans[k] + arr3[k];
        }
        ans.pop_back();
        cout<<ans;
    }

}
int main()
{
  solve();
}