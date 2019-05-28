/* Christy is interning at HackerRank. One day she has to distribute some chocolates to her colleagues. She is biased towards her friends and plans to give them more than the others. One of the program managers hears of this and tells her to make sure everyone gets the same number.

To make things difficult, she must equalize the number of chocolates in a series of operations. For each operation, she can give 1, 2 or 5chocolates to all but one colleague. Everyone who gets chocolate in a round receives the same number of pieces.

For example, assume the starting distribution is [1,1,5] She can give 2  bars to the first two and the distribution will be [3,3,5] On the next round, she gives the same two  bars each, and everyone has the same number: [5,5,5]
Given a starting distribution, calculate the minimum number of operations needed so that every colleague has the same number of chocolates.

Function Description

Complete the equal function in the editor below. It should return an integer that reperesents the minimum number of operations required.

equal has the following parameter(s):

arr: an array of integers to equalize
Input Format

The first line contains an integer t , the no of test cases
Each test case has 2 lines.
- The first line contains an integer n, the number of colleagues.
- The second line contains n space-separated integers denoting the number of chocolates each colleague has.

Output Format

Print the minimum number of operations needed for each test case, one to a line.

Sample Input

1
4
2 2 3 7

Sample Output

2

Explanation

Start with [2,2,3,7]
Add 1 to all but the 3rd element [3,3,3,8]
Add 5 to all but the 4th element [8,8,8,8]

Two operations were required.

Sample Input 1

1
3
10 7 12
Sample Output 1

3
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the equal function below.
int equal(vector<int> arr) {
    sort(arr.begin(),arr.end());
    int count = 0;
    for(int i=0;i<arr.size()-1;++i)
        {
            if(arr[i]==arr[i+1])
            {
                continue;
            }
            int num = arr[i+1]-arr[i];
            int num1=num;
            count+= num/5;
            num = num%5;
            if(num>0)
            {
            count+= num/2;
            num = num%2;
            }
            if(num>0)
                count++;
            for (int j=i;j<arr.size();++j)
            {
                if(j!=i+1)
                    arr[j]+=num1;
            }
        }
        cout<<count;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
// What I have done is to sort the elements first, then at every iteration, take the current two numbers find the difference and count how many distributions you need to do to make the first number equal to the second number, add that count at each step, Add the difference to all numbers and only skip current+1 number in array. Keep doing this untill all numbers in the array become equal.

