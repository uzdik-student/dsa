/**
 * Assume that you are given an array of N positive integers and an integer X.
 * Your task in this problem is to count the number of subarrays having sum X.
 * 
 * INPUT FORMAT
 * The first input line has two integers N and X: the number of elements in the array and the target sum X.
 * The next line has N integers showing the contents of the array: a, 22,...., an.
 * 
 * OUTPUT FORMAT
 * Print one integer, which shows the required number of subarrays.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    unordered_map<int, int> prefix_sum_count;
    int current_sum = 0;
    int count = 0;

    // Initialize the hash map with 0 sum having 1 occurrence
    prefix_sum_count[0] = 1;

    for (int i = 0; i < N; ++i) {
        // Update the current sum
        current_sum += arr[i];

        // Check if there is a prefix sum that we can subtract to get X
        if (prefix_sum_count.find(current_sum - X) != prefix_sum_count.end()) {
            count += prefix_sum_count[current_sum - X];
        }

        // Add the current sum to the hash map
        prefix_sum_count[current_sum]++;
    }

    cout << count << endl;
}