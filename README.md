# SZE-MOSZE-2020-Mortar_Kombat

This program simulates a turn based fight between a regular character and a player.  

## Input instructions
### ./a.out
In order to be able to use the `a.out` command, you must compile all the files in the scope with `.cpp` extension first, which is generating the `a.out` file if no output name is specified.<br>After compiling the user can refer to the executable from the current working directory with `./a.out` followed by the given arguments.  
<br>***The proper synthax is:***  
./a.out <character_attributes_json_file_1> <player_attributes_json_file_2>  
   
Differring number of arguments and non-existent files throw error.
### '.json' format example:
```
{
  "name" : "Kakarott",
  "hp" : 43,
  "dmg" : 9
}
```

## Simulation
The characters fight in turns back and forth repeatedly, starting with the regular character.  
By every attack, the attacked character's hit points reduce by the attacker character's damage points.   
For every damage point the player inflicts it gains an experience point.   
100 experience points cause the player to level up resulting in:
- 10% more maximum hit points (rounded)   
- 10% more damage points   
- instant hit point regeneration   
The simulation ends when one reaches 0 hit points.  
The program announces the winner and it's remaining HP, then stops.  

Documentation: https://teaching-projects.github.io/SZE-MOSZE-2020-Mortar_Kombat/
