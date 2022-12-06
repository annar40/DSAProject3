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
        HashNode<K, V> *temp3 = new HashNode<K, V>(100000000, "");
        HashNode<K, V> *temp4 = new HashNode<K, V>(100000000, "");

        V prev1;
        V prev2;
        V post1;
        V post2;

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
                    // cout << temp1->key << endl;
                    cout << "value in arr " << arr[count]->key << endl;

                    if (arr[count]->key >= temp1->key && arr[count]->key < userInputData)
                    {

                        if (temp2->key <= temp1->key)
                        {
                            temp2 = temp1;
                        }
                        temp1 = arr[count];
                    }
                    else if (arr[count]->key < temp3->key && arr[count]->key > userInputData)
                    {

                        temp3 = arr[count];
                    }
                    if(arr[count]->key > temp3->key &&  arr[count]->key < temp4->key)
                    {
                        temp4 = arr[count];
                    }
                
                }
                else
                {
                    test = false;
                }
            }

            count++;
        }
        prev1 = temp1->value;
        prev2 = temp2->value;
        post1 = temp3->value;
        post2 = temp4->value;

        ans.push_back(prev2);
        ans.push_back(prev1);
        // ans.push_back(userInputData);
        ans.push_back(post1);
        ans.push_back(post2);
        
        // cout << "temp1 value: " << prev1<< endl;
        // cout << "temp2 value: " << prev2 << endl;
        // cout << "temp3 value: " << temp3->value << endl;
        // cout << "temp4 value: " << temp4->value << endl;
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

};
// int main()
// {

//     HashMap<int, string> *h = new HashMap<int, string>(20);
//     // h->insertNode(1, "caleb");
//     // h->insertNode(5, "chandler");
//     // h->insertNode(3, "anna");
//     // h->insertNode(4, "brandon");
//     // h->insertNode(2, "ashley");
//     // h->insertNode(8, "madeline");
//     // h->insertNode(13, "bob");
//     // h->insertNode(7, "ryan");
//     // h->insertNode(9, "catherine");
//     // h->insertNode(12, "korynn");
//     h->insertNode(11, "abbey");
//     h->insertNode(17, "jake");
//     h->insertNode(19, "class");
//     h->insertNode(19, "math");
//     h->insertNode(20, "soccer");
//     h->insertNode(21, "mom");
//     h->insertNode(6, "dad");
//     h->insertNode(14, "hero");
//     h->insertNode(39, "blah");
//     h->insertNode(40, "green");
//     h->insertNode(67, "sea");
//     h->insertNode(98, "snake");

//     // h->display();

//     vector<string> answer = h->get(20);
//     for (int i=0; i<answer.size(); i++){
//         if(i == 3)
//         {
//             cout << "Your Value: ";
//         }
//         cout<<answer[i] << " ";
//     }

//     return 0;
// }