

//Name: Vishwa Shah
//Id: 201801036
//Date:18-4-2019
//Program : Sorting Algorithms








#include<iostream>
using namespace std;

template <typename E>
class List
{
    void operator = (const List&) {}
    List(const List&) {}

    public:
        //constructors and destructors
        List() {}
        virtual ~List() {} // decontructor

        //Return the number of elements in the List
        virtual int NumberOfElements() const = 0; // 'const' method means we can't change the value of any variables of the class

        //Return the Location of current element
        virtual int CurrentLocation() const = 0;

        //Return the data of current element
        virtual const E& getData() const = 0;

        //clear all the data from the List
        virtual void clear() = 0;

        //insert a data in the List at current location
        virtual void insert(const E& data) = 0;

        //insert a data in the end of the List
        virtual void append(const E& data) = 0;

        //delete a data at the current Location
        virtual E remove() = 0;

        //set the current Location to the start of the List
        virtual void setListLocationToStart() = 0;

        //set the current Location to the end of the List
        virtual void setListLocationToEnd() = 0;

        //set the current Location to the element on left side
        // of current element
        virtual void previousElement() = 0;

        //set the current Location to the element on left side
        // of current element
        virtual void nextElement() = 0;

        //Set current Location to a new Location
        virtual int setToNewLocation(int location) = 0;

        virtual void display() =0;

        };



// Array "arrayList" which inherites the base class "List"
template <typename E>
class arrayList: public List<E>
{
    int arraySize; // maximum size of the list
    int currentSize; // number of data elements stored
    int currentLocation; // location pointer of the list
    E* dataArray; // Array for storing the data

    public:
        //constructors and destructors
        arrayList(int size)
        {
            arraySize = size;
            currentSize = currentLocation = 0;
            dataArray = new E[arraySize];
        }
        ~arrayList()
        {
            delete [] dataArray;  // deleting the memory we allocated to dataArray in the heap
        }
	arrayList(const arrayList & A)
	{
		arraySize=A.arraySize;
		currentSize=A.currentSize;
		int i;
		for(i=0;i<currentSize;i++)
		{
			dataArray[i]=A.dataArray[i];
		}
		currentLocation=A.currentLocation;
	}

	void operator = (const arrayList& A)
	{
		arraySize=A.arraySize;
		currentSize=A.currentSize;
		int i;
		for(i=0;i<currentSize;i++)
		{
			dataArray[i]=A.dataArray[i];
		}
		currentLocation=A.currentLocation;
	}
	//implementation of inherited member functions

	//Return the number of elements in the List
        int NumberOfElements() const
	{
		return currentSize ;
	}

	//Return the Location of current element
	int CurrentLocation() const
	{
		return currentLocation;
	}

	 //Return the data of current element
	const E& getData() const
	{

		return (dataArray[currentLocation]);
	}


	//clear all the data from the List
        void clear()
	{
		int i;
		for(i=0;i<arraySize;i++)
		{
			dataArray[i]=0;
		}
		currentLocation=0;
		currentSize=0;
	}

        //insert a data in the List at current location
        void insert(const E& data)
	{
		int i;
		if(currentSize >= arraySize)
        {
            cout << "memory Full" << endl;
        }
        	else
        	{
                if(currentSize==0)
                {
                    currentLocation=0;
                    dataArray[currentLocation]=data;
                    currentSize++;
                }
                else

                {
                    for(i=currentSize-1;i>=currentLocation;i--)
                    {
                        dataArray[i+1]=dataArray[i];
                    }
                    dataArray[currentLocation]=data;
                    currentSize++;

                }
        	}
	}

        //insert a data in the end of the List
        void append(const E& data)
	{
		if(currentSize >= arraySize)
		{
			cout << "memory Full" << endl;

		}
		else
		{
			dataArray[currentSize]=data;
			currentSize++;
			currentLocation=currentSize-1;
		}
	}

        //delete a data at the current Location
        E remove()
	{
		int i;
		E temp=dataArray[currentLocation];
        if(currentLocation<currentSize)
        {
    		for(i=currentLocation;i<currentSize-1;i++)
		{
			dataArray[i]=dataArray[i+1];
		}
		dataArray[currentSize-1]=0;

		currentSize=currentSize-1;
		return temp;
        }
        else{
            return 0;
        }
	}

