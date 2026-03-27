#include <iterator>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

void bubble_sort(std::vector<int> & vec) {
   for (int i = vec.size() - 1; i > 0; i--)
   {
      for (int j = 0; j < i; j++)
      {
         if (vec.at(j) > vec.at(j + 1))
         {
            std::swap(vec.at(j), vec.at(j + 1));
         }
      }
   }
}

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right) {
   int i = 0;
   int j = 0;

   std::vector <int> tmp = {};

   int size_a = middle - left + 1;
   int size_b = right - middle;

   while (i < size_a && j < size_b)
   {
      if (vec.at(left + i) > vec.at(middle + 1 + j))
      {
         tmp.push_back(vec.at(middle + 1 + j));
         j++;
      }
      else if (vec.at(left + i) < vec.at(middle + 1 + j)) {
         tmp.push_back(vec.at(left + i));
         i++;
      }
      else {
         tmp.push_back(vec.at(middle + 1 + j));
         tmp.push_back(vec.at(left + i));
         i++;
         j++;
      }
   }
   if (i == size_a)
   {
      while (j < size_b)
      {
         tmp.push_back(vec.at(middle + 1 + j));
         j++;
      }
   }
   if (j == size_b)
   {
      while (i < size_a)
      {
         tmp.push_back(vec.at(left + i));
         i++;
      }
   }
   
   int index = left;
   for(int number : tmp) {
      vec[index] = number;
      index++;
   }
}


void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
   if (right - left == 0)
      return;
   
   size_t middle = (left + right) / 2;

   merge_sort(vec, left, middle);
   merge_sort(vec, middle + 1, right);
   merge_sort_merge(vec, left, middle, right);
}

void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
   std::vector<int> vec(size);
   std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
   return vec;
}

bool search(std::vector<int> & vec, size_t left, size_t right, int value) {
   
   while (left + 1 != right)
   {
      int middle = (left + right) / 2;
      if (value == vec.at(middle))
      {
         return true;
      }
      else {
         if(value > vec.at(middle)) {
            left = middle;
         }
         else {
            right = middle;
         }
      }
   }
   return false;
}

bool search(std::vector<int> & vec, int i) {
   return search(vec, 0, vec.size(), i);
}


int main(int argc, char const *argv[])
{
   /*
   std::vector<int> first_list_to_sort = generate_random_vector(1000, 35);
   std::vector<int> second_list_to_sort = generate_random_vector(1000, 35);
   std::vector<int> third_list_to_sort = generate_random_vector(1000, 35);
   {
      ScopedTimer timer("nom du chronomètre 1");
      bubble_sort(first_list_to_sort);
   }
   {
      ScopedTimer timer("nom du chronomètre 2");
      merge_sort(second_list_to_sort);
   }
   {
      ScopedTimer timer("nom du chronomètre 3");
      std::sort(third_list_to_sort.begin(), third_list_to_sort.end());
   }
   
   std::vector<int> liste = {1, 2, 2, 3, 4, 5, 7, 8, 10, 12};
   std::cout << search(liste, 6) << std::endl;
   */
   return 0;
}
