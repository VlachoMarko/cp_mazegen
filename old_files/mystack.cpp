#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>


class MyStack {
    public:
        MyStack();                        
        bool isEmpty() const;           
        int top() const;                
        int pop();                      
        void push(int i);   
        int size() const;
        std::string toString() const;
        
    private:
        std::vector<int> elements;
};


MyStack::MyStack() {}

bool MyStack::isEmpty() const 
{
    if (elements.empty() == true)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

int MyStack::size() const {
    return this->elements.size();
}

int MyStack::top() const
{

    if (isEmpty() == true)
    {
        throw std::runtime_error("MyStack is empty");
        return 0;
    }
    else
    {
        int tempReturn = elements.back();
        return tempReturn;
    }
}

int MyStack::pop()
{
    if (isEmpty() == true)
    {
        throw std::runtime_error("MyStack is empty");
        return 0;
    }
    else 
    {
        int tempReturn = elements.back();
        elements.pop_back();
        return tempReturn;
    }
}

void MyStack::push(int i)
{
    elements.push_back(i);
}


std::string MyStack::toString() const
{
    std::string output;
    output += '[';
    std::stringstream iss;

    if (isEmpty() == true)
    {
        output += "]";
        return output;
    }

    for (int i=elements.size()-1; i>=0; i--)
    {
        std::string stackItem; 
        iss << elements.at(i);
        iss >> stackItem;

        output += stackItem;

        if (i != 0)
        {
            output += ',';
        }

        iss.clear();
   }

   output += "]";

   return output;
}




// int main() {
//     MyStack MyStack;
    
//     while (true) {
//         try {
//             std::cout << "MyStack> " << std::endl;
            
//             std::string command;
//             std::cin >> command;
            
//             if ( (command.compare("end") == 0) || std::cin.eof() ){
//                 break;
//             } else if (command.compare("top") == 0) {
//                 std::cout << MyStack.top() << std::endl;
//             } else if (command.compare("pop") == 0) {
//                 std::cout << MyStack.pop() << std::endl;
//             } else if (command == "push") {
//                 if ( std::cin.eof() ) break;
//                 int i;
//                 std::cin >> i;
//                 bool failed = std::cin.fail();
//                 std::cin.clear();
//                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                 if ( failed ){
//                   throw std::runtime_error("not a number");
//                 }
//                 MyStack.push(i);
//             } else if ( command.compare("list") == 0){
//                 std::cout << MyStack.toString() << std::endl;;
//             } else {
//                 throw std::runtime_error("invalid command");
//             }
//         } catch (std::runtime_error& e) {
//             std::cout << "error: " << e.what() << std::endl;
//         }
//     }
    
//     return 0;
// }
