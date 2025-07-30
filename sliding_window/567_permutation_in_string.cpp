class Solution {
    public:
        
        bool checker(unordered_map<char,int> freq, int start, int end, string s2) {
            cout<<"checker called"<<"\n";
            int it = start;

            while(it <= end) {
                if (freq.find(s2[it]) == freq.end()) {
                    return false;
                } else if (freq[s2[it]] == 1) {
                    freq.erase(s2[it]);
                } else {
                    freq[s2[it]]--;
                }
                it++;
            }
            return true;
        }
                

        bool checkInclusion(string s1, string s2) {
            unordered_map<char,int> freq;

            for (char c : s1) {
                freq[c]++;
            }
            
            cout<<"map created"<<"\n";

            int start = 0;
            int end = s1.size()-1;
            
            while(end < s2.size()) {
                if (checker(freq,start,end,s2)) return true;
                cout<<"start: "<<start<<" end: "<<end<<"\n";
                start++;
                end++;
            }
            return false;
        }
};

