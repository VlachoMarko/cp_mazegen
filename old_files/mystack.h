#include <iostream>
#include <vector>
#include <string>
#ifndef MyStack_H
#define MyStack_H


class MyStack {
    public:
        MyStack();                        
        bool isEmpty() const;           
        int top() const;                
        int pop();     
        int size() const;                 
        void push(int i);  
        
    private:
        std::vector<int> elements;
};

#endif