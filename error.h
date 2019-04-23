#ifndef __error_h_
#define __error_h_

#include<string.h>
using namespace std;

typedef struct error
{
  int line_no;
  int col_no;
  int error_no;
}errors;


void insert_er(int,int,int);
void load_error_file(string filename);
void traverse(string filename);

extern vector <errors> err;
extern vector <string> err_description;

#endif
