class Solution {
private:
    vector<vector<int>> map;
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        if(rooms.size() == 0){
            return;
        }
        //maps
        map = rooms;
        //test_print(rooms);
        
        
        //logic
        vector<array<int, 2>> start_points = search_zeros(map);
        if(start_points.size() == 0){
            return;
        }
        for (int i = 0; i < start_points.size(); i++){
            array<int, 2> start_point = {start_points[i][0], start_points[i][1]};
            
            vector<array<int, 2>> bucket;
            bucket.push_back(start_point);
            
        
            vector<vector<int>> used = rooms;
            int col = used[0].size();
            int row = used.size();
            for (int r = 0; r < row; r++){
                for (int c = 0; c < col; c++){
                    used[r][c] = 0;
                }
            }
            
            int step = 0;
            used[start_points[i][0]][start_points[i][1]] = 1;
            
            while(bucket.size() > 0){
                step++;
                int size = bucket.size();
                for(int j = 0; j < size; j++){
                    vector<array<int, 2>> path = search_path(bucket.front());
                    for(int k = 0; k < path.size(); k++){
                        if(used[path[k][0]][path[k][1]] == 0){
                            if (rooms[path[k][0]][path[k][1]] > step) rooms[path[k][0]][path[k][1]] = step;
                            used[path[k][0]][path[k][1]] = 1;
                            bucket.push_back(path[k]);
                            //test_print(rooms);
                        }
                    }
                    
                    bucket.erase(bucket.begin());
                }
            }
        }
        
        
    }
    
    vector<array<int, 2>> search_zeros(vector<vector<int>>& target){
        vector<array<int, 2>> result;
        int col = target[0].size();
        int row = target.size();
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if(target[r][c] == 0){
                    array<int, 2> point = {r,c};
                    result.push_back(point);
                }
            }
        }
        return result;
    }

    vector<array<int, 2>> search_path(array<int, 2> start){
        vector<array<int, 2>> result;
        if (start[0]-1 >= 0 && test(start[0]-1, start[1])) {
            array<int, 2> point = {start[0]-1, start[1]};
            result.push_back(point);
        }
        if (start[0]+1 < map.size() && test(start[0]+1, start[1])) {
            array<int, 2> point = {start[0]+1, start[1]};
            result.push_back(point);
        }
        if (start[1]-1 >= 0 && test(start[0], start[1]-1)) {
            array<int, 2> point = {start[0], start[1]-1};
            result.push_back(point);
        }
        if (start[1]+1 <  map[0].size() && test(start[0], start[1]+1)) {
            array<int, 2> point = {start[0], start[1]+1};
            result.push_back(point);
        }
        return result;
    }

    bool test(int row, int col) {
        return map[row][col] > 0;
    }

    void test_print(vector<vector<int>>& target) {
        int col = target[0].size();
        int row = target.size();
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (target[r][c] == 2147483647 ){
                    cout << "Ma" << " ";
                }
                else if (target[r][c] >= 0 ){
                    cout << " " << target[r][c] << " ";
                }
                else{
                    cout << target[r][c] << " ";
                }
                
            }
            cout << endl;
        }
        cout << endl;
    }
};