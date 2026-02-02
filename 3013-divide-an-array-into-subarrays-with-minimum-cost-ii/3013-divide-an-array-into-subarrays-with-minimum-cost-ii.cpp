class Solution {
    int max_rank;
    vector<int> bit_count;
    vector<long long> bit_sum;
    vector<int> sorted_values;

    void update(int idx, int count_delta, long long val_delta) {
        for (; idx <= max_rank; idx += idx & -idx) {
            bit_count[idx] += count_delta;
            bit_sum[idx] += val_delta;
        }
    }

    long long query_k_smallest(int k) {
        int idx = 0;
        int current_k = 0;
        long long current_val_sum = 0;
        for (int i = 1 << 17; i > 0; i >>= 1) {
            int next_idx = idx + i;
            if (next_idx <= max_rank && current_k + bit_count[next_idx] < k) {
                idx = next_idx;
                current_k += bit_count[idx];
                current_val_sum += bit_sum[idx];
            }
        }
        return current_val_sum + (long long)(k - current_k) * sorted_values[idx];
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        sorted_values = nums;
        sort(sorted_values.begin(), sorted_values.end());
        sorted_values.erase(unique(sorted_values.begin(), sorted_values.end()), sorted_values.end());
        max_rank = sorted_values.size();

        bit_count.assign(max_rank + 1, 0);
        bit_sum.assign(max_rank + 1, 0);

        auto get_rank = [&](int val) {
            return lower_bound(sorted_values.begin(), sorted_values.end(), val) - sorted_values.begin() + 1;
        };

        int target_k = k - 1;
        for (int i = 1; i <= min(1 + dist, n - 1); ++i) {
            update(get_rank(nums[i]), 1, nums[i]);
        }

        long long min_cost = nums[0] + query_k_smallest(target_k);

        for (int i = 2; i <= n - target_k; ++i) {
            update(get_rank(nums[i - 1]), -1, -nums[i - 1]);
            if (i + dist < n) {
                update(get_rank(nums[i + dist]), 1, nums[i + dist]);
            }
            min_cost = min(min_cost, nums[0] + query_k_smallest(target_k));
        }
        return min_cost;
    }
};