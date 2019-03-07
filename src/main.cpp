#include <iostream>
#include <conio.h>
#include <error_code.h>
#include <queue.h>
#include <fstream>

using namespace std;

int main()
{
    queue q;
    int *out= NULL;
    int a[6] = {1,2,3,4,5,6};
    size_t size_a =  sizeof(a)/sizeof(a[0]);

    cout<<"isempty:"<<q.isEmptyQueue()<<endl;
    cout<<"sizeofQ:"<<q.sizeOfQueue()<<endl;
    if(ESUCCESS == q.peek((void*&)out))
        cout<<"Peek() Out:"<<*out<<endl;
    for(int j = 0;j<5;j++)
    {
        for(int i =0;i<size_a;i++)
        {
            if(ESUCCESS != q.enqueue((void *)(a+i)))
            {
                cout<<"in["<<i<<"]"<<*(a+i)<<endl;
            }
            else
            {
                cout<<"Enqueue Failed";
            }
        }
        
        q.printQ();
        
        cout<<"isempty:"<<q.isEmptyQueue()<<endl;
        cout<<"sizeofQ:"<<q.sizeOfQueue()<<endl;
        if(ESUCCESS == q.peek((void*&)out))
            cout<<"Peek() Out:"<<*out<<endl;

        for(int i =0;i<size_a+1;i++)
        {
            if(EMPTY_QUEUE != q.dequeue((void **)&out))
                cout<<"out["<<i<<"]"<<*out<<endl;
            else
            {
                cout<<"Queue is empty"<<endl;
            }
        }
        q.printQ();
        cout<<"isempty:"<<q.isEmptyQueue()<<endl;
        cout<<"sizeofQ:"<<q.sizeOfQueue()<<endl;
        if(ESUCCESS == q.peek((void*&)out))
            cout<<"Peek() Out:"<<*out<<endl;
    }
    getch();
    return ESUCCESS;
}