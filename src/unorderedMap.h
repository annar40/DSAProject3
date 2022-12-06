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
        
        ans.push_back(post1);
        ans.push_back(post2);
        
        
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
    void print(int search){
        vector<string> answer = get(search);
        
    for (int i=0; i<answer.size(); i++){
        if(i == 3)
        {
            cout << "Your Value: "<< search<<" ";
        }
        cout<<answer[i] << " ";
    }
    }

};
