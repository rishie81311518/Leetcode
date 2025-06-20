#include <stack>
#include <algorithm> // For std::min and std::max
#include <limits>    // For std::numeric_limits<int>::max()

class MinStack {
private:
    std::stack<long long> st; // Use long long to prevent overflow during calculations
    long long min_val;        // Stores the current minimum value

public:
    MinStack() {
        min_val = std::numeric_limits<long long>::max(); // Initialize min_val to a very large number
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            min_val = val;
        } else {
            if (val >= min_val) { // If the new value is greater than or equal to the current minimum
                st.push(val);
            } else { // If the new value is less than the current minimum
                // Store (2 * val - min_val) and update min_val
                st.push(2LL * val - min_val);
                min_val = val;
            }
        }
    }

    void pop() {
        if (st.empty()) {
            return; // Or throw an exception, depending on desired behavior for empty stack pop
        }

        long long top_val = st.top();
        st.pop();

        if (top_val < min_val) { // This means the popped element was the old minimum
            min_val = 2LL * min_val - top_val; // Recover the previous minimum
        }
        
        // If stack becomes empty after pop, reset min_val
        if (st.empty()) {
            min_val = std::numeric_limits<long long>::max();
        }
    }

    int top() {
        if (st.empty()) {
            // Or throw an exception, or return a sentinel value like std::numeric_limits<int>::min()
            return -1; 
        }

        long long top_val = st.top();
        if (top_val < min_val) {
            // If the stored value is less than min_val, it means the actual top is min_val
            // and the stored value is a "marker" for the previous minimum.
            return static_cast<int>(min_val);
        } else {
            return static_cast<int>(top_val);
        }
    }

    int getMin() {
        if (st.empty()) {
            // Or throw an exception, or return a sentinel value
            return -1; 
        }
        return static_cast<int>(min_val);
    }
};