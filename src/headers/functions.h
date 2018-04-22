//
// Author: Kaustubh Shivdikar
//


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <array>
#include <cmath>
#include <fstream>

struct MemoryRegion
{
  void *startAddr;
  void *endAddr;
  int isReadable;
  int isWriteable;
  int isExecutable;
  unsigned long blockSize;
};

int find_number_of_lines (const std::string& );
void fill_mr_struct(const std::string&, int, MemoryRegion *);
int pos_of_line (const std::string&, int );
int find_delimiter(const std::string&, int);
unsigned long long int string2long (const std::string&);


#endif // FUNCTIONS_H
