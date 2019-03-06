#include <iostream>
#include <conio.h>
#include <error_code.h>
#include <queue.h>

using namespace std;

int queueNode::setData( void *data )
{
    this->data = data;
}

int queueNode::getData( void **data )
{
    *data = this->data;
}

int queue::enqueue(void* data)
{
    queueNode *node = new queueNode;
    node->setData(data);
    if(NULL == data)
        return EBADPARAM;

    if( NULL == this->front )
    {
        this->front = node;
        node->next = node;
        node->prev = node;
    }
    else
    {
        this->front->prev->next = node;
        node->prev = this->front->prev;
        this->front->prev = node;
        node->next = this->front;         
    }
}

int queue::dequeue( void **data )
{
    if( NULL == this->front )
        return EMPTY_QUEUE;
    
    queueNode *temp = this->front;
    this->front->getData(data);
    this->front = this->front->next;
    //this->front->next

    this->front->prev = temp->prev;
    temp->prev->next = this->front;

    if(this->front == temp)
    {
        this->front = NULL;
        //cout<<"Last node,Queue is empty!";
    }
    
    free(temp);
    temp = NULL;
}

int queue::printQ()
{
    if( NULL == this->front )
    {
        cout<<"Queue is empty"<<endl;
        return EMPTY_QUEUE;
    }
    void *data = NULL;
    queueNode *temp = this->front;
    cout<<"Q:";
    do
    {
        temp->getData(&data);
        cout<<*(int *)data<< " ";
        temp = temp->next;
    }while(NULL != temp && temp != this->front);
    cout<<endl;
}

int queue::sizeOfQueue()
{
    if( NULL == this->front )
    {
        return 0;
    }
    int count = 0;
    void *data = NULL;
    queueNode *temp = this->front;
    do
    {
        count++;
    }while(NULL != temp && temp != this->front);
    return count;
}

bool queue::isEmptyQueue()
{
    if( NULL == this->front )
    {
        return true;
    }
    return false;
}
