class MyQueue {
private:
    stack<int> main, helper;
public:
    void push(int x) {
        // Push all the elements of main stack into helper stack. 
        while(!main.empty()) {
            helper.push(main.top());
            main.pop();
        }

        // Push the given element into main stack.
        main.push(x);

        // Update the main stack by pushing its previous elements from helper stack.
        while(!helper.empty()) {
            main.push(helper.top());
            helper.pop();
        }
    }
    
    int pop() {
        // The element on the top of main stack will be the queue's front element.
        int frontElement = main.top();
        main.pop();
        return frontElement;
    }
    
    int peek() {
        // The element on the top of main stack will be the queue's front element.
        return main.top();
    }
    
    bool empty() {
        // If main stack is empty, the queue is also empty.
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */