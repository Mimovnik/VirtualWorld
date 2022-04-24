#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Organism.hpp"

class Animal : public Organism {
   protected:
   public:
   Animal(int strenght, int initiative, Vector position, char skin);
   void action() override{

   };
   void collide() override{
       
   };
   void render(World world) override{
       
   };
};

#endif