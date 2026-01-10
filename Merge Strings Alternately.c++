
3class Solution {
4public:
5    string mergeAlternately(string word1, string word2) {
6        int i = 0, j = 0, k = 0;
7        int size1 = word1.length();
8        int size2 = word2.length();
9        
10        vector<char> temp;
11        string result = "";
12
13        while (i < size1 && j < size2) {
14            if (k % 2 == 0)
15                temp.push_back(word1[i++]);
16            else
17                temp.push_back(word2[j++]);
18            k++;
19        }
20
21        while (i < size1)
22            temp.push_back(word1[i++]);
23
24        while (j < size2)
25            temp.push_back(word2[j++]);
26
27        for (int idx = 0; idx < temp.size(); idx++)
28            result.push_back(temp[idx]);
29
30        return result;
31    }
32};
33
