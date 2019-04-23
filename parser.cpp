#include<iostream>
#include<fstream>
#include <stdexcept>
#include<vector>
#include <bits/stdc++.h> 
#include<algorithm>
#include<string>

#include "cmd.h"
#include "error.h"
#include "parser.h"

bool error = false;
bool block = false;

void parse_file(string filename)
{
  ifstream file(filename);
  if(file.is_open())
    {
      string line;
      int line_no;
      //cout<<line;
      line_no= 0;
      while(getline(file,line))
	{
	  line.erase(remove(line.begin(),line.end(),'\n'),line.end());
	  line_no++;
	  vector <string> tokens;
	  stringstream check1(line); 
	  string intermediate;
	  while(getline(check1, intermediate, ' ')) 
	    { 
	      tokens.push_back(intermediate); 
	    }
	  int i=0;
	  int col_no;
	  col_no = 0;
	  if(tokens.size()>=2)
	    {
	      while(i < tokens.size() && tokens.size()>=2) 
		{
		  //cout<<tokens[i]<<endl;
		  //cout<<"helo";
		  int val;
		  if(tokens[i]=="fd" || tokens[i]=="FD")
		    {
		      
		      try{
			val=stof(tokens[i+1]);
			insert_cmd(FD,val,PARAM_CMD); 
		      }
		      catch(invalid_argument){
			error=true;
			insert_er(line_no,col_no,4);
		      }
		      i=i+1;
		    }
		  if(tokens[i]=="bk" || tokens[i]=="BK")
		    {
		      try{
			val=stof(tokens[i+1]);
			insert_cmd(BK,val,PARAM_CMD); 
		      }
		      catch(invalid_argument){
			error=true;
		
			insert_er(line_no,col_no,4);
		      }
		      i=i+1;
		    }
		  if(tokens[i]=="rt" ||tokens[i]=="RT")
		    {
		      try{
			val=stof(tokens[i+1]);
			insert_cmd(RT,val,PARAM_CMD); 
		      }
		      catch(invalid_argument){
			error=true;
			
			insert_er(line_no,col_no,4);
		      }
		      i=i+1;
		    }
		  if(tokens[i]=="lt" || tokens[i]=="LT")
		    {
		      //cout<<"helo"<<endl;
		      try{
			val=stof(tokens[i+1]);
			insert_cmd(LT,val,PARAM_CMD); 
		      }
		      catch(invalid_argument){
			error=true;
			
			insert_er(line_no,col_no,4);
		      }
		      i=i+1;
		    }
		  if(tokens[i]=="repeat" || tokens[i]=="REPEAT")
		    {
		      //cout<<"helo"<<endl;
		     
		      try{
			val=stof(tokens[i+1]);
			insert_cmd(REPEAT,val,PARAM_CMD); 
		      }
		      catch(invalid_argument){
			error=true;
			
			insert_er(line_no,col_no,4);
		      }
		      i=i+1;
		    }
		  if(tokens[i]=="[" && block!=true)
		    {
		      //cout<<"helo"<<endl;
		      block = true;
		      insert_cmd(S,0,NO_PARAM_CMD);
		      
		    }
		  if(tokens[i]=="]")
		    {
		      if(block)
			{
			  insert_cmd(E,0,NO_PARAM_CMD);
			  i=i+1;
			}
		      else
			{
			  insert_er(line_no,col_no,5);
			  i++;
			}
		    }
		  else
		    i++;
		}
	    }
	  else{
	   
	    if(tokens[i]=="FD"||tokens[i]=="fd"||tokens[i]=="bk"||tokens[i]=="BK"||tokens[i]=="rt"||tokens[i]=="RT"||tokens[i]=="LT"||tokens[i]=="lt"||tokens[i]=="REPEAT"||tokens[i]=="repeat")
	      {
		
		error=true;
		insert_er(line_no,col_no,2);
	      }
	    else
	      {
		if(tokens[i]=="PD"||tokens[i]=="pd")
		  {
		    
		    insert_cmd(PD,0,NO_PARAM_CMD);
		  }
		else
		  {
		    if(tokens[i]=="PU"||tokens[i]=="pu")
		      {
			
			insert_cmd(PU,0,NO_PARAM_CMD);
		      }
		    else
		      {
			//cout<<"yaha par";
			error=true;
			insert_er(line_no,col_no,1);
		      }
		  }
	      }
	    i++;
	  }
	      
	  //err_description.push_back(line.c_str())
	  tokens.clear();
	  
	}
      file.close();
    }
}
/*
int main()
{
  parse_file("flower.rbt");
  for(int i =0;i<cmd_ls.size();i++)
    {
      cout<<cmd_ls[i].cmd<<" "<<cmd_ls[i].scale_fact<<" "<<endl;
    }
  load_error_file("error_file");
  traverse("oct.rbt");
}
*/

