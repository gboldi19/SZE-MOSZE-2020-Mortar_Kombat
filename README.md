# SZE-MOSZE-2020-Mortar_Kombat  

This program simulates a turn based fight between two characters.  

## Input instructions  
### ./a.out  
*Using the ./a.out command, the User can create two characters with the following synthax:*  
./a.out <char1_name> <char1_HP> <char1_DMG> <char2_name> <char2_HP> <char2_DMG>  
- <char1_name>: name of the first character (no whitespaces allowed)  
- <char1_HP>: health points of the first character (only integer numbers allowed)  
- <char1_DMG>: damage points of the first character (only integer numbers allowed)  
- <char2_name>: name of the second characer (no whitespaces allowed)  
- <char2_HP>: health points of the second character (only integer numbers allowed)  
- <char2_DMG>: damage points of the second character (only integer numbers allowed)  

Attributes must be devided by whitespaces.  
Every other first words result in an error, and every additional words are not taken into account.  

## Simulation  
The characters fights in turns back and forth repeatedly, starting with the first character.  
By every attack, the attacked character's health points reduce by the attacker character's damage points.  
The simulation ends when one reaches 0 health points.  
The program then announces the looser and winner and stops.