        //set the current Location to the start of the List
        void setListLocationToStart()
	{
		currentLocation=0;
	}

        //set the current Location to the end of the List
        void setListLocationToEnd()
	{
		currentLocation=currentSize;
	}

        //set the current Location to the element on left side
        // of current element
        void previousElement()
	{
		currentLocation=currentLocation-1;
        }

        //set the current Location to the element on right side
        // of current element
        void nextElement()
        {
		if(currentLocation>=arraySize)
		{
			 cout << "you have reached the end of the array" << endl;

		}
		else
		{
			currentLocation=currentLocation+1;
		}
	}

        //Set current Location to a new Location
        int setToNewLocation(int location)
	{
	   // cout << "location" << location << endl;
		if(location>=currentSize)
		{
			 cout << "the location you entered is greater than the size of the array " << endl;
			return 0;

		}
		else
		{
			currentLocation=location;
			//cout << "end" << endl;
			return dataArray[currentLocation];
		}

	}
	void display()
	{
		int i;
		for(i=0;i<currentSize;i++)
		{
			cout << dataArray[i];
			cout << " ";
		}
	}

	};


	template <typename E>
struct node
{
    E data;
    node* next;
};



template <typename E>
class linkList: public List<E>
{
    node<E>* firstElement;
    node<E>* lastElement;
    node<E>* currentElement;
    int sizeOfList;

    public:
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
        //operator overloading
        linkList(const linkList & A)
	{

		 /*node<E> * i;
         i=A.firstElement;
         while(i->next!=NULL)
		 {
			insert(i->data);
			i=i->next;
		 }*/
		 firstElement=A.firstElement;
		 lastElement=A.lastElement;
		 sizeOfList=A.sizeOfList;
		 node<E> * temp1;
		 temp1=A.firstElement->next;
		 int i=1;
		 for(i=1;i<sizeOfList;i++)
		 {
			 node<E> * temp= new node<E>;
			 temp->data=temp1->data;
			 temp->next=temp1->next;
			 temp1=temp1->next;
		 }
		 currentElement=A.currentElement;

	}


	void operator = (const linkList& A)
	{
		sizeOfList=0;
		 node<E> * i;
         i=A.firstElement;
         while(i->next!=NULL)
		 {
			insert(i->data);
			i=i->next;
		 }
		sizeOfList=A.sizeOfList;
		/* firstElement=A.firstElement;
		 lastElement=A.lastElement;
		 sizeOfList=A.sizeOfList;
		 node<E> * temp1;
		 temp1=A.firstElement->next;
		 int i=1;
		 for(i=1;i<sizeOfList;i++)
		 {
			 node<E> * temp= new node<E>;
			 temp->data=temp1->data;
			 temp->next=temp1->next;
			 temp1=temp1->next;
		 }
		 currentElement=A.currentElement;*/
	}

	//Return the number of elements in the List
        int NumberOfElements() const
        {
            return sizeOfList;
        }

    //Return the Location of current element
        int CurrentLocation() const
        {
			node<E> * temp;

			int i=0;
			temp=firstElement;
			while(temp!=currentElement)
			{
				temp=temp->next;
				i=i+1;
			}
            return i+1;
        }

        //Return the data of current element
        const E& getData() const
        {
            return currentElement->data;
        }

        //clear all the data from the List
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

		//insert a data in the List at current location
        void insert(const E& Data)
        {
            if(sizeOfList==0)
            {
    firstElement = lastElement = currentElement = new node<E>;
              firstElement->data=Data;
              firstElement->next=NULL;



            }
            else if(currentElement==firstElement && sizeOfList!=0)
            {
              node<E> * temporary;
              temporary=new node<E>;
              temporary->data=Data;
		   firstElement=temporary;
              firstElement->next=currentElement;
              currentElement=firstElement;
              //currentElement=currentElement->next;

            }
            else if(currentElement!=firstElement && sizeOfList!=0)
            {
              node<E> * temporary;
              temporary=new node<E>;
              temporary->data=Data;
              node<E> * temp2;
              for(temp2=firstElement;temp2->next!=currentElement;temp2=temp2->next)
             {
                 ;
             }

              temporary->next=currentElement;
              temp2->next=temporary;
              currentElement=temporary;
            }



            sizeOfList=sizeOfList+1;

        }


