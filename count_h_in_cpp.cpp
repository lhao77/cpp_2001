#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <fstream>

#define MAX_LINE_LEN 256
//#define COMMENT_0	"//"
//#define COMMENT_1	"/*"

const char comment_0[10] = "//";
const char comment_1[10] = "/*";
const char define[10] ="#define";

//std::map<std::string,std::set<std::string> > g_map_file;	//the file --> include h file.
std::map<std::string,std::set<std::string> > g_map_cpp_h;	//the cpp file --> include h file.
std::map<std::string,std::set<std::string> > g_map_h_cpp;	//the h file --> cpp file.
bool is_comment_line_for_astart = false;	// do with /*

std::string& trim(std::string &s) 
{
    if (s.empty()) 
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of("/ ") + 1);
    return s;
}

bool is_include_line(std::string tmp)
{	
	std::string str(tmp);
	trim(str);
	
	std::size_t found;
	if(!(found=str.find(define)))
		return true;
	return false;
}

void dowith_line(std::string &str)
{
	//if(is_comment_line_for_astart)
	trim(str);
	
	std::size_t found;
	if( !(found=str.find(comment_0)) )
	{
		str = "";
		return;
	}
	
	if( !(found=str.find(define)) )
	{
		str = "";
		return;
	}
	else
	{
		str = str.substr(found+strlen(define));
		found = str.find_first_of("<\"");
		str = str.substr(found+1);
		found = str.find_first_of("<\""); 
		str = str.substr(0,found);
		trim(str);
		
		if(found=str.find(".h"))
		{
			return;
		}
		else
		{
			str = "";
			return;
		}
	}
}

void calc_hset(std::map<std::string,std::set<std::string> >& map_h, std::string str_file)
{
	std::fstream fs(str_file.c_str(),std::ios::in);
	
	while(!fs.eof())
	{
		char tmp[MAX_LINE_LEN];
		fs.getline(tmp,MAX_LINE_LEN);
		
		std::string str(tmp);
		dowith_line(str);
		
		if(str.length())
		{
	 	    std::map< std::string,std::set<std::string> >::iterator iter;
		    if( (iter = map_h.find(str_file)) != map_h.end() )
		    {
				std::set<std::string> set_str;
				set_str.insert(str);
				map_h.insert( std::pair<std::string,std::set<std::string> >(str_file,set_str) );
		    }
		    else
		    {
				iter->second.insert(str);
			}
		}
	}
}


void calc_hset(const char *filename)
{
    std::string str_file(filename);
	
 	//test the file is h file or c file or other file.....
	if( str_file.find(".h") != std::string::npos )
	{
		calc_hset(g_map_h_cpp,str_file);
		g_map_h_cpp.insert( std::pair<std::string,std::set<std::string> >(str_file,std::set<std::string>() ) );
	}
	else if( str_file.find(".c") != std::string::npos )
	{
 		calc_hset(g_map_cpp_h,str_file);
		g_map_cpp_h.insert( std::pair<std::string,std::set<std::string> >(str_file,std::set<std::string>() ) ); 
    }
    else
    {
	 	assert("error file");
	} 
}

int main()
{
	
}
