#include <iostream>
using namespace std;

int main(){
    cout << "Welcome to the Simple Calculator Program" << "\n";
    cout << "You have the choice to do addition, subtraction, multiplication and division." << "\n";
    cout << "Press 'q' or 'Q' as the operator to quit." << "\n";

    char op;
    double n1, n2;

    cout << "Enter operator(+, - , *, / ):" << "\n";
    cin >> op;

    while (op != 'q' && op != 'Q'){
        cout << "Enter two numbers: " << "\n";
        cin >> n1 >> n2;
 

        if(op == '+'){
            cout << n1 << " + " << n2 << " = " << n1 + n2 << "\n";
        } else if (op == '-'){
            cout << n1 << " - " << n2 << " = " << n1 - n2 << "\n";
        } else if (op == '*'){
            cout << n1 << " * " << n2 << " = " << n1 * n2 << "\n";
        } else if (op == '/'){
            if (n2 != 0){
                cout << n1 << " / " << n2 << " = " << n1 / n2 << "\n";
            } else {
                cout << "Error! Division by zero is not allowed" << "\n"; 
            }
        } else {
            cout << "Error! The operator is invalid. Please use a correct operator." << "\n";
        }

        cout << "Enter operator (+, -, *, /) or q to quit: " << "\n";
        cin >> op;
    }
    
    cout << "Exiting the calculator." << "\n";
    return 0;
}
