#include<iostream>
#include<cmath>

using namespace std;

class Shape{
    private:
    double length, width, height;

    public:
    Shape(): length(0), width(0), height(0) {}

    void square(double side){
        length=side;
    }
    void cube(double side){
        length = side;
    }
    void rectangle(double len, double wid){
        length = len;
        width= wid;
    }
    void cuboid (double len, double wid, double hei){
        length = len;
        width = wid;
        height = hei;
    }
    double ar_sq(){
        return length*length;
    }
    double ar_cub(){
        return 6* (length*length);
    }
    double ar_rect(){
        return length*width;
    }
    double ar_cbod(){
        return 2*(length*width + width*height + height*length);
    }
};

int main(){
    Shape shape;
    int choice;
    double length, width, height;

    do{
        cout<<"Enter your choice: "<<"\n";
        cout<<"A. Square\n";
        cout<<"B. Cube\n";
        cout<<"C. Rectangle\n";
        cout<<"D. Cubiod\n";
        cout<<"E. Exit\n";
        cin>>choice;

        switch(choice){
            case 1:
                    cout<<"Enter the length of Square";
                    cin>>length;
                    shape.square(length);
                    cout<<"Area of the square: "<< shape.ar_sq()<<"\n";
                    break;

            case 2: 
                    cout<<"Enter the length of the cube: ";
                    cin>>length;
                    shape.cube(length);
                    cout<<"Area of the cube: "<<shape.ar_cub()<<"\n";
                    break;

            case 3:
                cout << "Enter length and width of rectangle: ";
                cin >> length >> width;
                shape.rectangle(length, width);
                cout << "Area of Rectangle: " << shape.ar_rect() << "\n";
                break;

            case 4:
                cout << "Enter length, width, and height of cuboid: ";
                cin >> length >> width >> height;
                shape.cuboid(length, width, height);
                cout << "Area of Cuboid: " << shape.ar_cbod() << "\n";
                break;

            case 5:
                    cout<<"Exited the program!"<<"\n";

            default:
                    cout<<"Invalid!";
        }
    }while (choice !=5);
    return 0;
}