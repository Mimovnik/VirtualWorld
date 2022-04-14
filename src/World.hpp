 #ifndef WORLD_H
 #define WORLD_H

 class World{
     char* name;

     public:
     
     World(){
         name = "World";
     }

     char* getName();
 };

 #endif