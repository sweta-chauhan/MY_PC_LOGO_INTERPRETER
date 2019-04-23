#include<iostream>
#include <stdio.h>	// printf
#include <stdlib.h>	// exit,malloc
#include <string.h>	// strerror
#include <errno.h>	// errno

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/gl_draw.H>
#include <vector>
#include <math.h>
#include <assert.h>

#include "cursor.h"
#include "error.h"
#include "cmd.h"
#include "parser.h"

bool can_draw = true;
bool fd(const float dist,cursor *c)
{
  float x,y;
  
  x = c->x_coord + dist*cos(M_PI*(c->dir)/180.0);
  y = c->y_coord + dist*sin(M_PI*(c->dir)/180.0);
  //cout<<cos(M_PI*(c->dir)/180.0);
  update_cursor(&c,x,y,c->dir);
  return true;
};

bool bk(const float dist,cursor *c)
{
  float x,y;
  
  x = c->x_coord - dist*cos(M_PI*(c->dir)/180.0);
  y = c->y_coord - dist*sin(M_PI*(c->dir)/180.0);
  //cout<<cos(M_PI*(c->dir)/180.0);
  update_cursor(&c,x,y,c->dir);
  return true;
}

bool lt(const double angle,cursor *c)
{
  update_cursor(&c,c->x_coord,c->y_coord,c->dir+angle);
  return true;
}

bool rt(const double angle,cursor *c)
{
	return lt(-angle,c);
}

bool repeat(int times)
{
  for(int i = 0;i<times;i++)
    {
      
    }
}
class InterPreter : Fl_Widget
{
public:
  cursor *current_position=init_cursor();
  void draw() {
        fl_color(FL_BLACK);
	int i;
	i = 0;
	while(i<cmd_ls.size())
	  {
	    
	    //print_cursor(current_position);
		if(cmd_ls[i].cmd==FD)
		  {
		    int x,y;
		    x = get_x(current_position);
		    y = get_y(current_position);
		    fd(cmd_ls[i].scale_fact,current_position);
		    if(can_draw)
		      {
			fl_line(x,y,get_x(current_position),get_y(current_position));
		      }
		    i++;
		  }
		else
		  {
		    if(cmd_ls[i].cmd==RT)
		    {
		    rt(cmd_ls[i].scale_fact,current_position);
		    i++;
		    }
		    else
		      {
		        if(cmd_ls[i].cmd==LT)
		        {
			  lt(cmd_ls[i].scale_fact,current_position);
			  i++;
			}
			else
			  { if(cmd_ls[i].cmd==BK)
			      {
				int x,y;
				x = get_x(current_position);
				y = get_y(current_position);
				bk(cmd_ls[i].scale_fact,current_position);
				if(can_draw)
				  {
				    fl_line(x,y,get_x(current_position),get_y(current_position));
				  }
				i++;
			      }
			    else
			      {
				if(cmd_ls[i].cmd==REPEAT)
				  {
				    int iter;
				    int first_cmd;
				    iter = cmd_ls[i].scale_fact;
				    i++;
				    first_cmd = i;
				    while(iter!=0)
				      {
					i=first_cmd;
					while(cmd_ls[i].cmd!=E)
					  {
					    if(cmd_ls[i].cmd==FD)
					      {
						int x,y;
						x = get_x(current_position);
						y = get_y(current_position);
						fd(cmd_ls[i].scale_fact,current_position);
						if(can_draw)
						  {
						    
						    fl_line(x,y,get_x(current_position),get_y(current_position));
						  }
						i++;
					      }
					    else
					      {if(cmd_ls[i].cmd==RT)
						  {
						    rt(cmd_ls[i].scale_fact,current_position);
						    i++;
						  }
						else
						  if(cmd_ls[i].cmd==LT)
						    {
						      lt(cmd_ls[i].scale_fact,current_position);
						      i++;
						    }
						  else
						    {
						      if(cmd_ls[i].cmd==BK)
							{
							  int x,y;
							  x = get_x(current_position);
							  y = get_y(current_position);
							  bk(cmd_ls[i].scale_fact,current_position);
							  if(can_draw)
							    {
							      fl_line(x,y,get_x(current_position),get_y(current_position));
							    }
							  i++;
							}
						      else
							i++;
						    }
					      }
					  }
					iter--;	
				      }
				  }
				else
				  {
				    if(cmd_ls[i].cmd==PD)
				      {
					can_draw=true;
					i++;
				      }
				    else
				      {
					if(cmd_ls[i].cmd==PU)
					  {
					    can_draw=false;
					    i++;
					  }
					else
					  i++;
				      }
				  }
			      }
			  }
		      }
		  }
	  }
  }
 InterPreter(int X, int Y, int W, int H, const char*L=0) : Fl_Widget(X,Y,W,H,L) {
    color(FL_BLACK);
    } 
};

using namespace std;


void process_interpreter(string filename)
{
  
}
int main(int argc,char* argv[])
{
  Fl::scheme("gtk+");
  Fl_Window *fl = new Fl_Window(1800,1000,"SWETA_INTERPRETER");
  InterPreter *dis= new InterPreter(920,920,900,870,"DISPLAY");
  try
    {
      assert(argc>=2);
      parse_file(argv[1]);
      if(error!=true)
	{
          fl->show(argc,argv);
	  return Fl::run();
	}
      load_error_file("error_file");
      traverse(argv[1]);
    }
  catch(const char *e)
    {
      cout<<e<<endl;
    }
  
}
