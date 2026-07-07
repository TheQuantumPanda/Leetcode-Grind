/*After doing that dumb shit Imma do a medium one*/
/*The question looks a backtracking one not to good with it but here we go*/
/*Here is the code*/
class Solution {
public:
    vector<string> ans;

    void solve(int open, int close,int n, string &current) {
        if (current.size() == 2*n){
            ans.push_back(current);
            return;
        }
        if (open < n){
            current.push_back('(');
            solve(open+1, close,n , current);
            current.pop_back();
        }
        if(close < open) {
            current.push_back(')');
            solve(open, close+1, n, current);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string current = "";
        solve(0,0,n,current);
        return ans;
    }
};
/*After 28 mins the solution got submitted dang got basic logic and syntax mistake -_-*/
/*GPT improved my code and gave more output*/
/*GPT improved code*/
class Solution {
public:
    vector<string> ans;
    void solve(int open, int close, int n, string &current)
    {
        if(open == n && close == n)
        {
            ans.push_back(current);
            return;
        }
        if(open < n)
        {
            current.push_back('(');
            solve(open + 1, close, n, current);
            current.pop_back();
        }
        if(close < open)
        {
            current.push_back(')');
            solve(open, close + 1, n, current);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string current;
        current.reserve(2 * n);
        solve(0, 0, n, current);
        return ans;
    }
};
/*This halved the runtime*/

/*This also a similar approach but takes 0ms runtime*/
/*
class Solution {
    void f(int open,int close,vector<string>& v,string s,int n){
        if(s.length()>=2*n){
            v.push_back(s);
            return ;
        }
        if(open<n){
            f(open+1,close,v,s+"(",n);
        }
        if(close<open){
            f(open,close+1,v,s+")",n);
        }
        
      
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        f(0,0,v,"",n);
        return v;
    }
};
*/
