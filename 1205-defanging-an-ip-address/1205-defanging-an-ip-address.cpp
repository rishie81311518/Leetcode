class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        int i = 0;
        while( i < address.size()){
            if (address[i] == '.' )
            ans = ans + "[.]";
            else
            ans = ans + address[i];
            i++;
        }
        return ans;
    }
};