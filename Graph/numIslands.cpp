class numIslands {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row_size = grid.size();
        int col_size = grid[0].size();
        int island_count = 0;
        vector<vector<bool>> visited_island(row_size,vector<bool>(col_size, false));
        for (int row_ptr = 0; row_ptr < row_size; row_ptr++) {
            for (int col_ptr = 0; col_ptr < col_size; col_ptr++) {
                if ((grid[row_ptr][col_ptr] == '1') && (!visited_island[row_ptr][col_ptr])) {
                    island_count ++;
                    stack<pair<int,int>> st;
                    st.push(make_pair(row_ptr, col_ptr));
                    visited_island[row_ptr][col_ptr] = true;
                    while (!st.empty()) {
                        int row, col;
                        row = st.top().first; 
                        col = st.top().second;
                        st.pop();
                        if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited_island[row - 1][col]) {
                            st.push(make_pair(row - 1, col));
                            visited_island[row - 1][col] = true;
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited_island[row][col - 1]) {
                            st.push(make_pair(row, col - 1));
                            visited_island[row][col - 1] = true;
                        }                      
                        if (col + 1 < col_size && grid[row][col + 1] == '1' && !visited_island[row][col + 1]) {
                            st.push(make_pair(row, col + 1));
                            visited_island[row][col + 1] = true;
                        }
                        if (row + 1 < row_size && grid[row + 1][col] == '1' && !visited_island[row + 1][col]) {
                            st.push(make_pair(row + 1, col));
                            visited_island[row + 1][col] = true;
                        } 
                    
                    }
                }
            }
        }
        return island_count;
    }
};