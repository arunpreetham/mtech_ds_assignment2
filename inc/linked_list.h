class queueNode
{
    private:
    void *data;
    queueNode *next, *prev;

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
};

class queue
{
    private:
    queueNode *front;

    public:
    queue()
    {
        this->front = NULL;
    }

    ~queue()
    {
        this->front = NULL;
    }

    public:
    int enqueue(void *data);
    int dequeue(void **data);
    int sizeOfQueue();
    int isEmptyQueue();
};