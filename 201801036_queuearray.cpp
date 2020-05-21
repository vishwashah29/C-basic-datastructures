#include <iostream>

using namespace std;


template <typename E>
class Queue
{
    void operator = (const Queue&) {}
    Queue(const Queue&) {}

    public:
        //constructors and destructors
        Queue() {}
        virtual ~Queue() {}

        // Insert an element at the end of the queue
        virtual void insert(const E & element) = 0;

        //Remove the first element of the queue
        virtual E remove() = 0;

        // Return the length of the queue
        virtual int length() const = 0;

        //Return a copy of the first element
        virtual const E FirstElement() const= 0;

        // Remove all the elements from the Queue
        // and free the occupied memory without causing
        // memory leak
        virtual void clearQueue() = 0;

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
class QueueArrayList:  public Queue<E>
{
    int maximumSize;  //maximum size of the array list
    int firstElement; //index of the first element
    int lastElement; //index of the last element
    arrayList<E>* QueueArray; // Array for storing the data


    public:
        //constructors and destructors
        //constructors and destructors
        QueueArrayList(int size)
        {
            maximumSize = size;
            QueueArray = new arrayList<E>(size);
            firstElement = lastElement = 0;
        }
        ~QueueArrayList()
        {
            delete QueueArray;
        }


         void insert(const E & element)
        {

			if(lastElement==maximumSize)
            {
                cout << "The array has reached its maximum limit and you cannot add more elements" << endl;
            }

            else
            {
				if(lastElement==0)
				{
					firstElement=0;
				}
                 QueueArray->dataArray[lastElement]=element;
                lastElement=lastElement+1;
            }
        }

        E remove()
        {
			if(lastElement==0)
			{
				cout << "The queue is empty and you cannot dequeue" << endl;
				return -1;
			}
			else
			{
				int i;
				int num;
				num = QueueArray->dataArray[firstElement];
				for(i=0;i<lastElement;i++)
				{
					QueueArray->dataArray[i]=QueueArray->dataArray[i+1];
				}
				firstElement=0;
				lastElement=lastElement-1;
				return num;
			}
		}

		int length() const
		{
			return lastElement;
		}

		const E FirstElement() const
		{
			return QueueArray->dataArray[firstElement];
		}

		void clearQueue()
		{
			firstElement=0;
			lastElement=0;
			delete QueueArray;
		}
		void display()
        {
            if(lastElement==0)
            {
                cout <<" Queue is empty;" << endl;
            }
            else
            {
                int i;
                for(i=0;i<lastElement;i++)
                {
                    cout <<" " << QueueArray->dataArray[i] << endl;
                }
            }

        }

};


int main()
{

    int size,functiontobeimplemented=6,num;
    cout << "enter the size of the queue :" << endl;
    cin >> size;
   QueueArrayList<int> A(size);
    while(functiontobeimplemented!=0)
    {
        cout << "\n enter the number of the function you want to implement:" << endl;
        cout << "1. insert "<< endl << "2. remove" << endl << "3. length" << endl << "4. first Element" << endl << "5. clear stack" << endl << "0. exit " << endl;
        cin >> functiontobeimplemented;
        switch(functiontobeimplemented)
        {

        case 1:
            cout << " Enter a number you want to enqueue :  " << endl;
            cin >> num;
            A.insert(num);
            cout << "the queue now is :" << endl;
            A.display();
            break;
        case 2:
            cout << " the number that is removed is:  " << A.remove() << endl;
            cout << "the queue now is :" << endl;
            A.display();
            break;
        case 3:
            cout << "the queue  length is :   " << A.length() << endl;
            cout << "the queue now is :" << endl;
            A.display();
            break;
        case 4:
            cout << "the element at the first element of the queue :  " << A.FirstElement() << endl;
             cout << "the stack now is :" << endl;
            A.display();
            break;
        case 5:
            cout << "your queue is now cleared" << endl;
            A.clearQueue();
             cout << "the queue now is :" << endl;
            A.display();
            break;


        }
    }


}