        //insert a data in the end of the List
        void append(const E& Data)
        {
              node<E> * temporary;
              temporary=new node<E>;
              temporary->data=Data;
              lastElement->next=temporary;
              lastElement=lastElement->next;
             // currentElement=currentElement->next;
              lastElement->next=NULL;
              sizeOfList=sizeOfList+1;
        }


         //delete a data at the current Location
         E remove()
         {
             E Data;

             if(currentElement==firstElement)
             {
                Data=currentElement->data;
                firstElement=firstElement->next;
                currentElement=currentElement->next;
                sizeOfList--;
                return Data;

             }

             else
             {
                  node<E> * temp;
                  temp=firstElement;
                  for(temp=firstElement;temp->next!=currentElement;temp=temp->next)
                  {
                  }
                    if(temp->next==lastElement && temp->next==currentElement)
                    {
                        Data=currentElement->data;
                        lastElement=temp;
                        currentElement=temp;
                        temp->next=NULL;
                        lastElement->next=NULL;
                        currentElement->next=NULL;
                        sizeOfList--;
                        return Data;

                    }
                    else if (temp->next!=lastElement && temp->next==currentElement)
                    {
                        Data=currentElement->data;
                        temp->next=currentElement->next;
                        currentElement=temp->next;
                        sizeOfList--;
                        return Data;

                    }
                    else
                    {
                        return 0;
                    }

             }

         }


         //set the current Location to the start of the List
         void setListLocationToStart()
         {
             if(sizeOfList==0)
             {
                 cout << "The list is empty " << endl;
             }
             else
             {
                  currentElement=firstElement;
             }

         }

         //set the current Location to the end of the List
         void setListLocationToEnd()
         {
             if(sizeOfList==0)
             {
                 cout << "The list is empty " << endl;
                 //exceptions
             }
             else
             {
                currentElement=lastElement;
             }
         }

         //set the current Location to the element on left side
        // of current element
         void previousElement()
         {
             if(currentElement!=firstElement)
             {
                node<E> * temp;
                temp=firstElement;
                int i=1;
                while(i<=sizeOfList)
                {


                    if(temp->next==currentElement)
                    {
                        currentElement=temp;
                        break;

                    }
                    else
                    {
                        i++;
                        temp=temp->next;
                    }
                }

             }
             else
             {
                 cout << "the current location is pointing to the first element can't set to the previous element" << endl;
             }

         }

         //set the current Location to the element on right side
        // of current element
         void nextElement()
         {
             if(currentElement!=lastElement)
             {
                  currentElement=currentElement->next;
             }
             else
             {
                 cout << "the current element points to the last location there is no next element" << endl;
             }

         }

           //Set current Location to a new Location
         int setToNewLocation(int location)
         {
             node<E> * temp;
             temp=firstElement;

             if(location>sizeOfList)
             {
				 cout << " The list is smaller than the location you want to set"<< endl;
				 return -1;
			 }

			 else
			 {
				int i=0;
				while(i!=location)
				{
					temp=temp->next;
					i++;
				}
				currentElement=temp;
				return getData();
			}

            /* for(temp=firstElement;temp!=lastElement;temp=temp->next)
             {
                 if(temp->data==location)
                 {
                     currentElement=temp;
                     i++;

                 }

             }
             if(i==0)
             {
                 cout << "the particular element not found in the entire list" << endl;
             }*/


         }

		// Display the given list
         void display()
         {
            node<E> * temp;


            temp=firstElement;
            cout << "firstElement" << temp->data << endl;
            int i=1;
		//cout<<"Size of list :"<<sizeOfList<<endl;

            while(i<=sizeOfList)
           {
                cout <<temp->data<< endl;
                i++;
                temp=temp->next;

            }

         }

};

