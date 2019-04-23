#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "error.h"

using namespace std;

vector <errors> err;
vector <string> err_description;

void insert_er(int line,int col,int error_no)
{
  errors er;
  er.line_no = line;
  er.col_no  = col;
  er.error_no= error_no;
  err.push_back(er);
}

void load_error_file(string filename)
{
  ifstream file(filename);
  if(file.is_open())
    {
      string line;
      while(getline(file,line))
	{
	  err_description.push_back(line.c_str());
	}
      file.close();
    }
}

void traverse(string filename)
{
  for(int i=0;i<err.size();i++)
    {
      cout<<filename<<" : line no :"<<err[i].line_no<<": "<<err[i].col_no<<": "<<err_description[err[i].error_no]<<endl;
    }
}
/*
int main()
{
  load_error_file("error_file");
  errors e1,e2,e3;
  e1.line_no=1;
  e1.col_no=1;
  e1.error_no=1;
  e2.line_no=2;
  e2.col_no=4;
  e2.error_no=1;
  e3.line_no=3;
  e3.col_no=5;
  e3.error_no=2;
  err.push_back(e1);
  err.push_back(e2);
  err.push_back(e3);
  traverse("hello");
}
*/
