#ifndef ARRAYSTACK_
#define ARRAYSTACK_


#include "stack.h"
#include <iostream> 

using namespace std;

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength);

template<class T>

class arrayStack : public stack<T> {
public:
    arrayStack(int initialCapacity = 10);
            
    //destructor
    ~arrayStack(){delete [] stack;}
    //checks if stack is empty
    bool empty() const {return stackTop ==-1;}
    // returns the size of stack
    int size() const { return stackTop + 1;}
    // returns the top of the stack (the last T object added)
    T& top(){
        if (stackTop == -1){
            //return 0;
        }
        return stack[stackTop];
    }
    // removes the top of the stack
    void pop() {
        if(stackTop == -1){
            //return false;
        }
        stack[stackTop--].~T(); //destructor for T
    }
    void push(const T& theElement);
private:
    int stackTop; // current top of stack
    int arrayLength; // stack capacity
    T *stack; // element array
};
template<class T>
arrayStack<T>::arrayStack(int initialCapacity){
        if(initialCapacity <1 ){
            cout<< "Initial capacity" << initialCapacity << " must be greater than 0.\n";
            //break;
        }
        arrayLength= initialCapacity;
        stack = new T[arrayLength];
        stackTop=-1;
}
template<class T>
void arrayStack<T>::push(const T& theElement){
        if(arrayLength-1 == stackTop){
            changeLength1D(stack, arrayLength, 2*arrayLength);
            arrayLength*=2;
        }
        stack[++stackTop]=theElement;
}

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength){
    if(newLength<0){
        //throw illegalParameterValue();
    }
    T* temp= new T[newLength];
    int number = min(oldLength,newLength);
    copy(a, a+number, temp);
    delete [] a;
    a=temp;
}


#endif
    
    