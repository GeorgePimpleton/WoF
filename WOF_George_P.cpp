#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

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
   ifs.seekg(std::ios::beg);

   // skips the first two line, the phrase list starts at line 3
   int ran_phrase { rtk::rand(3, num_phrases) };

   for ( size_t itr { }; itr < ran_phrase; ++itr )
   {
      std::getline(ifs, phrase);
   }

   return phrase;
}

std::string guess_phrase(std::string phrase)
{
   std::string guess { };

   for ( int itr { }; itr < phrase.size(); ++itr )
   {
      char type = phrase[itr];

      if ( ::isalpha(type) )
      {
         guess += '#';
      }
      else if ( ::ispunct(type) )
      {
         guess += type;
      }
      else
      {
         guess += ' ';
      }
   }
   return guess;
}

int main()
{
   rtk::srand();

   std::string phrase { get_phrase() };

   std::cout << phrase << '\n';

   std::string init_guess { guess_phrase(phrase) };

   std::cout << init_guess << '\n';
}