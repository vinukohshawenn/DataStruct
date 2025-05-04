//Menu-driven program for implementation of Hash table using separate chaining
#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable{
    private:

    list<int> table[TABLE_SIZE];

    public:

    HashTable(){};

    int hashFunction(int);
    int insert(int);
    int remove(int);
    int search(int);

};

int main(){
    HashTable Hash;
    int choice, key, result;

    while(1){
        cout<<"Here are the options for the menu:\n";
        cout<<"1. Insert\n2. Remove\n3. Search\n4. Exit\n";
        cout<<"Now enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter key to insert: ";
            cin>>key;
            Hash.insert(key);
            break;

            case 2:
            cout<<"Enter key to remove: ";
            cin>>key;
            Hash.remove(key);
            break;

            case 3:
            cout<<"Enter key to search: ";
            cin>>key;
            result = Hash.search(key);
            if(result==-1){
                cout<<"Key not found, search for a different key\n";
            }
            else{
                cout<<"Key found at position "<<result<<"\n";
            }
            break;

            case 4:
            cout<<"Exiting...";
            return -1;
            break;

            default:
            cout<<"Enter valid choice\n";
            break;
        }
    }
}
//Function to find the hash function
int HashTable::hashFunction(int key){
    return key % TABLE_SIZE;
}
//Function to insert a key in the hash table using separate chaining
int HashTable::insert(int key){
    int index = hashFunction(key);
    for(int val : table[index]){
        if(val == key){
            cout<<"Key is already present\n";
            return 1;
        }
    }
    table[index].push_back(key);
    cout<<"Inserted "<<key<<" at index "<<index<<"\n";
    return 1;
}
//Function to search a key in the hash table using separate chaining
int HashTable::search(int key){
    int index = hashFunction(key);
    for(int val : table[index]){
        if(val == key){
            return index;
        }
    }
    return -1;
}
//Function to remove a key from the hash table using separate chaining
int HashTable::remove(int key){
    int index = hashFunction(key);
    for(auto it = table[index].begin(); it != table[index].end(); ++it){
        if(*it == key){
            table[index].erase(it);
            cout<<"Deleting "<<key<<"\n";
            return 1;
        }
    }
    cout<<"Cannot delete, key not found\n";
    return 1;
}
