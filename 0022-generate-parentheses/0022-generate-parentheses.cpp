class Solution {
private:
    void generate(int n , string& s , vector<string>& res, int open , int close){
        if(open+close == 2*n){
            res.push_back(s);
            return;
        }

        if(open<n){
            s.push_back('(');
            generate(n,s,res,open+1,close);
            s.pop_back();
        }

        if(close<open){
            s.push_back(')');
            generate(n,s,res,open,close+1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>res;
        generate(n,s,res,0,0);
        return res;
    }
};