class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> words(wordList.begin(), wordList.end());

        // If endWord doesn't exist, transformation is impossible

        if (words.find(endWord) == words.end())

            return 0;

        queue<string> q;

        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string current = q.front();

                q.pop();

                // Try changing every character

                for (int i = 0; i < current.size(); i++) {

                    char original = current[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        current[i] = c;

                        // Found the target

                        if (current == endWord)

                            return level + 1;

                        // New valid word

                        if (words.find(current) != words.end()) {

                            q.push(current);

                            words.erase(current);

                        }

                    }

                    current[i] = original;

                }

            }

            level++;

        }

        return 0;
    }
};