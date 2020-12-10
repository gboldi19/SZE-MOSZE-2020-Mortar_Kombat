# SZE-MOSZE-2020-Mortar_Kombat

This program simulates a turn based fight between a hero and a some monsters.  
  
## Input instructions  
### Argument  
Use an argument when running the compiled executable. The argument should be a path to a .json file describing a scenario.  
There must be a "hero" and a "monsters" key with paths to all the entities' .json files.  
```   
{
    "hero" : "Dark_Wanderer.json",
    "monsters" : ["Fallen.json", "Fallen.json", "Zombie.json", "Fallen.json", "Blood_Raven.json"]
} 
```  
### Entities  
All entities' .json files must contain specific keys, as in the following examples:
#### Hero
```   
{
    "name" : "Prince Aidan of Khanduras",
    "base_health_points" : 30,
    "damage" : 3,
    "magical-damage" : 0,
    "defense": 1,
    "defense_bonus_per_level" : 1,
    "base_attack_cooldown" : 1.1,
    "experience_per_level" : 20,
    "health_point_bonus_per_level" : 5,
    "damage_bonus_per_level" : 1,
    "cooldown_multiplier_per_level": 0.9
} 
```  
#### Monster
```   
{  
    "name" : "Zombie",
    "health_points": 10,
    "damage" : 1,
    "magical-damage" : 0,
    "attack_cooldown": 2.8,
    "defense" :  0,
}  
```  
  
## Simulation  
### Fight
The characters fight in turns back and forth repeatedly.  
By every attack, the attacked character's hit points reduce by the attacker character's damage points.   
For every damage point the hero inflicts it gains an experience point.   
After a given amount of experience points the hero levels up resulting in:
- Given amount of increase in maximum hit points   
- Given amount of increase in damage points   
- Less damage cooldown by given ratio
- Instant hit point regeneration   
The simulation ends when one reaches 0 hit points.  
## Scenario  
The hero fights throught all the monsters one by one. 
Before every fight the name, level and the opponent's name is printed.  
If either any of the monster or the hero has no hit points left, the simulation ends.  
The hero's name, level, hit points, maximum hit points, damage points, attack cooldown are printed, and then the program exits.   
  
Documentation: https://teaching-projects.github.io/SZE-MOSZE-2020-Mortar_Kombat/   
