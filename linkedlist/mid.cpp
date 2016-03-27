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

    Node* merge(Node* head1, Node* head2) {
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        Node* head = NULL;
        Node* tail = NULL;
        while(head1 != NULL && head2 != NULL) {
            if(head1->data < head2->data) {
                if(!head) {
                    head = head1;
                    tail = head1;
                    head1 = head1->next;
                }
                else {
                    tail->next = head1;
                    head1 = head1->next;
                    tail = tail->next;
                }
            }
            else {
                if(!head) {
                    head = head2;
                    tail = head2;
                    head2 = head2->next;
                }
                else {
                    tail->next = head2;
                    head2 = head2->next;
                    tail = tail->next;
                }
            }
        }
        if(!head1 && head2) {
            while(head2 != NULL) {
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
            }
        }
        else if(!head2 && head1) {
            while(head1 != NULL) {
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
            }
        }

        return head;
    }

    void print(Node* head) {
        while(head) {
            cout<<"--"<<head->data;
            head = head->next;
        }
        cout<<endl;
    }

    Node* findMidNodeHelper(Node* head) {
        if(!head)
            return head;
        cout<<"inside findmidnode"<<endl;
        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
cout<<"returning from findmidnode"<<endl;
        return slow;
    }

    Node* mergesortHelper(Node* head) {
        if(head == NULL || head->next == NULL)
            return head;
cout<<"inside merge and midnode func called"<<endl;
        Node* midNode = findMidNodeHelper(head);
        cout<<"The midnode: "<<midNode->data<<endl;
        Node* head1 = head;
        Node* head2 = midNode->next;
        midNode->next = NULL;
        /*Node* p = head;
        cout<<"dividing the lists"<<endl;
        while(p->next != midNode) {
            p = p->next;
        }
        p->next = NULL;
        cout<<"divided"<<endl;

        print(head1);
        print(head2);*/

        head1 = mergesortHelper(head1);
        head2 = mergesortHelper(head2);
        head = merge(head1, head2);
        return head;
    }

    public:
   
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

    Node* findMidNode() {
        Node* temp =  findMidNodeHelper(head);
        cout<<"midnode: "<<temp->data<<endl;
        return temp;
        
    }

    void mergesort() {
        head = mergesortHelper(head);
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

/*void test(LinkedList & a, LinkedList & b) {
    takeInput(a);
    takeInput(b);
    LinkedList c;
    c.head = merge(a.head, b.head);
    c.print();   

}*/

int main() {

    LinkedList l;
    takeInput(l);
    l.print();
    //l.findMidNode();
    
    l.mergesort();
    l.print();
//    test();

return 0;
}
