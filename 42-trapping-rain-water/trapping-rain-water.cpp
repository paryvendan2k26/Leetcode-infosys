class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
           vector<int> sufix(n);

        sufix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufix[i]=max(sufix[i+1], height[i]);
        }
        int total=0;
        int prefixmax=height[0];
        for(int i=0;i<n;i++){
            int sufixmax=sufix[i];

            if(height[i]<prefixmax && height[i]< sufixmax){
                total+=min(prefixmax, sufixmax)-height[i];
            }
                            prefixmax=max(height[i], prefixmax);

        }

        return total;
    }
};