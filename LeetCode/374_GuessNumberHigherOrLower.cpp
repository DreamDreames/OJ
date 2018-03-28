#include "shared.h"

namespace GuessNumberHigherOrLower {
    int guess(int num);
    
    class Solution {
    public:
        int guessNumber(int n) {
            return guessNumberBetween(1, n);
        }
    private:
        int guessNumberBetween(int low, int high) {
            if(low == high)
                return high;
            
            int middle = low / 2 + high / 2;
            
            int target = guess(middle);
            if (target == 0)
                return middle;
            
            if(target == 1)
                return guessNumberBetween(middle + 1, high);
            
            return guessNumberBetween(low, middle - 1);
        }
    };
}
