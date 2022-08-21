#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "random_toolkit.hpp"

int main()
{
   std::ifstream ifs ( "wof.1-20.txt" );

   if ( !ifs )
   {
      return (std::cerr << "Cannot open file\n"), 1;
   }

   std::string temp;
   std::vector<std::string> phrases;

   // skip the first two lines.
   std::getline(ifs,temp);
   std::getline(ifs, temp);

   while ( std::getline(ifs, temp) )
   {
      phrases.emplace_back(temp);
   }

   rtk::srand();

   int ran_phrase { rtk::rand(0, phrases.size() - 1) };

   std::cout << phrases[ran_phrase] << '\n';
}