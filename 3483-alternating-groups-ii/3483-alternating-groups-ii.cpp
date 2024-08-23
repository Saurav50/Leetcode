class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int i = 0;
        int j = 1;
        int count = 0;
        deque<int> dq;
        int check = true;
        int indx = INT_MIN;
        queue<int> q;

        dq.push_back(colors[0]);
       
        j = 1;

        while (j < colors.size() + k - 1) {

            if (dq.size() && (dq.back() == colors[j % colors.size()] ||
                              dq.front() == dq.back())) {
                q.push(j - 1);
            }

            dq.push_back(colors[j % colors.size()]);

            if (dq.size() == 3) {
                dq.pop_front();
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