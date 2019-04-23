#include "cursor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

cursor* init_cursor()
{
  cursor *c;
  (c) = (cursor*)malloc(sizeof(cursor)); 
  if((c)!=NULL)
    {
      (c)->x_coord = DEFAULT_X_COORD;
      (c)->y_coord = DEFAULT_Y_COORD;
      (c)->dir = DEFAULT_DIR;
    }
  return c;
}

c_error update_cursor(cursor **c,float x,float y,float dir)
{
  if(*c)
    {
      (*c)->x_coord = x;
      (*c)->y_coord = y;
      (*c)->dir = dir;
      return c_success;
    }
  return c_failure;
}

c_error free_sursor(cursor *c)
{
  if(c)
    {
      free(c);
      return c_success;
    }
  return c_failure;
}

c_error clear(cursor **c)
{
  if(*c)
    {
      (*c)->x_coord = DEFAULT_X_COORD;
      (*c)->y_coord = DEFAULT_Y_COORD;
      (*c)->dir = DEFAULT_DIR;
      return c_success;
    }
  return c_failure;
}

void print_cursor(cursor *c)
{
  cout<<"("<<c->x_coord<<", "<<c->y_coord<<", "<<c->dir<<")"<<endl;
}

float get_x(cursor *s)
{
  return s->x_coord;
}

float get_y(cursor *s)
{
  return s->y_coord;
}
/*
int main(void)
{
  cursor *c1 = NULL;
  if(init_cursor(&c1))
    {
      update_cursor(&c1,1,1);
      print_cursor(c1);
    }
  cout<<"Helo";
}
*/

