#include "shared.h"
/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 Example:
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> Returns -3.
 minStack.pop();
 minStack.top();      --> Returns 0.
 minStack.getMin();   --> Returns -2.
*/
namespace MinStack{
    class MinStack {
    public:
        /** initialize your data structure here. */
        MinStack(){

        }
        
        void push(int x) {
            _values.push(x);
            if(_minValues.empty())
                _minValues.push(x);
            else if(x <= _minValues.top())
                _minValues.push(x);
        }
        
        void pop() {
            int temp = _values.top();
            _values.pop();
            if(temp == _minValues.top())
                _minValues.pop();
        }
        
        int top() {
            return _values.top();
        }
        
        int getMin() {
            return _minValues.top();
        }
    private:
        stack<int> _values;
        stack<int> _minValues;
    };
    
    TEST(MinStack, minStack){
        MinStack obj;
        obj.push(-2);
        obj.push(0);
        obj.push(-3);
        int min = obj.getMin();
        ASSERT_EQ(-3, min);
        obj.pop();
        min = obj.getMin();
        ASSERT_EQ(-2, min);
    }
}
