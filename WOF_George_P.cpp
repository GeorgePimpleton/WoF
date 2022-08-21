#include <fstream>
#include <iostream>
#include <string>

#include "random_toolkit.hpp"

std::string get_phrase()
{
   std::ifstream ifs("wof.1-20.txt");

   if ( !ifs ) { std::cerr << "Cannot open file\n";  exit(1); }

   std::string phrase;

   int num_phrases { };

   while ( std::getline(ifs, phrase) ) { num_phrases++; }

   // reset the file to the beginning
   ifs.clear();
   ifs.seekg(0, std::ios::beg);

   // skips the first two line, the phrase list starts at line 3
   int ran_phrase { rtk::rand(3, num_phrases) };

   for ( size_t itr { }; itr < ran_phrase; ++itr )
   {
      std::getline(ifs, phrase);
   }

   return phrase;
}
int main()
{
   rtk::srand();

   std::string phrase { get_phrase() };

   std::cout << phrase << '\n';
}