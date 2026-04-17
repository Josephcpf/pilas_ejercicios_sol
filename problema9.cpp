
// pregunta de la temperatura diaria y cuando va a aumentar luego
class Solution {
public:
     
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        Stack<int> s;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++){
            while(!s.isempty() && temperatures[i] > temperatures[s.top()]){
                res[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        for(int i = 0; i < n; i++) {
            if(res[i] != 0)
                res[i] = res[i] - i;
        }

        return res;
    }
};



// 
class Solution {
public:
    vector<int> next_less_element(vector<int>& h){
        int n = h.size();
        vector<int> res(n,n);
        Stack<int> s;
        for(int i = 0 ; i < n ; i++){
            while(!s.isempty() && h[i] < h[s.top()]){
                res[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }

    vector<int> prev_less_element(vector<int>& h){
        int n = h.size();
        vector<int> res(n,-1);
        Stack<int> s;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!s.isempty() && h[i] < h[s.top()]){
                res[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prev_less_element(heights);
        vector<int> next = next_less_element(heights);
        int n = heights.size();
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            int l = prev[i] , r = next[i];
            //cout<<prev[i]<<" "<<next[i]<<endl;
            ans = max(ans, heights[i] * (r-l-1));
        }
        return ans;
    }
};
