//Menu-driven program for implementation of Hash table using linear probing
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable{
    private:

    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    public:

    HashTable(){
        for(int i=0; i<TABLE_SIZE; i++){
            isOccupied[i]=false;
            table[i]=EMPTY;
        }
    };

    int hashFunction(int);
    int insert(int);
    int remove(int);
    int search(int);
    int display();

};

int main(){
    HashTable Hash;
    int choice, key, result;

    while(1){
        cout<<"Here are the options for the menu:\n";
        cout<<"1. Insert\n2. Remove\n3. Search\n4. Display\n5. Exit\n";
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
            cout<<"--------------------Display--------------------\n";
            Hash.display();
            break;

            case 5:
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
    return key%TABLE_SIZE;
}
//Function to insert a key in the hash table
int HashTable::insert(int key){
    int index = hashFunction(key);
    int startIndex = index;

    while(table[index] != key && table[index] != EMPTY && table[index] != DELETED){
        index = (index + 1)%TABLE_SIZE;
        if(index == startIndex){
            cout<<"Table is full, cannot insert more keys\n";
            return 1;
        }
    }
    if(table[index] == key){
        cout<<"Key is already present\n";
        return 1;
    }
    table[index] = key;
    cout<<"Inserted "<<key<<" at index "<<index<<"\n";
    isOccupied[index] = true;
    return 1;
}
//Function to search a key in the has table
int HashTable::search(int key){
    int index = hashFunction(key);
    int startIndex = index;

    while(table[index] != EMPTY){
        if(table[index] == key){
            return index;
        }
        index = (index + 1)%TABLE_SIZE;
        if(index == startIndex){
            break;
        }
    }
    return -1;
}
//Function to remove a key from the hash table
int HashTable::remove(int key){
    int result = search(key);
    if(result==-1){
        cout<<"Cannot delete, key not found\n";
    }
    else{
        cout<<"Deleting "<<table[result]<<"\n";
        table[result] = DELETED;
        isOccupied[result] = false;
    }
    return 1;
}
//Fcuntion to display the keys in the hash table
int HashTable::display(){
    for(int i=0; i<TABLE_SIZE; i++){
        if(table[i] == EMPTY){
            cout << i << ": EMPTY\n";
        }
        else if(table[i] == DELETED){
            cout << i << ": DELETED\n";
        }
        else{
            cout << i << ": " << table[i] << "\n";
        }
    }
    return 1;
}
