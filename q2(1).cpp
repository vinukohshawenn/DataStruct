//Menu-driven program for implementation of Hash table using quadratic probing
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable{
    private:

    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    public:

    HashTable(){
        for(int i=0; i<TABLE_SIZE; i++){
            isOccupied[i]=false;
            table[i]=-1;
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
    int i = 0;

    while(i < TABLE_SIZE){
        int newIndex = (index + i*i) % TABLE_SIZE;
        if(table[newIndex] == key){
            cout<<"Key is already present\n";
            return 1;
        }
        if(table[newIndex] == -1 || table[newIndex] == -2){
            table[newIndex] = key;
            cout<<"Inserted "<<key<<" at index "<<newIndex<<"\n";
            isOccupied[newIndex] = true;
            return 1;
        }
        i++;
    }
    cout<<"Table is full, cannot insert more keys\n";
    return 1;
}
//Function to search a key in the has table
int HashTable::search(int key){
    int index = hashFunction(key);
    int i = 0;

    while(i < TABLE_SIZE){
        int newIndex = (index + i*i) % TABLE_SIZE;
        if(table[newIndex] == -1){
            return -1;
        }
        if(table[newIndex] == key){
            return newIndex;
        }
        i++;
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
        table[result]=-2;
        isOccupied[result]=false;
    }
    return 1;
}
//Fcuntion to display the keys in the hash table
int HashTable::display(){
    for(int i=0; i<TABLE_SIZE; i++){
        cout<<table[i]<<" ";
    }
    cout<<"\n";
    return 1;
}
