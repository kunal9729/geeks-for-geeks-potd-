class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        --l;
        --r;
        
        for(int i = l; i < r + 1; i++){
            int bit = (y >> i) & 1;
            x |= bit << i;
        }
        
        return x;
    }
};
