#include <iostream>

using namespace std;

template <typename E>
class Stack
{
    void operator = (const Stack&) {}
    Stack(const Stack&) {}

    public:
        //constructors and destructors
        Stack() {}
        virtual ~Stack() {}

        // Return the length of the stack
        virtual int length() const = 0;

        //Return the Location of current element
        virtual void push(const E& element) = 0;

        //clear the current data element from stack
        virtual E pop() = 0;

        //Return a copy of the current element
        virtual const E currentElement() const= 0;

        // Remove all the elements from the stack
        // and free the occupied memory without causing
        // memory leak
        virtual void clearStack() = 0;

};
template <typename E>
class arrayList
{

    public:

    int arraySize; // maximum size of the list
    int currentSize; // number of data elements stored
    int CurrentLocation; // location pointer of the list
    E* dataArray; // Array for storing the data

        //constructors and destructors
        arrayList(int size)
        {
            arraySize = size;
            currentSize = CurrentLocation = 0;
            dataArray = new E[arraySize];
        }
        ~arrayList()
        {
            delete [] dataArray;
        }
 };


template <typename E>
class StackArrayList: public Stack<E>
{
    int stacksize; // size of the stack
    int currentLocation; // location pointer keeping track of
                         // current element
    arrayList<E>* StackArray; // Array for storing the data

    public:
        //constructors and destructors
        StackArrayList(int size)
        {
            stacksize = size;
            StackArray = new arrayList<E>(size);
            currentLocation = 0;
        }
        ~StackArrayList()
        {
            delete StackArray;
        }
        int length() const
        {
            return currentLocation;
        }
        void push(const E& element)
        {
            if(currentLocation==stacksize)
            {
                cout<< "The array has reached its maximum limit and you cannot add more elements" << endl;
            }

            else
            {
                 StackArray->dataArray[currentLocation]=element;
                currentLocation=currentLocation+1;
            }
        }
        E pop()
        {
            if(currentLocation==0)
            {
                cout << "The stack is empty" << endl;
                return -1;
            }
            else
            {
                currentLocation=currentLocation-1;
                return StackArray->dataArray[currentLocation];

            }
        }
        const E currentElement() const
        {
        if(currentLocation==0)
        {
            cout << "stack size is 0" << endl;
        }
        else
        {
           return StackArray->dataArray[currentLocation-1];
        }
        }
        void clearStack()
        {
            currentLocation=0;

            delete StackArray;
        }
        void display()
        {
            if(currentLocation==0)
            {
                cout <<" Stack is empty;" << endl;
            }
            else
            {
                int i;
                for(i=0;i<currentLocation;i++)
                {
                    cout <<" " << StackArray->dataArray[i] << endl; ;
                }
            }

        }

};

int main()
{

    int size,functiontobeimplemented=6,num;
    cout << "enter the size of the stack :" << endl;
    cin >> size;
    StackArrayList<int> A(size);
    while(functiontobeimplemented!=0)
    {
        cout << "\n enter the number of the function you want to implement:" << endl;
        cout << "1. stacklength "<< endl << "2. push" << endl << "3. pop" << endl << "4. current Element" << endl << "5. clear stack" << endl << "0. exit " << endl;
        cin >> functiontobeimplemented;
        switch(functiontobeimplemented)
        {
        case 1:
            cout << "the current stack length is :   " << A.length() << endl;
            cout << "the stack now is :" << endl;
            A.display();
            break;
        case 2:
            cout << " Enter a number you want to push in the stack :  " << endl;
            cin >> num;
            A.push(num);
            cout << "the stack now is :" << endl;
            A.display();
            break;
        case 3:
            cout << " the number that is removed is:  " << A.pop() << endl;
            cout << "the stack now is :" << endl;
            A.display();
            break;
        case 4:
            cout << "the element at the current location of the stack is :  " << A.currentElement() << endl;
             cout << "the stack now is :" << endl;
            A.display();
            break;
        case 5:
            cout << "your stack is now cleared" << endl;
            A.clearStack();
             cout << "the stack now is :" << endl;
            A.display();
            break;


        }
    }


}
