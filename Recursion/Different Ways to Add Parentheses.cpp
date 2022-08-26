class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<int> cal;
        for(int i = 0; i < expression.size(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                vector<int> l = diffWaysToCompute(expression.substr(0,i));
                vector<int> r = diffWaysToCompute(expression.substr(i+1));
                
                for(int x: l){
                    for(int y: r){
                        if(expression[i] == '+') cal.push_back(x+y);
                        else if(expression[i] == '-') cal.push_back(x-y);
                        else cal.push_back(x*y);
                    }
                }
            }
        }
        
        if(cal.empty()) cal.push_back(stoi(expression));
        return cal;
        
    }
};