//swap function
template <typename E>
void swap(List<E> *A,int i,int index)
{
    		A->setToNewLocation(i);


		int temp=A->getData();
		A->setToNewLocation(index);
		int temp2 = A->getData();
		A->setToNewLocation(i);
		A->remove();
		A->setToNewLocation(i);
		A->insert(temp2);
		A->setToNewLocation(index);
		A->remove();
		A->setToNewLocation(index);
		A->insert(temp);


}

//implementation of selection sort

template <typename E>
void selection_sort(List<E> * A)
{
	int n,i,j,index,temp,min;
	A->setListLocationToStart();
	n=A->NumberOfElements();
	cout << n<< endl;
	for(i=0;i<n-1;i++)
	{
		A->setToNewLocation(i);

		min=A->getData();
		index = i;
		for(j=i+1;j<n;j++)
		{
			A->setToNewLocation(j);

			if(A->getData() < min)
			{
				min=A->getData();
				index=j;
			}

		}
		swap(A,i,index);
	}

	}

	//implementation of Bubble sort

	template <typename E>
	void bubble_sort(List<E> * A)
	{

        A->setListLocationToStart();
	   int  n=A->NumberOfElements();
	    int i,j,temp1,temp2;
	    for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                A->setToNewLocation(j);
                temp1=A->getData();
                A->setToNewLocation(j+1);
                temp2=A->getData();
                if(temp1>temp2)
                {
                    swap(A,j,j+1);
                }
            }
        }


	}


//implementation of merge sort
template <typename E>
void MergeSort(List<E> *L,int l, int r)
{
    //MERGE SORT
    if(r<=l)
    return;
    else
    {
        int m=(l+r)/2;
        MergeSort(L,l,m);
        MergeSort(L,m+1,r);
        Merge(L,l,m,r);
    }
}

template <typename E>
void Merge(List<E> *L,int const l, int m, int r)
{

    int i,cl,cr;
    cl=l;
    cr=m+1;
    E Ltemp[r-l+1];
    for(i=l;i<=r;i++)
    {
        L->setToNewLocation(i);
        Ltemp[i-l]=L->getData();
    }
    E a,b;
    for(i=l;i<=r;i++)
    {
        if(cl<=m && cr<=r)
        {
            a=Ltemp[cl-l];
            b=Ltemp[cr-l];
            if(a<b)
            {
                L->setToNewLocation(i);
                L->remove();
                L->insert(a);
                cl++;
            }
            else
            {
                L->setToNewLocation(i);
                L->remove();
                L->insert(b);
                cr++;
            }
        }
        else if(cl>m)
        {
            b=Ltemp[cr-l];
            L->setToNewLocation(i);
            L->remove();
            L->insert(b);
            cr++;
        }
        else if(cr>r)
        {
            a=Ltemp[cl-l];
            L->setToNewLocation(i);
            L->remove();
            L->insert(a);
            cl++;
        }
    }
}


/*	template <typename E>
	void merge_sort(List<E> * A)
	{
	    int i,j,temp1,temp2;
        int n=A->NumberOfElements();
        cout << "number of elementrs:" << n << endl;
	    if(n<2)
        {
            return ;
        }

        int mid=n/2;
        cout << "mid" << mid << endl;
        List<E> * Left;
        List<E> * Right;
        int nL=mid; //size of left subarray
        int nR=n-mid; // size of Right subarray

        for(i=0;i<mid;i++)
        {
            A->setToNewLocation(i);
            temp1=A->getData();
            cout << "temp1" << temp1 << endl;
            Left->append(temp1);

        }
        cout << "display Left" << endl;
         Left->display();
        for(j=mid;j<n-mid;j++)
        {
            A->setToNewLocation(j);
            temp2=A->getData();
            Right->append(temp2);
        }
            cout << "display Right" << endl;
             Right->display();


        merge_sort(Left);
        merge_sort(Right);
        Merge(Left,Right,A);
	}

	template <typename E>
	void Merge(List<E> * Left,List<E> * Right,List<E> * A)
	{
	   int nL=Left->NumberOfElements();
	   int  nR=Right->NumberOfElements();
	   int i=0,j=0,temp1,temp2;
	   while(i<nL && j<nR)
       {
           Left->setToNewLocation(i);
           Right->setToNewLocation(j);
           temp1=Left->getData();
           temp2=Right->getData();
           if(temp1>temp2)
           {
               A->append(temp2);
               j++;

           }
           else
           {
               A->append(temp1);
               i++;

           }
       }
           while(i<nL)
           {
               Left->setToNewLocation(i);
               temp1=Left->getData();
               A->append(temp1);
               i++;
           }
           while(j<nR)
           {
               Right->setToNewLocation(j);
                temp2=Right->getData();
                A->append(temp2);
                j++;

           }





	}
*/


