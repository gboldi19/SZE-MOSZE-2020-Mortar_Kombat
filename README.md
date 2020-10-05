# SZE-MOSZE-2020-Mortar_Kombat

This program simulates a turn based fight between two characters.  

## Input instructions
### ./a.out
In order to be able to use the `a.out` command, you must compile all the files in the scope with `.cpp` extension first, which is generating the `a.out` file if no output name is specified.<br>After compiling the user can refer to the executable from the current working directory with `./a.out` followed by the given arguments.  
<br>***The proper synthax is:***  
./a.out <character_attributes_json_file_1> <character_attributes_json_file_2>  
   
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
The characters fight in turns back and forth repeatedly, starting with the first character.  
By every attack, the attacked character's hit points reduce by the attacker character's damage points.  
The simulation ends when one reaches 0 hit points.  
The program announces the winner and it's remaining HP, then stops.  
