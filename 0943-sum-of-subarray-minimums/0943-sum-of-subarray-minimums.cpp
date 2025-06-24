class Solution {
public:
 
  vector<int> findNse(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nse(n, -1);

    for(int i = n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
        

    } 
    return nse;
  }

    vector<int> findPse(vector<int> &arr){
          stack<int> st;
    int n = arr.size();
    vector<int> pse(n, -1);

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
        st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
      
    }
    return pse;
 }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total  = 0;
        int mod = 1e9 + 7;

        if ( n == 0) return 0;
       vector<int> nse = findNse(arr);
       vector<int> pse = findPse(arr);

       for (int i = n-1; i >= 0; i--) {
          long long rightCount = nse[i] - i;
          long long leftCount = i - pse[i];

         total = (total + (long long)arr[i] * leftCount % mod * rightCount % mod) % mod;
       }

       return total;


        
    }
};