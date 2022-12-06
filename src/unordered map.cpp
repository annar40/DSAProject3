#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>
using namespace std;

template <typename K, typename V>

class HashNode
{
public:
    V value;
    K key;

    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

template <typename K, typename V>

class HashMap
{

    HashNode<K, V> **arr;
    int capacity;

    int size;

public:
    HashMap(int cap)
    {

        capacity = cap;
        size = 0;
        arr = new HashNode<K, V> *[capacity];

        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;
    }

    int hashCode(K key)
    {
        return key % capacity;
    }

    // Function to add key value pair
    void insertNode(K key, V value)
    {
        HashNode<K, V> *temp = new HashNode<K, V>(key, value);

        int hashIndex = hashCode(key);

        float loadFactor = (float)size / (float)capacity;
        float maxLoad = 0.75f;

        if (loadFactor >= maxLoad)
        {
            rehash();
            return;
        }

        // find next free space
        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        // if new node to be inserted
        // increase the current size
        if (arr[hashIndex] == NULL)
            size++;
        arr[hashIndex] = temp;
    }

    void rehash()
    {

        // size = 0;
        capacity = capacity * 2;
        HashMap<int, string> *temp = new HashMap<int, string>(capacity);

        for (int i = 0; i < capacity / 2; i++)
        {
            if (arr[i] != NULL && arr[i]->key != -1)
            {
                temp->insertNode(arr[i]->key, arr[i]->value);
            }
        }
        arr = temp->arr;
    }

    vector<V> get(int userInputData)
    {
        HashNode<K, V> *temp1 = new HashNode<K, V>(0, "");
        HashNode<K, V> *temp2 = new HashNode<K, V>(0, "");
        V prev1;
        V prev2;
        vector<V> ans;
        bool test = true;

        int count = 0;
        int counter = 0;

        while (test)
        {
            if (arr[count] != NULL)
            {
                if (counter < size)
                {
                    counter++;
                    cout << temp1->key << endl;
                    cout << "value in arr " << arr[count]->key << endl;
                    // if((int)(temp1->key) < userInputData)

                    if ( arr[count]->key > temp1->key && arr[count]->key < userInputData)
                    {
                        temp1 = arr[count];
                    }
                }
                else
                {
                    test = false;
                }
                // cout << counter << endl;
            }

            count++;
        }
        ans.push_back(temp1->value);
        cout << "temp1 value: " << temp1->value << endl;
        return ans;
    }

    // Return current size
    int sizeofMap()
    {
        return size;
    }

    // Return true if size is 0
    bool isEmpty()
    {
        return size == 0;
    }

    // Function to display the stored key value pairs
    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key
                     << "  value = "
                     << arr[i]->value << endl;
        }
    }
};
int main()
{

    HashMap<int, string> *h = new HashMap<int, string>(20);
    h->insertNode(1, "caleb");
    h->insertNode(5, "chandler");
    h->insertNode(3, "anna");
    h->insertNode(4, "brandon");
    h->insertNode(2, "ashley");
    h->insertNode(8, "madeline");
    h->insertNode(13, "bob");
    h->insertNode(7, "ryan");
    h->insertNode(9, "catherine");
    h->insertNode(12, "korynn");
    h->insertNode(11, "abbey");
    h->insertNode(17, "jake");
    h->insertNode(18, "class");
    h->insertNode(19, "math");
    h->insertNode(20, "soccer");
    h->insertNode(21, "mom");
    h->insertNode(6, "dad");
    h->insertNode(14, "hero");
    h->insertNode(35, "jake");
    h->insertNode(39, "blah");
    h->insertNode(40, "green");
    h->insertNode(67, "sea");
    h->insertNode(98, "snake");

    h->display();

    vector<string> answer = h->get(20);
    // for (int i=0; i<answer.size(); i++){
    //     cout<<answer[i]<< endl;
    // }

    return 0;
}