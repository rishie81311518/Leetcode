class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push elements into the heap
        for (int num : nums) {
            pq.push(num);
            // If heap size exceeds k, remove the smallest element
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // The top of the heap is the kth largest element
        return pq.top();
    }
};