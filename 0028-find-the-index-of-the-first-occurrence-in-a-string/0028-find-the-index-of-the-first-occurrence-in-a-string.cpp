class Solution {
public:
    int strStr(string haystack, string needle) {
       if(needle.empty()){
        return 0;
       }

    for (int i = 0; i< haystack.size(); ++i){
         if (haystack.substr(i, needle.size()) == needle) {
            return i; // Return the starting index of the first occurrence
        }
    }

    return -1;


        
    }
};