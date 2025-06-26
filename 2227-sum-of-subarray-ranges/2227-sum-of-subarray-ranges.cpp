#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For std::min, std::max

class Solution {
public:
   
    long long sumSubarrayMins(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<long long> left_count(n), right_count(n); // Stores counts of elements
        std::stack<int> s; // Monotonic stack to store indices

    
        for (int i = 0; i < n; ++i) {
   
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
         
            left_count[i] = (s.empty() ? (long long)i + 1 : (long long)i - s.top());
            s.push(i);
        }

        // Clear stack for next use
        while (!s.empty()) s.pop();


        for (int i = n - 1; i >= 0; --i) {
           
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            right_count[i] = (s.empty() ? (long long)n - i : (long long)s.top() - i);
            s.push(i);
        }

        long long sumMins = 0;
        for (int i = 0; i < n; ++i) {
      
            sumMins += (long long)arr[i] * left_count[i] * right_count[i];
        }
        return sumMins;
    }


    long long sumSubarrayMaxs(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<long long> left_count(n), right_count(n); // Stores counts of elements
        std::stack<int> s; // Monotonic stack to store indices

        for (int i = 0; i < n; ++i) {
           
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            left_count[i] = (s.empty() ? (long long)i + 1 : (long long)i - s.top());
            s.push(i);
        }

        // Clear stack
        while (!s.empty()) s.pop();

    
        for (int i = n - 1; i >= 0; --i) {
      
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            right_count[i] = (s.empty() ? (long long)n - i : (long long)s.top() - i);
            s.push(i);
        }

        long long sumMaxs = 0;
        for (int i = 0; i < n; ++i) {
         
            sumMaxs += (long long)arr[i] * left_count[i] * right_count[i];
        }
        return sumMaxs;
    }

    long long subArrayRanges(std::vector<int>& nums) {
      
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
