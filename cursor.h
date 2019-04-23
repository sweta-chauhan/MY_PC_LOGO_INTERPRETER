#ifndef __cursor_h_
#define __cursor_h_

#define DEFAULT_X_COORD 750
#define DEFAULT_Y_COORD 450
#define DEFAULT_DIR 0

typedef enum {c_failure,c_success}c_error;

struct cursor
{
  float x_coord;
  float y_coord;
  float dir;
};

cursor* init_cursor();
c_error update_cursor(cursor **,float,float,float);
c_error free_cursor(cursor *);
c_error clear(cursor **);
float get_x(cursor *c);
float get_y(cursor *c);
void print_cursor(cursor *c);
#endif
