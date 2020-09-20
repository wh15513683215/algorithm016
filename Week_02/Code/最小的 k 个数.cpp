class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
     vector<int> res(k,0);
     sort(arr.begin(),arr.end());
     for (int i = 0; i <= k-1; ++i) 
         res[i] = arr[i];
         return res;
    }
};//Onlog(n) O(log(n))

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0) return res;
        priority_queue<int> h;
        for (int ch : arr) {
            if (h.size() < k)
            h.push(ch);
            else {
                if (h.top() <= ch) 
                continue;
                else {
                    h.pop();
                    h.push(ch);
                }
            }
        }
        while (!h.empty()) {
            res.push_back(h.top());
            h.pop();
        }
        return res;
    }
}; //堆排序 O(nlogk) O(k)
