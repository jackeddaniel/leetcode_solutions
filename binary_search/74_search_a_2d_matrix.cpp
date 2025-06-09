class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            cols = matrix[0].size();
            rows = matrix.size();
            int row_no,col_no; //for usage in the while loop
            total = cols * rows;
            int start = 0;
            int end = total - 1;
            while(start <= end) {
                int mid = start + (end-start)/2;
                
                row_no = mid/cols;
                col_no = mid%cols;

                if(matrix[row_no][col_no] == target) return true;
                else if(matrix[row_no][col_no] < target) start = mid + 1;
                else end = mid - 1;
            }

            return false;
        }
};

