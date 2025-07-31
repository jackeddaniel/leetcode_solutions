class Solution {
    public: 
        int lastStoneWeight(vector<int>& stones) {

            priority_queue<int> heap;

            for(int i : stones) {
                heap.push(i);
            }

            while(heap.size() > 1) {
                int stone_a = heap.top();
                heap.pop();
                int stone_b = heap.top();
                heap.pop();

                if(stone_a != stone_b) {
                    heap.push(abs(stone_a-stone_b));
                }
            }

            if(heap.empty()) return 0;
            return heap.top();
        }
};
