//used bfs to solve it
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordListset(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);
        int level = 0;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                string curr = que.front();
                que.pop();
                if (curr == endWord)
                    return level + 1;
                for (char ch : "abcdefghijklmnopqrstuvwxyz") {
                    for (int i = 0; i < curr.length(); i++) {
                        string neighbour = curr;
                        neighbour[i] = ch;
                        if (visited.find(neighbour) == visited.end() &&
                            wordListset.find(neighbour) != wordListset.end()) {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};