// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = n, m;
        
        while( l <= r ){
            long mid = l + (r-l)/2;
            if( isBadVersion (mid) )
                r = mid - 1, m = mid;
            if( isBadVersion(mid) == false )
                l = mid + 1;
        }
        
        return m;
    }
};
