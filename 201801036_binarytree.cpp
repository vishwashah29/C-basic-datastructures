//Name:Vishwa Shah
//Id:201801036
//Date:18/04/19
//Assignment 5-Implementation of Binary Tree



#include<iostream>

using namespace std;


//Binary tree node abstract class
template <typename E>
class BinNode
{
    public:

    virtual ~BinNode() {}

    virtual E& getValue() = 0;

    virtual void setValue(const E&) = 0;

    virtual bool isLeaf() = 0;
};

template <typename E>
class BinaryTreeNode : public BinNode<E>
{
    E value; // The node's value
    BinaryTreeNode* leftChild; // Pointer to left child
    BinaryTreeNode* rightChild; // Pointer to right child

    public:
    // constructors and destructor
    BinaryTreeNode() { leftChild = rightChild = NULL; }
    BinaryTreeNode(E v, BinaryTreeNode* l =NULL, BinaryTreeNode* r =NULL)
    {value = v; leftChild = l; rightChild = r; }
    ~BinaryTreeNode() // Destructor
    { delete leftChild; delete rightChild;}

    // Functions to set and return the value and key
    E& getValue() { return value; }
    void setValue(const E& e) { value = e; }

    // Functions to set and return the children
    inline BinaryTreeNode* left() const { return leftChild; }
    void setLeft(BinaryTreeNode<E>* b) { leftChild = b;}
    inline BinaryTreeNode* right() const { return rightChild; }
    void setRight(BinaryTreeNode<E>* b) { rightChild = b; }

    // Return true if it is a leaf, false otherwise
    bool isLeaf() { return (leftChild = NULL) && (rightChild == NULL); }
};

template <typename E>
class BinTree{
    private:
        int size = 1;
        BinaryTreeNode<E>* root;
    public:
       BinTree() {root=NULL;}

        BinaryTreeNode<E>* getRoot(){return root;}

        BinaryTreeNode<E>* getNode(int i){
            if(i==0){
                return root;
            }

            BinaryTreeNode<E> *n = getNode((i-1)/2);

            if(i%2 != 0){
                return n->left();
            }else{
                return n->right();
            }
        }

        void insert(E value){
            BinaryTreeNode<E> *n = new BinaryTreeNode<E>(value);
            if(root==NULL) root=n;
            else
            {
            int pi = (size-1)/2;
            BinaryTreeNode<E> *parent = getNode(pi);
            if(size%2 == 0){
                parent->setRight(n);
            }else{
                parent->setLeft(n);
            }
            size++;
            }
        }

        void preorder(BinaryTreeNode<E> *node){
            if(node == NULL){
                return;
            }

            cout << node->getValue() << " ";
            preorder(node->left());
            preorder(node->right());

        }

        void inorder(BinaryTreeNode<E> *node){
            if(node == NULL){
                return;
            }

            inorder(node->left());
            cout << node->getValue() << " ";
            inorder(node->right());
        }

        void postorder(BinaryTreeNode<E> *node){
            if(node == NULL){
                return;
            }

            postorder(node->left());
            postorder(node->right());
            cout << node->getValue() << " ";
        }


        BinaryTreeNode<E>* searchit(BinaryTreeNode<E>* node,int value)
        {
        if(node==NULL) return NULL;

         if(node->getValue()==value) return node;
         BinaryTreeNode<E> * temp;
         temp = searchit(node->left(),value);

         if(temp!=NULL)
         {
             return temp;
         }
        else
        {
            return searchit(node->right(),value);
        }

        }

        void Delete(int value)
        {
            BinaryTreeNode<E> * node = searchit(root,value);

            if(node==NULL) cout << "Value not found or tree is empty\n";
            else
            {
                BinaryTreeNode<E>* last = getNode(size-1);

                swap(node->getValue(),last->getValue());

                last = getNode( (size-2)/2 );

                if(size%2==1) last->setRight(NULL);
                else last->setLeft(NULL);

            size--;
            }

        }
};

int main()
{
    BinTree<int> B;

    int choice =0;
    while(choice != -1){
        cout << "1-Insert\n2-Delete\n3-Preorder\n4-Inorder\n5-Postorder\n-1-Exit:";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter the value:";
                int val;
                cin >> val;
                B.insert(val);
                break;
            }
            case 2:{
                cout << "Enter the value to delete:";
                int val;
                cin >> val;
                B.Delete(val);
                break;
            }
            case 3:{
                B.preorder(B.getRoot());
                cout << endl;
                break;
            }
            case 4:{
                B.inorder(B.getRoot());
                cout << endl;
                break;
            }
            case 5:{
                B.postorder(B.getRoot());
                cout << endl;
                break;
            }
        }
    }
}
