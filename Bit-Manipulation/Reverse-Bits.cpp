class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
            //check least significant bit
            uint32_t c=n&1;
            //shift the bit
            n=n>>1;
            ans=ans<<1;
            //add it to the ans
            ans=ans|c;
        }
        return ans;
    }
};
