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
struct node
{
    E data;
    node* next;
};

template <typename E>
class linkList
{
	  public:
    node<E>* firstElement;
    node<E>* lastElement;
    node<E>* currentElement;
    int sizeOfList;


        //constructors and destructors
        linkList()
        {
            firstElement = lastElement = currentElement = new node<E>;
            lastElement->next=NULL;
            sizeOfList = 0;
        }
        ~linkList()
        {
            while(firstElement != NULL)
            {

                currentElement = firstElement;
                firstElement = firstElement->next;
                delete currentElement;
            }
        }
         void clear()
        {
            /*node<E> * i;
            i=firstElement;
            while(i!=lastElement)
            {
                i->data=0;
                i=i->next;
            }*/
            while(firstElement != NULL)
            {

                currentElement = firstElement;
                firstElement = firstElement->next;
                delete currentElement;
            }
            sizeOfList=0;
        }
         void insert(const E& Data)
        {
            if(sizeOfList==0)
            {
                firstElement = lastElement = currentElement = new node<E>;
              currentElement->data=Data;
              lastElement->next=NULL;

            }
            else if(currentElement->next==NULL && sizeOfList!=0)
            {
              node<E> * temporary;
              temporary=new node<E>;
              currentElement=temporary;
              currentElement->data=Data;
              lastElement->next=currentElement;
              lastElement=lastElement->next;
              //currentElement=currentElement->next;
              lastElement->next=NULL;
              currentElement->next=NULL;
            }
            else
            {
              node<E> * temporary;
              temporary=new node<E>;
              temporary->data=Data;
              temporary->next=currentElement->next;
              currentElement->next=temporary;
              currentElement=currentElement->next;
            }
            sizeOfList=sizeOfList+1;
        }





	};
template <typename E>
class QueueLinkList:  public Queue<E>
{
    //size of the link list
    int size;
    // Array for storing the data
    linkList<E>* QueueArray;


    public:
        //constructors and destructors
        //constructors and destructors
        QueueLinkList()
        {
            QueueArray = new linkList<E>();
            size=0;

        }
        ~QueueLinkList()
        {
             QueueArray->clear();
            //for the next statement ensure
            // that you have implemented
            // destructor in the linkList class.
            delete QueueArray;
        }
        void insert(const E & element)
        {
			QueueArray->insert(element);
			size++;
		}
		E remove()
		{
		    if(QueueArray->firstElement==NULL)
            {
                cout << "the queue is empty" << endl;
                return -1;
            }
            else
            {
            int i;
			i=QueueArray->firstElement->data;
			QueueArray->firstElement=QueueArray->firstElement->next;
			size--;
			return i;
            }
		}
		int length() const
		{
			return size;
		}
		const E FirstElement() const
		{
		    if(QueueArray->firstElement==NULL)
            {
                cout << "the queue is empty" << endl;
                return -1;
            }
            else
			return QueueArray->firstElement->data;
		}
		void clearQueue()
		{
			QueueArray->clear();
			size=0;
		}
		void display()
         {
            node<E> * temp;

           temp=QueueArray->firstElement;
            //int i=1;
            //while(i<=QueueArray->sizeOfList)
            while(temp)
            {
                cout << temp->data << endl;
                //i++;
                temp=temp->next;
            }


         }




};


int main()
{

    int functiontobeimplemented=6,num;

   QueueLinkList<int> A;
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
             cout << "the queue now is :" << endl;
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



