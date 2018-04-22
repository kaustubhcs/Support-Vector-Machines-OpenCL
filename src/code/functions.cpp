#include "functions.h"
#include "debugger.h"
#include <string>
using namespace std;

int find_number_of_lines (const std::string& fdata) {
int number_of_lines=0;
string new_line = "\n";

for (uint i=0;i<fdata.length();i++) {
        if (fdata[i] == new_line[0]) {
        	number_of_lines++;
        }
}

return number_of_lines;
}







void fill_mr_struct(const std::string& fdata,int line_number, MemoryRegion *mr) {
int start_of_line = pos_of_line(fdata,line_number);

int pos_1_dl = find_delimiter(fdata,pos_of_line(fdata,line_number));
int pos_2_dl = find_delimiter(fdata,pos_of_line(fdata,line_number)+pos_1_dl+1);

string saddr = fdata.substr(pos_of_line(fdata,line_number),pos_1_dl);
string eaddr = fdata.substr(pos_of_line(fdata,line_number)+pos_1_dl+1,pos_2_dl);

// Permission Block
string pblock = fdata.substr(pos_of_line(fdata,line_number)+pos_1_dl+pos_2_dl+2,4);

unsigned long long int s_addr = string2long(saddr);
unsigned long long int e_addr = string2long(eaddr);

void *ptr_saddr;
void *ptr_eaddr;
ptr_saddr = (void *) s_addr;
ptr_eaddr = (void *) e_addr;

//cout << "Start Address: " << ptr_saddr <<  " End Address: " << ptr_eaddr << endl;
mr[line_number].startAddr = ptr_saddr;
mr[line_number].endAddr = ptr_eaddr;
long diff;
diff = e_addr - s_addr;
string r = "r";
string w = "w";
string x = "x";

if (pblock[0] == r[0]) {
	mr[line_number].isReadable = 1;
} else {
	mr[line_number].isReadable = 0;
}

if (pblock[1] == w[0]) {
	mr[line_number].isWriteable = 1;
} else {
	mr[line_number].isWriteable = 0;
}

if (pblock[2] == x[0]) {
	mr[line_number].isExecutable = 1;
} else {
	mr[line_number].isExecutable = 0;
}

mr[line_number].blockSize = diff;

}



unsigned long long int string2long (const std::string& in) {

unsigned long long int value=0;
int length = in.length();
int n1;
string temp;
int loop_counter=0;
for (int i=length-1;i>=0;i--) {
	temp = in[i];
//	n1 = stoi(temp);


	if (temp == "0") {
	value += 0*pow(16,loop_counter);
	} else if (temp == "1") {
	value += 1*pow(16,loop_counter);
        } else if (temp == "2") {
	value += 2*pow(16,loop_counter);
        } else if (temp == "3") {
	value += 3*pow(16,loop_counter);
        } else if (temp == "4") {
	value += 4*pow(16,loop_counter);
        } else if (temp == "5") {
        value += 5*pow(16,loop_counter);
        } else if (temp == "6") {
        value += 6*pow(16,loop_counter);
        } else if (temp == "7") {
        value += 7*pow(16,loop_counter);
        } else if (temp == "8") {
        value += 8*pow(16,loop_counter);
        } else if (temp == "9") {
        value += 9*pow(16,loop_counter);
        } else if (temp == "a") {
        value += 10*pow(16,loop_counter);
        } else if (temp == "b") {
        value += 11*pow(16,loop_counter);
        } else if (temp == "c") {
        value += 12*pow(16,loop_counter);
        } else if (temp == "d") {
        value += 13*pow(16,loop_counter);
        } else if (temp == "e") {
        value += 14*pow(16,loop_counter);
        } else if (temp == "f") {
        value += 15*pow(16,loop_counter);
	}
loop_counter++;
}
return value;
}



int pos_of_line (const std::string& fdata, int line_number) {
//int line_position=0;
int position=0;
string new_line = "\n";
while (line_number) {
	for (;position<fdata.length();position++) {
		if (fdata[position] == new_line[0]) {
			position++;
			break;
		}
	}
	line_number--;
}

return position;
}





int find_delimiter(const std::string& fdata, int start) {
string dash = "-";
string space = " ";
string new_line = "\n";
int counter = 0;
for (int i=start;i<fdata.length();i++) {
	if (fdata[i] == dash[0] || fdata[i] == space[0] || fdata[i] == new_line[0]) {
		return counter;
	}
	counter++;
}

return -1;
}








