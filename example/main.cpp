#include "https_server_basic.h"



std::string callback(std::string A){
  
 std::string out="test.json";
 return(out);};
  
  
int main(){
  
   std::function<std::string(std::string)> func=callback;
   start_http_server(func);
  
  
}
