class Solution {
public:
    void PUSH(stack<string> &directory_list, string &directory_name) {
        if(directory_name == ".") return;
        if(directory_name == "..") {
            if(!directory_list.empty()) directory_list.pop();
            return;
        }
        directory_list.push(directory_name);
    }

    string simplifyPath(string path) {
        stack<string> directory_list;
        string directory_name = "", ans = "";
        

        for(char ch: path) {
            if(ch == '/' && directory_name.size()) {
                PUSH(directory_list, directory_name);
                directory_name.clear();
            }
            else if(ch != '/') {
                directory_name += ch;
            }
        }
        if(directory_name.size()) {
            PUSH(directory_list, directory_name);
        }

        while(!directory_list.empty()) {
            directory_name = directory_list.top();

            ans = "/" + directory_name + ans;
            directory_list.pop();
        }

        if(ans.size() == 0) return "/";
        return ans;
    }
};