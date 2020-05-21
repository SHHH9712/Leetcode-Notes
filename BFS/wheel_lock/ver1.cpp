class Solution {
public:
    vector<int> ops = {1, -1};
    int openLock(vector<string>& deadends, string target) {
        string wheel = "0000";
        int used[10000]; //if used mark 1
        
        
        int deadend[10000];
        for(auto &d :deadend){
            d = 0;
        }
        for(string &d:deadends){
            deadend[stoi(d)] = 1;
        }
        
        queue<string> que;
        que.push(wheel);
        for(auto &u :used){
            u = 0;
        }
        used[stoi(wheel)] = 1;
        if( deadend[0]==1) return -1;
        
        int step = 0;
        while(que.size()){
            step++;
            cout << "step = " << step << endl;
            int size = que.size();
            for(int s = 0; s < size; s++){
                wheel = que.front();
                que.pop();
                for(int i = 0; i < 4; i++){
                    for(int &op : ops){
                        string new_wheel = wheel;
                        char digit = new_wheel[i];
                        int val_digit = (int)digit;
                        if(val_digit == 48 && op==-1){
                            val_digit+=9;
                        }else if(val_digit == 48+9 && op==1){
                            val_digit-=9;
                        }else{
                            val_digit+=op;
                        }
                        digit = (char)val_digit;
                        
                        new_wheel[i] = digit;
                        
                        int val_wheel = stoi(new_wheel);
                        if(val_wheel<0 || val_wheel>9999 || used[val_wheel]==1 || deadend[val_wheel]==1) continue;
                        if(stoi(target)==val_wheel) return step;
                        que.push(new_wheel);
                        used[val_wheel] = 1;
                    }
                }
            }
                
        }
        
        return -1;
    }
};