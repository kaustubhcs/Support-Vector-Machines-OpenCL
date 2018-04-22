#include "debugger.h"
#include "functions.h"

using namespace std;

// Global Variables


//**********   MAIN FUNCTION   **********


int main (int argc, char *argv[] ) {

cout << "\n\n\n\n\n\n\n\n\n\n\e[1;32mProgram Start\e[0m\n";

// Accepting input from Console
    switch (argc) { // For getting input from console
        case 6:
            long input_5;
            input_5 = atol(argv[5]); //Fifth Input
            //num_threads = input_5;
        case 5:
            long input_4;
            input_4 = atol(argv[4]); //Fourth Input
            //in_parallel = input_4;
        case 4:
            long input_3;
            input_3 = atol(argv[3]); // Third Input
            //display_bit = input_3;
        case 3:
            long input_2;
            input_2 = atol(argv[2]); // Second Input
            debug = input_2;
        case 2:
            long input_1;
            input_1 = atol(argv[1]); // First input
            pid = input_1;
            break;
        case 1:
            // Keep this empty
            break;
        default:
            cout << "FATAL ERROR: Wrong Number of Inputs" << endl; // If incorrect number of inputs are used.
            return 1;
    }


cout << "\n\e[1;31mProgram End\e[0m\n\n\n";
return 0;
}







