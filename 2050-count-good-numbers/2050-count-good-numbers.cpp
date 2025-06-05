#include <iostream>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenNumber = (n + 1) / 2;
        long long oddNumber = n / 2;

        long long evenPosition = power(5, evenNumber);
        long long oddPosition = power(4, oddNumber);

        return (evenPosition * oddPosition) % MOD;
    }
};

