sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        unordered_map<int, int> mp;
        
        int min_size = min(nums1.size(), nums2.size());
        
        int diff1=0;
        int diff2=0;
        int diff3=0;
        for (int i = 0; i < min_size; i++) {
            int x=nums1[i] - nums2[i];
            
            if(x==diff1 || x==diff2 || x==diff3){
                if(x==diff1) diff1+=x;
                if(x==diff2) diff2+=x;
                if(x==diff3) diff3+=x;
            }else  {
                if(diff1==INT_MIN) diff1=x;
                if(diff2==INT_MIN) diff2=x;
                if(diff3==INT_MIN) diff3=x;
            }
            
        }
        
        int arr[3]={diff1,diff2,diff3};
        
            int max=-1;
            int max_index=-1;
        for(int i=0;i<3;i++){
            if(abs(arr[i])>max){
                max=abs(arr[i]);
                max_index=i;
            }
        }
        
        int ans=arr[max_index]/min_size;
        return ans;