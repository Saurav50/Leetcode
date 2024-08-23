class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int i = 0;
        int j = 1;
        int count = 0;
        queue<int> q;

        while (i < colors.size()) {

            if (colors[(j - 1) % colors.size()] == colors[j % colors.size()]) {
                q.push((j) % colors.size());
            }

            if (j - i + 1 < k) {
                j++;
            }

            else if (j - i + 1 == k) {
                if (q.front() == i) {
                            q.pop();
                }
                if (q.size() == 0) {
                    count++;
                }
                
                
                

                i++;
                j++;
            }
        }
        return count;
    }
};