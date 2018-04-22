#include "debugger.h"
#include "functions.h"

using namespace std;

// Global Variables
int debug = 0;
long pid = -1;
//**********   MAIN FUNCTION   **********

// For reference only, actual declaration in Functions Header.
/*
struct MemoryRegion
{
  void *startAddr;
  void *endAddr;
  int isReadable;
  int isWriteable;
  int isExecutable;
};
*/

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

string cmd1= "cat /proc/";
string cmd2;
if (pid < 1) {
cmd2 = "self";
} else {
cmd2 = to_string(pid);
}
string cmd3= "/maps";

string cmd = cmd1 + cmd2 + cmd3;
const char *cc = cmd.c_str();
FILE* fptr = popen(cc, "r");
array<char, 128> buffer;
string fdata;
 while (fgets(buffer.data(), 128, fptr) != NULL) {
        fdata += buffer.data();
    }
    auto returnCode = pclose(fptr);
//CITE: https://stackoverflow.com/questions/44610978/popen-writes-output-of-command-executed-to-cout
//cout << fdata << endl << endl;
int number_of_lines;
number_of_lines = find_number_of_lines(fdata);

MemoryRegion* mr;

mr = new MemoryRegion [number_of_lines];

for (int i=0;i<number_of_lines;i++) {
	fill_mr_struct(fdata,i,mr);
}

long tread_only=0;
long tread_write=0;

for (int i=0;i<number_of_lines;i++) {
	if (mr[i].isReadable == 1 && mr[i].isWriteable == 0) {
		tread_only += mr[i].blockSize;
	}

	if (mr[i].isReadable == 1 && mr[i].isWriteable == 1) {
		tread_write += mr[i].blockSize;
	}


}

//CITE: http://www.cplusplus.com/doc/tutorial/files/
//

ofstream out_file;
out_file.open ("output.txt");
out_file << "Total Memory Regions: " << number_of_lines << endl;
for (int i=0; i< number_of_lines; i++) {
out_file << "Index: " << i << endl;
out_file << "startAddr: " << mr[i].startAddr << endl;
out_file << "endAddr: " << mr[i].endAddr << endl;
out_file << "isReadable: " << mr[i].isReadable << endl;
out_file << "isWriteable: " << mr[i].isWriteable << endl;
out_file << "isExecutable: " << mr[i].isExecutable << endl;
out_file << "blockSize: " << mr[i].blockSize << endl;

}

//out_file << fdata;
out_file.close();

cout << "Total Read Only Memory: " << tread_only << " Bytes"<< endl;
cout << "Total Read-Write Memory: " << tread_write  << " Bytes" << endl;

cout << "\n\e[1;31mProgram End\e[0m\n\n\n";
return 0;
}







