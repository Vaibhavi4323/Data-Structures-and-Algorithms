class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // Max heap
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            // We can execute at most n + 1 tasks
            // before the same task can be executed again
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int current = pq.top();
                    pq.pop();
                    current--;
                    if (current > 0) {
                        temp.push_back(current);
                    }
                }
                time++;
                // All tasks are completed
                if (pq.empty() && temp.empty()) {
                    break;
                }
            }
            // Put remaining tasks back into heap
            for (int f : temp) {
                pq.push(f);
            }
        }
        return time;
    }
};