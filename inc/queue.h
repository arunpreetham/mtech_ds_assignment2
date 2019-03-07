class queue;

class queueNode
{
    friend class queue;
    private:
    void *data;

    queueNode *next, *prev;

    public:
    queueNode()
    {
        this->data = NULL;
        this->next = NULL;
        this->prev = NULL;
    }
    
    ~queueNode()
    {
        this->data = NULL;
        this->next = NULL;
        this->prev = NULL;
    }
    int setData(void *data);
    int getData(void **data);
    int addNode();
};

class queue
{
    private:
    queueNode *front;
    size_t sizeOfQ;

    public:
    queue()
    {
        this->front = NULL;
        this->sizeOfQ = 0;
    }

    ~queue()
    {
        this->front = NULL;
    }

    int enqueue(void *data);
    int dequeue(void **data);
    int sizeOfQueue();
    bool isEmptyQueue();
    int printQ();
    int peek(void *&data); //view the next element which is going to be dequeued
};