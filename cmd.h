#ifndef __cmd_h_
#define __cmd_h_
#include<vector>
using namespace std;

typedef enum {cmd_failure=-1,cmd_success}cmd_error;
typedef enum {FD=0,BK,RT,LT,PD,PU,REPEAT,E,S}cmd_type;
typedef enum {NO_PARAM_CMD,PARAM_CMD}cmd_param;
struct command
{
  cmd_type cmd;
  cmd_param cp;
  int scale_fact;
};
extern vector <command> cmd_ls;

cmd_error insert_cmd(cmd_type c,float s,cmd_param cp);

//cmd traverse_cmd_list();

#endif
