// Problem link-: https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
    stack<string>future;
    stack<string> history;
public:
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    void visit(string url) {
        history.push(url);
        while(!future.empty())
            future.pop();
    }
    string back(int steps) {
        int i=0;
        while(i<steps && history.size()>1){
            future.push(history.top());
            history.pop();
            i++;
        }
        return history.top();
    }
    string forward(int steps) {
        int i=0;
        while(i<steps && !future.empty()){
            history.push(future.top());
            future.pop();
            i++;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
