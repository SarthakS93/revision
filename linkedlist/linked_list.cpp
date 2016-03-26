#include<bits/stdc++.h>
using namespace std;

class LinkedList;

class Node {
    int data;
    Node* next;

    public:
    Node(int data) {
        this->data = data;
        next = NULL;
    }  

    friend class LinkedList;
};

class LinkedList {
    Node* head;
    
    public:
    LinkedList(): head(NULL) {        
    }

    LinkedList(LinkedList const & s) {
        this->head = NULL;
        Node* temp = s.head;
        Node* tail = NULL;

        while(temp != NULL) {
            Node* newNode = new Node(temp->data);
            if(this->head == NULL)
                this->head = newNode;
            else
                tail->next = newNode;
            tail = newNode;
            temp = temp->next;
        }
    }

    private:

    void printReverseHelper(Node* head) {
        if(head == NULL) 
            return;
        printReverseHelper(head->next);
        cout<<head->data<<" ";
    }




    int findElementRecursivelyHelper(Node* head, int data) {
        if(head == NULL)
            return -1;
        if(head->data == data)
            return 1;
        int k = findElementRecursivelyHelper(head->next, data);
        if(k == -1)
            return -1;
        else
            return 1 + k;
    }

    int lengthHelper(Node* head) {
        if(head == NULL)
            return 0;
        return (1 + lengthHelper(head->next));
    }

    Node* reverseIterativeHelper(Node* head) {
        Node *current, *next, *prev;
        current = head;
        prev = NULL;

        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    bool palindromeHelper(Node* head, Node* & index) {
        if(head == NULL)
            return true;
        bool temp = palindromeHelper(head->next, index);
        if(!temp) {
            return temp;
        }

        if(head->data == index->data) {
            index = index->next;
            return true;
        }
        else {
            return false;
        }
    }

    Node* kreverseHelper(Node* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        Node *current = head, *prev = NULL, *nextNode;
        int ctr = 0;

        while(current != NULL && ctr < k) {
            prev = current;
            current = current->next;
            ctr++;
        }
        prev->next = NULL;
        Node* p = current;

        current = head;
        prev = NULL;

        while(current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head->next = kreverseHelper(p, k);
        head = prev;

        return head;
    }

    Node* reverseRecursiveHelper(Node* head) {
        if(head == NULL || head->next == NULL)
            return head;

        Node* smallerHead = reverseRecursiveHelper(head->next);
        head->next->next = head;
        head->next = NULL;
        return smallerHead;
    }

    public:

    int findElement(int data) {
        Node* p = head;
        int position = 0;
        while(p != NULL) {
            if(p->data == data)
                return position;
            p = p->next;
            position++;
        }
        return -1;
    }

    int findElementRecursively() {
        cout<<"Enter the item to be searched for: "<<endl;
        int data;
        cin>>data;
        return findElementRecursivelyHelper(head, data);
    }

    void addAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }


    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }

    ~LinkedList() {
        while(head != NULL) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }

    int length() {
        return lengthHelper(head);
    }

    Node* midPoint(Node* head) {
        if(head == NULL)
            return NULL;
        Node* fast = head->next;
        Node* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    void printMidNodeData() {
        Node* mid = midPoint(head);
        cout<<"The data of mid node is: "<<mid->data<<endl;
    }

    void reverseIterative(){
        head = reverseIterativeHelper(head);
        cout<<"Reversed!!"<<endl;
    }

    void nthNodeFromEnd(int n) {
        int i = 0;
        Node* fast = head;
        while(i < n && fast != NULL) {
            i++;
            fast = fast->next;            
        }
        if(i < n) {
            cout<<"Invalid!!"<<endl;
            return;
        }
        Node* slow = head;
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        cout<<n<<"th node from end is: "<<slow->data<<endl;      
    }

    void bubbleSort() {
        Node *current, *prev;
        int len = lengthHelper(head);
        for(int i = 0; i < len; i++) {
            current = head;
            prev = NULL;
            while(current != NULL && current->next != NULL) {
                if(current->data > current->next->data) {
                    if(prev == NULL) {
                        Node* nextNode = current->next;
                        current->next = nextNode->next;
                        nextNode->next = current;
                        head = nextNode;
                        prev = nextNode;                    
                    }
                    else {
                        Node* nextNode = current->next;
                        current->next = nextNode->next;
                        nextNode->next = current;
                        prev->next = nextNode;                    
                        prev = nextNode;                    
                    }

                }
                else {
                    prev = current;
                    current = current->next;
                }
            }
        }
        cout<<"Sorted!!"<<endl;
    }

    void palindrome() {
        Node* index = head;
        bool temp =  palindromeHelper(head, index);
        if(temp) {
            cout<<"Yes its a palindrome!!"<<endl;
            return;
        }
        else {
            cout<<"Its not a palindrome!!"<<endl;
            return;
        }
    }

    void removeDuplicatesSorted() {
        Node *p = head;
        while(p != NULL && p->next != NULL) {
            if(p->data == p->next->data) {
                Node* temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else {
                p = p->next;
            }
        }
    }

    void kreverse() {
        int k;
        cout<<"Enter k: "<<endl;
        cin>>k;
        head = kreverseHelper(head, k);
    }

    void appendLastNInFront() {
        Node *fast = head, *slow = head, *prev = NULL;
        int n, i = 1;
        cout<<"Enter n: "<<endl;
        cin>>n;
        while(i < n) {
            i++;
            fast = fast->next;
        }

        while(fast!= NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = NULL;
        Node* temp = slow;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        head = slow;

        cout<<"Appended the last "<<n<<" nodes in front"<<endl;
    }

    /*void removeDuplicatesUnsorted() {
        Node* current = head;
        Node* prev = NULL;
        unordered_map<int, bool> mymap;
        while(current != NULL) {
            if(mymap.count(current->data) != 1) {
                mymap[current->data] = true;
                prev = current;
                current = current->next;
            }
            else {
                Node* nextNode = current->next;
                prev->next = nextNode;
                delete current;
                current = nextNode;
            }
        }
    }*/

    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
        cout<<"Reversed!!"<<endl;
    }

    void printReverse() {
        cout<<"Reverse Print is as follows: "<<endl;
        printReverseHelper(head);
        cout<<""<<endl;
    }

};

    void takeInput(LinkedList & a) {
        int x;
        cout<<"Enter next element and -1 to stop: ";        
        cin>>x;
        while(x != -1) {
            a.addAtBeginning(x);
            cout<<"Enter next: ";
            cin>>x;
        }
    }

int main() {

    LinkedList a;
    takeInput(a);
    a.print();
    //cout<<"The length is: "<<a.length()<<endl;
    //cout<<"The position of element is: "<<a.findElementRecursively()<<endl;
    //a.printMidNodeData();
    //a.reverseIterative();
    //a.print();
    //a.nthNodeFromEnd(3);
    //a.bubbleSort();
    //a.print();
    //a.palindrome();
    //a.removeDuplicatesSorted();
    //a.print();
    a.reverseRecursive();
    //a.removeDuplicatesUnsorted();
    a.print();
    a.kreverse();
    a.print();
    a.appendLastNInFront();
    a.print();

return 0;
}
