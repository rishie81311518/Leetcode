#include <queue>

class Solution {
public:
    long long putMarbles(std::vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;

        std::priority_queue<int> maxHeap; 
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min heap for the smallest (k-1) elements

        for (int i = 0; i < n - 1; i++) {
            int sum = weights[i] + weights[i + 1];

            minHeap.push(sum);
            if (minHeap.size() > k - 1) minHeap.pop(); // Keep only (k-1) smallest elements

            maxHeap.push(sum);
            if (maxHeap.size() > k - 1) maxHeap.pop(); // Keep only (k-1) largest elements
        }

        long long minScore = 0, maxScore = 0;

        while (!minHeap.empty()) {
            minScore += minHeap.top();
            minHeap.pop();
        }

        while (!maxHeap.empty()) {
            maxScore += maxHeap.top();
            maxHeap.pop();
        }

        return minScore - maxScore;
    }
};
