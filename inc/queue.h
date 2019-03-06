class queueNode
{
    private:
    void *data;

    public:
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
    int setData(void *data);
    int getData(void **data);
    int addNode();
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
    bool isEmptyQueue();
    int printQ();
};