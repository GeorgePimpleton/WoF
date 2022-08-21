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

   std::string phrase;

   int num_phrases { };

   while ( std::getline(ifs, phrase) ) { num_phrases++; }

   // reset the file to the beginning
   ifs.clear();
   ifs.seekg(0, std::ios::beg);

   rtk::srand();

   // skips the first two line, the phrase list starts at line 3
   int ran_phrase { rtk::rand(3, num_phrases) };

   for ( size_t itr { }; itr < ran_phrase; ++itr )
   {
      std::getline(ifs, phrase);
   }

   std::cout << phrase << '\n';
}