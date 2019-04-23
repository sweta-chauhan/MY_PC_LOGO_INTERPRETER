#include<iostream>
#include<vector>
#include "cmd.h"

using namespace std;

vector <command> cmd_ls;



cmd_error insert_cmd(cmd_type cmd,float scale_fact,cmd_param cmd_p)
{
  command c1;
  if(cmd_p==NO_PARAM_CMD || cmd_p==PARAM_CMD)
    {
      c1.cmd=cmd;
      c1.cp=cmd_p;
      c1.scale_fact=scale_fact;
      cmd_ls.push_back(c1);
      return cmd_success;
    }
  return cmd_failure;
}
/*
int main()
{
  insert_cmd(FD,200,PARAM_CMD);
  insert_cmd(RT,90,PARAM_CMD);
  insert_cmd(BK,200,PARAM_CMD);
  insert_cmd(LT,90,PARAM_CMD);
  insert_cmd(BK,200,PARAM_CMD);
  insert_cmd(RT,90,PARAM_CMD);
  insert_cmd(FD,200,PARAM_CMD);
  //insert(BK,200,PARAM_CMD);
  for (int i=0;i<cmd_ls.size();i++)
    {
      cout<<cmd_ls[i].cmd<<endl;
    }
}
*/
/*
cmd traverse_cmd_list()
{
  vector<int>::iterator start=cmd_list.begin();
  ovector<int>::iterator end=cmd_list.end();
  auto it = next(ptr,1);
  return 
}
*/
