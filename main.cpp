#include <iostream>

using namespace std;


template <class T>
class linkedlist
{
private:
    struct node
    {
        T data;
        node *next;
        node *prev;


    };


    node *head;
    node *tail;
    int c=0;

public:

    linkedlist()
    {
        head=NULL;
        tail=NULL;

    }



    ~linkedlist()
    {
        c=0;
        while (head->next != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;

    }

    class iterat
    {
        friend class linkedlist;
    private:
        node *ptr;


    public:
        iterat()
        {

            ptr=NULL;
        }
        iterat(node *newptr)
        {

            ptr=newptr;



        }
        bool operator==(const iterat& itr)
        {
            return ptr == itr.ptr;
        }

        bool operator!=(const iterat& itr)
        {
            return !(*this == itr);
        }


        void operator++(int)
        {
            ptr = ptr->next;

            try
            {

                if(ptr==NULL)
                {
                    throw ptr;
                }

            }
            catch(...)
            {
                cout<<"ERROR you are in the end of the list"<<endl;
            }

        }

        void operator--(int)
        {

            ptr=ptr->prev;

            try
            {

                if(ptr==NULL)
                {
                    throw ptr;
                }

            }
            catch(...)
            {
                cout<<"ERROR you are in the end of the list"<<endl;
            }



        }




        T& operator*()  //const {
        {
            return ptr->data;
        }



    };

    iterat begin()
    {


        return iterat(head);

    }

    iterat end()
    {

        return iterat(tail);
    }
    int sizee()
    {
        int k = 0;
        iterat position=head;
        while(position.ptr!=NULL){
            k++;
            position.ptr = position.ptr->next;
        }
        return k;
    }

    linkedlist(int value, int initial_size)
    {

        head=NULL;
        tail=NULL;

        for(int i =0; i<initial_size; i++)
        {


            node* temp = new node();
            iterat pos = head;

            if(head == NULL)
            {
                temp->data = value;
                temp->prev = NULL;
                temp->next = NULL;
                head = temp;
                tail = temp;


            }
            else
            {
                while (pos.ptr->next !=NULL )
                    pos.ptr = pos.ptr->next;

                temp->data = value;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
                temp->next = NULL;

            }


        }
    }

    iterat insert(const int value)
    {

        node* temp = new node;
        iterat pos = head;

        if(head == NULL)
        {
            temp->data = value;
            temp->prev = NULL;
            temp->next = NULL;
            head = temp;
            tail = temp;


        }
        else
        {
            while (pos.ptr->next !=NULL )
                pos.ptr = pos.ptr->next;



            temp->data = value;
            temp->prev = tail;
            tail->next = temp;
            tail=temp;
            temp->next = NULL;


        }





    }


    iterat erase(iterat position)
    {

        node *toDelete = position.ptr;
        if(toDelete==head)
        {
            head=position.ptr->next;
            delete toDelete;


        }

        else if(toDelete==tail)
        {
            tail = position.ptr->prev;
            delete toDelete;

        }


        else
        {
            position.ptr->prev->next=position.ptr->next;
            position.ptr->next->prev=position.ptr->prev;
            delete toDelete;
        }





        return position;
    }

    linkedlist & operator=(linkedlist & anotherlist)
    {
        node* NewNode = new node;
        iterat curr = anotherlist.begin();
        NewNode->data =curr.ptr->data;
        NewNode->prev = NULL;
        head = NewNode;
        tail = NewNode;
        curr.ptr = curr.ptr->next;

        while(curr.ptr !=NULL)
        {

            node* NewTemp = new node;
            NewTemp->data = curr.ptr->data;
            NewTemp->prev = tail;
            tail->next = NewTemp;
            NewTemp->next=NULL;
            tail = NewTemp;
            curr.ptr = curr.ptr->next;
        }



    }



    void print()
    {

        node* curr= head;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;

        }



        cout<<endl;


    }

};










int main()
{



    linkedlist<int> a(2,7);
    linkedlist<int> v;
    linkedlist<int> s;

    a.print();

    v.insert(1);
    v.insert(2);
    v.insert(3);
    v.insert(4);
    v.insert(5);

    v.print();

    linkedlist<int>::iterat it=v.begin();
    it++;
    v.erase(it);

    s=v;

    s.print();


    linkedlist<int>::iterat it2=s.end();
    it2--;
    it2--;

    cout<<*it2<<endl;





    return 0;
}
