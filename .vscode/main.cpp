#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
sphere area = 4πr^2, volume = 4/3 πr^3
cuboid area = 2 (length x width + width x height + length x height)
cuboid volume = length x width x height
pyramid area = area of base + 1/2 x perimeter of base x slant height
pyramid volume = 1/3 x area of base x height
cylinder area = 2πr^2 + 2πrh
cylinder volume = πr^2h
*/

struct Result{
    double area;
    double volume;
};

Result sphere(double radius, double pi = 3.14159){
    Result result;
    result.area = 4 * pi * pow(radius, 2);
    result.volume = (4.0 / 3.0) * pi * pow(radius, 3);
    return result;
}

Result cuboid(double length, double width, double height){
    Result result;
    result.area = 2 * (length * width + width * height + length * height);
    result.volume = length * width * height;
    return result;
}

Result pyramid(double length, double width, double slant, double height){
    Result result;
    double baseArea = length * width;
    double perimeter = 2 * (length + width);
    result.area = baseArea + (1.0 / 2.0) * perimeter * slant;
    result.volume = (1.0 / 3.0) * baseArea * height;
    return result;
}

Result cylinder(double radius, double height, double pi = 3.14159){
    Result result;
    result.area = 2 * pi * pow(radius, 2) + 2 * pi * radius * height;
    result.volume = pi * pow(radius, 2) * height;
    return result;
}

void output(double area, double volume){
    cout << "The area is: " << fixed << setprecision(4) << area << "cm^2" << endl;
    cout << "The volume is: " << fixed << setprecision(4) <<volume << "cm^3" << endl;
}

int main(){
    int choice;
    const double pi = 3.14159;
    double length, width, height, radius, slant;

    do{
        cout << "----- SHAPE VOLUME & AREA CALCULATOR PROGRAM -----" << endl;
        cout << "Pls enter a choice." << endl;
        cout << "1. Sphere" << endl;
        cout << "2. Cuboid" << endl;
        cout << "3. Pyramid" << endl;
        cout << "4. Cylinder" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "----- SPHERE CALCULATOR-----" << endl;
                cout << "Enter radius (in cm): ";
                cin >> radius;

                Result result = sphere(radius);
                output(result.area, result.volume);
                break;

                if(radius <= 0){
                    cout << "ERROR: Must be a positive number." << endl;
                    break;
                }
            }

            case 2:{
                cout << "----- CUBOID CALCULATOR -----" << endl;
                cout << "Enter length (in cm): ";
                cin >> length;

                cout << "Enter width (in cm): ";
                cin >> width;

                cout << "Enter height (in cm): ";
                cin >> height;

                Result result = cuboid(length, width, height);
                output(result.area, result.volume);
                break;

                if(length <= 0 || width <= 0 || height <= 0){
                    cout << "ERROR: Must be a positive number." << endl;
                    break;
                }
            }

            case 3:{
                cout << "----- PYRAMID CALCULATOR -----" << endl;
                cout << "Enter length (in cm): ";
                cin >> length;

                cout << "Enter width (in cm): ";
                cin >> width;

                cout << "Enter slant height (in cm): ";
                cin >> slant;

                cout << "Enter height (in cm): ";
                cin >> height;

                Result result = pyramid(length, width, slant, height);
                output(result.area, result.volume);
                break;

                if(length <= 0 || width <= 0 || slant <= 0 || height <= 0){
                    cout << "ERROR: Must be a positive number." << endl;
                    break;
                }
            }

            case 4:{
                cout << "----- CYLINDER CALCULATOR -----" << endl;
                cout << "Enter radius (in cm): ";
                cin >> radius;

                cout << "Enter height (in cm):";
                cin >> height;

                Result result = cylinder(radius, height);
                output(result.area, result.volume);
                break;

                if(radius <= 0 || height <= 0){
                    cout << "ERROR: Must be a positive number." << endl;
                    break;
                }
            }

            case 5:{
                cout << "Goodbye!" << endl;
                return 0;
            }

            default:{
                cout << "ERROR: Please enter only number 1 to 5." << endl;
            }
        }
    }while(choice != 5);

    return 0;
}