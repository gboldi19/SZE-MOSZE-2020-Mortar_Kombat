# SZE-MOSZE-2020-Mortar_Kombat

This program simulates a turn based fight between two characters.  

## Input instructions
### ./a.out
In order to be able to use the "a.out" command, you must compile all the files in the scope with ".cpp" extension first, which is generating the "a.out" file if no output name is specified.
After compiling the user can refer to the executable from the current working directory with "./a.out" followed by the given arguments.  
*The proper synthax is:*  
./a.out <character_one_name> <character_one_HP> <character_one_DMG> <character_two_name> <character_two_HP> <character_two_DMG>  
- <character_one_name>: name of the first character (no whitespaces allowed)  
- <character_one_HP>: hit points of the first character (only integer numbers allowed)  
- <character_one_DMG>: damage points of the first character (only integer numbers allowed)  
- <character_two_name>: name of the second characer (no whitespaces allowed)  
- <character_two_HP>: hit points of the second character (only integer numbers allowed)  
- <character_two_DMG>: damage points of the second character (only integer numbers allowed)  

Attributes must be devided by whitespaces.  
Every other first words result in an error, and every additional words are not taken into account.  

## Simulation
The characters fight in turns back and forth repeatedly, starting with the first character.  
By every attack, the attacked character's hit points reduce by the attacker character's damage points.  
The simulation ends when one reaches 0 hit points.  
The program announces the loser and winner, then stops.  
