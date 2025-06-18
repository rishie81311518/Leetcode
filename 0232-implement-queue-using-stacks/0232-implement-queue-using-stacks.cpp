#include <stack> // Essential header

class MyQueue {
private:
    std::stack<int> s1; // Declare as member variables
    std::stack<int> s2;

public:
    MyQueue() {
        // Constructor, nothing specific needed here
    }

    void push(int x) {
        s1.push(x); // Push to the input stack
    }

    int pop() {
        // First, check if the entire queue is empty.
        // If it is, there's nothing to pop.
        if (empty()) {
            // For competitive programming, returning -1 is common for error.
            // In robust code, you'd throw an exception like std::out_of_range.
            return -1;
        }

        // If the output stack (s2) is empty, we need to transfer elements from s1.
        if (s2.empty()) {
            // Move all elements from s1 to s2. This reverses their order,
            // making the oldest element from s1 the top of s2.
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // At this point, s2 MUST NOT be empty, because we already checked
        // that the overall queue wasn't empty, and if s2 was empty, we filled it.
        int frontElement = s2.top(); // Get the front element
        s2.pop();                    // Remove it
        return frontElement;         // Return the removed element
    }

    int peek() {
        // First, check if the entire queue is empty.
        // If it is, there's nothing to peek.
        if (empty()) {
            return -1;
        }

        // If the output stack (s2) is empty, transfer elements from s1.
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // At this point, s2 MUST NOT be empty.
        return s2.top(); // Return the front element without removing it
    }

    bool empty() {
        // The queue is empty only if both stacks are empty.
        return s1.empty() && s2.empty();
    }
};