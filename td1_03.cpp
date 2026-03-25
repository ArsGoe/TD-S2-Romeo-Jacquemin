#include <vector>
#include <iostream>
#include <algorithm>

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

}


void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
   size_t middle = (left + right) / 2;

   if(right - left <= 2) {
      merge_sort_merge(vec, left, middle, right);
   }
   else {
      merge_sort(vec, left, middle);
      merge_sort(vec, middle + 1, right);
      merge_sort_merge(vec, left, middle, right);
   }
   
}

void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}


int main(int argc, char const *argv[])
{
   std::vector<int> liste = {5, 2, 3, 5, 6, 7, 4, 2, 1};
   bubble_sort(liste);
   for(int i : liste) {
      std::cout << i << " ";
   }
   return 0;
}