//implementation of quick sort

template <typename E>
void quick_sort(List<E> *l,int start,int end)
{   int pindex;
   	if(start<end)
   	{
   	    pindex=partition(l,start,end);
   	    quick_sort(l,start,pindex-1);
   	    quick_sort(l,pindex+1,end);
   	}

}
template <typename E>
int partition(List<E> *l,int start,int end)
{
    int pivot=0,i=0,current=0,idata=0,i_d=0,high=0;
    l->setToNewLocation(end);

       pivot=l->getData();
       i=(start-1);

    for(int j=start; j<=end-1;j++)
    {
        l->setToNewLocation(j);

       current=l->getData();
       if(current<=pivot)
       {
           i++;
           l->setToNewLocation(i);
           idata=l->getData();
           l->remove();
           l->insert(current);
           l->setToNewLocation(j);
           l->remove();
           l->insert(idata);
       }
    }
    l->setToNewLocation(end);
    high=l->getData();
    l->setToNewLocation(i+1);
    i_d=l->getData();
    l->remove();

    l->insert(high);
    l->setToNewLocation(end);
    l->remove();
    l->insert(i_d);
    return i+1;

}


   /* template <typename E>
	void quick_sort(List<E> * A,int start,int endindex)
	{
	    if(start>=endindex)
        {
          return ;
        }
	    int pindex=partition_sort(A,start,endindex);
	    cout << "pindex" << pindex;

	    quick_sort(A,start,pindex-1);
	    quick_sort(A,pindex+1,endindex);


	}

    template <typename E>
	int partition_sort(List<E> * A,int start,int endindex)
	{
	    cout << "start" << start << endl;
	    cout <<"end" << endindex << endl;
	    int i;
	    int pindex=start;
	    A->setToNewLocation(endindex);
	    int p ivot=A->getData();
	    cout << "pivot" << pivot << endl;
	    for(i=0;i<=endindex-1;i++)
        {
            A->setToNewLocation(i);
            int temp1=A->getData();
            if(temp1<pivot)
            {
                swap(A,i,pindex);
                pindex++;
            }
        }
        swap( A,pindex,pivot);
        return pindex;
	}
*/


















int main()

{


   int functiontobeimplemented,size,no,i=0;
    cout << "enter the size of the list" << endl;
    cin >> size;
    arrayList<int> B(size);

		while(i<size)
		{
			cout << "Enter the  element of the list" << endl;
			cin >> no;
			B.append(no);
			i++;
		}
		cout << " Your List is:" << endl;
		B.display();


	cout << "what sorting function do you want to implement? " << endl;
	cout << "enter 1. Selection sort" <<endl <<" 2.Bubble sort" << endl << "3. merge sort" << endl << "4 quick sort" << endl;
	cin >> functiontobeimplemented;
	switch(functiontobeimplemented)
	{
		case 1:
		{
            selection_sort(&B);
            cout << "the sorted array is" << endl;
            B.display();
            break;
		}
		case 2:
		{
            bubble_sort(&B);
               cout << "the sorted array is" << endl;
            B.display();
            break;
		}

		case 3:
		{
            MergeSort(&B,0,size-1);
               cout << "the sorted array is" << endl;
            B.display();
            break;
		}

		case 4:
		{
            quick_sort(&B,0,size-1);

               cout << "the sorted array is" << endl;
            B.display();
            break;
		}


    }
}



















