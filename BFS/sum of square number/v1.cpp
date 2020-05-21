class Solution {
public:
    int numSquares(int n) {
        queue<int> que;
        int step = 0;
        
        que.push(n);
        while(que.size()!=0){
            step++;
            cout << "layer: " << step << endl;
            int size = que.size();
            for(int ii = 0; ii < size; ii++){
                int now = que.front();
                que.pop();
                int count = 0;
                while(now - count>0){
                    int val = (int)sqrt(now - count);
                    if(pow(val,2)+count==now) {
                        if(count==0){
                            return step;
                        }
                        que.push(count);
                    }
                    count++;
                }
            }
            
        }
        
        
        return -1;
    }
};