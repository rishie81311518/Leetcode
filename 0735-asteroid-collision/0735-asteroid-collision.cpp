class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;  // Stack to simulate asteroid collisions
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {  // Iterate through all asteroids
            bool destroyed = false;
            while (!destroyed && !st.empty() && asteroids[i] < 0 && st.back() > 0) {
                if (st.back() == -asteroids[i]) {  // Equal magnitude, both destroy
                    st.pop_back();
                    destroyed = true;
                } else if (st.back() < -asteroids[i]) {  // Current asteroid is larger
                    st.pop_back();
                } else {  // st.back() is larger, current asteroid destroyed
                    destroyed = true;
                }
            }
            if (!destroyed) {
                st.push_back(asteroids[i]);
            }
        }

        // Convert list to vector for return
        vector<int> result(st.begin(), st.end());
        return result;
    }
};