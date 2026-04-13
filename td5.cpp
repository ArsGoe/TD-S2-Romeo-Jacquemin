#include <iterator>
#include <numeric>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>

using namespace std::literals;



size_t folding_string_hash(std::string const& s, size_t max){
   int sum = 0;
   std::hash<char> h;
   for(char c : s) {
      std::cout << h(c) << std::endl;
      sum += h(c);
   }
   return sum % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
   int sum = 0;
   int count = 1;
   std::hash<char> h;
   for(char c : s) {
      std::cout << h(c) << std::endl;
      sum += h(c) * count;
      count++;
   }
   return sum % max;
}

enum Direction{
   HAUT,
   BAS,
   GAUCHE,
   DROITE
};

Direction turn_right(Direction dir) {
   if( dir == Direction::HAUT) {
      return Direction::DROITE;
   }
   else if (Direction::BAS) {
      return Direction::GAUCHE;
   }
   else if (Direction::DROITE) {
      return Direction::BAS;
   }
   else if (Direction::GAUCHE) {
      return Direction::HAUT;
   }
}

struct Position{
   int x;
   int y;

   Position() {
   }

   Position(int x, int y) {
      this->x = x;
      this->y = y;
   }

   bool operator==(Position pos_b){
      return x == pos_b.x && y == pos_b.y;
   }

   std::ostream& operator<<(std::ostream&  stream){
      stream << "(" << x << "+" << y << ")";
      return stream;
   }

   Position* operator+=(Position pos_b){
      x += pos_b.x;
      y += pos_b.y;

      return this;
   }

   Position* operator+=(Direction dir){
      if( dir == Direction::HAUT) {
         y += 1; 
      }
      else if (Direction::BAS) {
         y -= 1;
      }
      else if (Direction::DROITE) {
         x += 1;
      }
      else if (Direction::GAUCHE) {
         x -= 1;
      }
      return this;
   }

   Position operator+(Direction dir){
      if( dir == Direction::HAUT) {
         return Position(x, y+1);
      }
      else if (dir == Direction::BAS) {
         return Position(x, y-1);
      }
      else if (dir == Direction::DROITE) {
         return Position(x+1, y);
      }
      else {
         return Position(x-1, y);
      }
   }
};

struct Map{
   int size_x, size_y, gardian_x, gardian_y;
   Direction guard_direction;
   std::vector<Position> obstacles;

   bool check_pos_is_obstacle(Position pos_a) {
      for(Position pos : obstacles) {
         if(pos_a == pos) {
            return true;
         }
      }
      return false;
   }
};

Map parse_input(std::istream& input_stream) {
   Map map;
   int number_of_lines = 0; 
   for (std::string line{}; std::getline(input_stream, line, '\n') and line != "";) {
       number_of_lines++;
       map.size_x = line.size();

       int i = 0;
       for(char c : line) {
         if (c == '#') {
            map.obstacles.push_back(Position(i, number_of_lines));
         }
         else if (c == '^') {
            map.gardian_x = i;
            map.gardian_y = number_of_lines;
            map.guard_direction = Direction::HAUT;
         }
         else if (c == "v") {
            map.gardian_x = i;
            map.gardian_y = number_of_lines;
            map.guard_direction = Direction::BAS;
         }
         else if ( c == "<") {
            map.gardian_x = i;
            map.gardian_y = number_of_lines;
            map.guard_direction = Direction::GAUCHE;
         }
         else if (c == ">") {
            map.gardian_x = i;
            map.gardian_y = number_of_lines;
            map.guard_direction = Direction::DROITE;
         }
         i++;
       }
   }
   map.size_y = number_of_lines;
   return map; 
}


namespace std {
   template <>
   struct hash<Position> {
       std::size_t operator()(const Position& pos) const {
           return (pos.x * 47 + pos.y * 33) % 444;
       }
   };
}

struct WalkResult {
   Position final_position;
   size_t steps_taken;
   std::unordered_set<Position> visited_positions;
};

WalkResult Simulation(Map map){
   WalkResult resu;
   Position current_gardian_pos = Position(map.gardian_x, map.gardian_y);
   bool stop = false
   while (!stop)
   {
      resu.visited_positions.insert(current_gardian_pos);
      if(map.check_pos_is_obstacle(current_gardian_pos + move_direction)){
         map.guard_direction = turn_right(map.guard_direction);
      }
      if(Direction::HAUT &&  (current_gardian_pos.y  + move_direction).y <= map.size_y){
         stop = true
      }
      if(Direction::BAS &&  (current_gardian_pos.y + move_direction).y < 0 ){
         stop = true
      }
      if(Direction::DROITE &&  (current_gardian_pos.x + move_direction).x <= map.size_x){
         stop = true
      }
      if(Direction::GAUCHE &&  (current_gardian_pos.y  + move_direction).x < 0){
         stop = true
      }
   }
   
   return resu;
}

int main(int argc, char const *argv[])
{
   
   return 0;
}
