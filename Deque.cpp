#include "Deque.h"
#include <iostream>

using namespace std;

Deque::Deque()
{
    cursor = NULL;
    current_size = 0;
    right_p = NULL;
    left_p = NULL;
}

Deque::Deque( const Deque& dq ) // Copy constructor.
{
  if(dq.current_size != 0)
  {
    node * temp = dq.left_p;
    while(temp != NULL)
    {
      push_right(temp->data);
      temp = temp->next;
    }
    cursor = left_p;
    node * temp1 = dq.left_p;
    while(temp1 != dq.cursor)
    {
      cursor_right();
      temp1 = temp1->next;
    }
  }
  else
  {
    left_p = NULL;
    right_p = NULL;
    cursor = NULL;
  }
}

Deque::~Deque() // Destructor.
{
  while(size() != 0)
  {
    pop_left();
  }
}

void Deque::push_left(int item)
{
    if(current_size == 0)
    {
        node * insert = new node(item, NULL, NULL);
        left_p = insert;
        right_p = insert;
        cursor = left_p;
        current_size++;
    }
    else
    {
        node * insert = new node(item, NULL, left_p);
        left_p->prev = insert;
        left_p = insert;
        current_size++;
    }
}

void Deque::push_right(int item)
{
    if(current_size == 0 )
    {
        node * insert = new node(item, NULL, NULL);
        right_p = insert;
        left_p = insert;
        cursor = right_p;
        current_size++;
    }
    else
    {
        node * insert = new node(item, right_p, NULL);
        right_p->next = insert;
        right_p = insert;
        current_size++;
    }
}

int Deque::pop_left()
{
    node* temp = left_p;
    int val = left_p->data;
    if(current_size == 1)
    {
        cursor = NULL;
        right_p = NULL;
        left_p = NULL;

    }
    else
    {
        if(cursor == left_p)
        {
            cursor = cursor->next;
        }
        left_p = left_p->next;
        left_p->prev = NULL;

    }
    delete temp;
    current_size--;
    return val;
}

int Deque::pop_right()
{
    node* temp = right_p;
    int val = right_p->data;
    if(current_size == 1)
    {
        cursor = NULL;
        right_p = NULL;
        left_p = NULL;

    }
    else
    {
        if(cursor == right_p)
        {
            cursor = cursor->prev;
        }
        right_p = right_p->prev;
        right_p->next = NULL;
    }
    delete temp;
    current_size--;

    return val;
}

bool Deque::empty()
{
    return current_size == 0;
}

int Deque::size()
{
    return current_size;
}


bool Deque::cursor_left()
{

    if (cursor->prev!= NULL)
    {
        cursor = cursor->prev;
        return true;
    }
    else
    {
        return false;
    }
}

bool Deque::cursor_right()
{

    if (cursor->next!= NULL)
    {
        cursor = cursor->next;
        return true;
    }
    else
    {
        return false;
    }
}


int Deque::peek_left()
{
    return left_p->data;

}



int Deque::peek_right()
{
    return right_p->data;
}



int Deque::get_cursor()
{
    return cursor->data;
}



void Deque::set_cursor(int i)
{
   cursor->data = i;

}


void Deque::display()
{
    node* temp = left_p;
    if(current_size == 0)
    {
    cout << "[] size=0, cursor=NULL." << endl;
    }
    else
    {
        cout << "[";
        for(int j = 0; j<current_size;j++)
        {
            cout << temp->data<< ";";
            temp = temp->next;
        }

       cout << "]" << " size=" << size() << ", cursor=" << get_cursor() << "." << endl;
   }
}


void Deque::verbose_display()
{
    node* temp = left_p;
    if(current_size == 0)
    {
        cout << "[] size=0, left_p=NULL, right_p=NULL, cursor=NULL." << endl;
    }
    else
    {
        cout << "[";
        for(int j = 0; j<current_size;j++)
        {
            if(temp == left_p)
        {
            cout << "{prev=NULL"<< " node= " << &(temp->next->prev) << " next= " <<&(temp->next)<< "}; " ;
        temp = temp->next;
        }
        else if(temp == right_p)
            {
                cout << "{prev= "<< &(temp->prev) << " node= " << &(temp->prev->next) << " next=NULL}; ";
        temp = temp->next;
            }
        else
        {
                cout << "{prev= "<< &(temp->prev) << " node= "<< &(temp->prev->next) << " next= " <<&(temp->next)<< "}; " ;
                temp = temp->next;
            }

        }

       cout << "]" << " size=" << current_size << ", cursor=" << &cursor <<" , left_p= "<<&left_p<< ", right_p= "<< &right_p<< "." << endl;
   }
    delete temp;
}






