/*My Approach is to to compare whatever the pointer is pointing to and compare it to the rest*/
/*My hindsight was I didnt consider about nesting properly it was ok if given data is like {[()]}
but when nested one comes like it will still pass if it is like this [(]) it will fail only if it is like (([)]
This solution is fixed by GPT in runtime it was not good like 305 runtime so not good but in memory 8.5 MB beating like 99%*/

class Solution {
public:
    bool isValid(string s) {
        while(true) {
            int originalLength = s.length();
            size_t pos;
            pos = s.find("()");
            if(pos != string::npos)
                s.erase(pos, 2);
            pos = s.find("{}");
            if(pos != string::npos)
                s.erase(pos, 2);
            pos = s.find("[]");
            if(pos != string::npos)
                s.erase(pos, 2);
            if(s.length() == originalLength)
                break;
        }
        return s.empty();
    }
};

/*Here is the GPT solution*/
/*It make the opening bracket push into stack and check the stack if it is a closing stack
and lastly if the stack is empty then ok if not not valid*/
/*
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s) {

            if(c == '(' || c == '{' || c == '[') {

                st.push(c);
            }

            else {

                if(st.empty()) {
                    return false;
                }

                if(c == ')' && st.top() != '(') {
                    return false;
                }

                if(c == '}' && st.top() != '{') {
                    return false;
                }

                if(c == ']' && st.top() != '[') {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
*/
