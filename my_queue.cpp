#include "my_queue.h"

using namespace std;

que::que(int size)
{
    arr = new people[size];
    capacity = size;
    
    rear = -1;
    count = 0;
}

que::que(const que& q)
{
    this->arr = new people[q.capacity];
    capacity = q.capacity;
    
    rear = -1;
    count = 0;
    
    for (int i = 0; i < q.count; i++)
    {
        enqueue(q.arr[i]);
    }
}

que::~que() {
    delete[] arr;
}

void que::dequeue() //удаления переднего элемента из очереди
{
    
    people* temp = new people[this->count - 1];

    for (int i = 1; i < this->count; i++)
    {
        temp[i - 1] = this->arr[i];
    }

    delete[] this->arr;
    this->arr = new people[this->capacity];
    this->count--;
    int j = this->count;

    for (int i = 0; i < j; i++)
    {
        this->arr[i] = temp[i];
    }
    
}


void que::enqueue(people item) //добавления элемента в queue
{

    if (isFull())
    {
        incapacity();
    }

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
    this->setpriority();
}

people que::peek() //возврат первого элемента queue
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[0];
}

int que::size() {
    return count;
}

bool que::isEmpty() {
    return (size() == 0);
}

bool que::isFull() {
    return (size() == capacity);
}

people& que::operator=(const people& p)
{
    
    return *this->arr;
}

que& que::operator=(const que& q)
{   
        if (this->arr != nullptr)
        {
            delete[] this->arr;
        }

        this->arr = new people[q.capacity];
        capacity = q.capacity;
        
        rear = -1;
        count = 0;

        for (int i = 0; i < q.count; i++)
        {
            enqueue(q.arr[i]);
        }
        return *this;   
}

que& que::operator()(int l, int r, const people& p)
{
    if (r > count || l < 0)
    {
        cout << "Неправильные границы\n";
        system("pause");
        return *this;
    }

    for (int i = l - 1; i != r; i++)
    {
        arr[i] = p;
    }
    return *this;
}

void que::incapacity(int newcapacity) //увеличение capacity
{
    if (newcapacity >= capacity) { capacity = newcapacity; return; }
    capacity += newcapacity;
    people* temp = new people[this->capacity];

    for (int i = 0; i < this->count; i++)
    {
        temp[i] = this->arr[i];
    }

    delete[] this->arr;
    arr = new people[capacity];

    for (int i = 0; i < this->count; i++)
    {
        this->arr[i] = temp[i];
    }

    delete[] temp;
}

void que::show()
{
    cout << "\tИмя\t\tПриоритет" << endl;
    for (int i = 0; i < this->count; i++)
    {
        cout << i + 1 << ".    " << arr[i].name << "\t\t  " << arr[i].priority << endl;
    }
    cout << endl;
}

void que::file(std::string filename)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::fstream file;
    file.open(filename, fstream::out | fstream::app);
    while (!file.is_open())
    {
        std::cout << "Введите путь к файлу ";
        char path[100];
        std::cin >> path;
        file.open(path, fstream::out | fstream::app);
    }

    for (int i = 0; i < this->count; i++)
    {
        file << i+1 << ".   \"" << this->arr[i].name << "\"\t\t" << arr[i].priority << endl;
    }

    file << std::endl;
    file.close();
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    return;
}

void que::getfromfile(std::string filename)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::fstream file(filename);

    while (!file.is_open())
    {
        std::cout << "Введите путь к файлу ";
        char path[100];
        std::cin >> path;
        file.open(path);
    }

    people p;
    stringstream ss;
    ss << file.rdbuf();
    file.close();
    
    for(int i = 5; i < ss.str().size(); i++)
    {
        if (ss.str()[i] == '\"')
        {
            int j = i + 1, x = 0;
            string tempname, temp;
            
                while (ss.str()[j] != '\"')
                {
                    tempname += ss.str()[j];
                    j++;
                }     
                j += 2;
                x = ss.str().find('\n', j);
                if (x != std::string::npos)
                {
                    temp = ss.str().substr(j, x);
                }
                else 
                {
                    temp = ss.str().substr(j, 1);
                }

                p.name = tempname;
                p.priority = stoi(temp);
                i = j + 2;
                this->enqueue(p);
        }
    }

    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    return;
}

void que::setpriority()
{
    people temp;
    for (int i = 0; i < this->count - 1; i++)
    {
        for (int j = 0; j < this->count - i - 1; j++)
        {
            if(this->arr[j].priority > this->arr[j + 1].priority)
            {
                temp = this->arr[j];
                this->arr[j] = this->arr[j + 1];
                this->arr[j + 1] = temp;
            }
        }
    }
}

