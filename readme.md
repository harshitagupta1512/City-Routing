# City-Routing

### Instructions on Compilation

1. Clone this directory and `cd` into it.
2. Run the command `gcc main.c project.c & ./a.out`.

### Input format
The first line will have two space separated integers representing the number of places in the city i.e number of nodes in the city graph and the number of streets in the city i.e the number of edges in the city graph/map.\
`Number of places(int)` `Number of streets (int)`

Each of the next *Number of streets* lines gives the description of one of the streets in the given format.\
`Source_node_name(str)` `Destination_node_name` `Street_length(float)` `Number_of_lanes(int)` `Average_number_of_cars(int)` `Avergae_number_of_accidents(int)` `Speed_Limit(int)`

### Functionalities
*Assuming the graph (city map) is connected and undirected.*

User enters one of the following choices
```
   1.FIND THE SAFEST PATH
   2.FIND THE FASTEST PATH
   3.DELETE STREET IN THE CITY MAP
   4.CHANGE THE STREET DATA FOR ANY STREET
   5.EXIT
   Enter you choice(1/2/3/4/5/6)
```

1. If the user enters choice `1`. The program now prompts the user to enter his starting and destination location.
*The input format* would be\
`starting_location(string)` `ending_location(string)`

 The program will give the safest path between the entered locations.

2. If the user enters choice `2`. The program now prompts the user to enter his starting and destination location.
*The input format* would be\
`starting_location(string)` `ending_location(string)`

 The program will give the fastest path between the entered locations

3. If the user enters choice `3`. The program prompts the user to enter the source and destination node of the street he wishes to delete.\
The input format will be\
`starting_location(string)` `ending_location(string)`

The program will remove the street from the city map if any such street exists, if not it prints "no such street exits"
and continues.

4. If the user enters choice `4`. The program prompts the user to enter the starting and ending point of the street he wishes to change data for and the only data he can change for a street will be the average number of cars on the street per hour (that can change with time maybe due to some procession/accident/construction work etc).\
The input format will be\

`starting_location(string)` `ending_location(string)` `num_cars(int)`

The program will change the data for the street in the city map if any such street exists, if not it prints "no such street exits" and continues.

5.If the user enters choice `5`
The user exits from the program.

For the test cases we use a *testcase generator* that is a block of code which when given the num_places and num_streets gives us the parameters for numStreets different streets in appropriate range.

Here is a *sample test case* 
```
9 14
home b 625 4 137 6 93
b c 126 1 185 9 23
c d 961 4 22 9 95
d exam 590 2 92 4 98
exam f 957 2 167 9 62
f g 886 4 127 5 56
g h 246 1 275 9 64
h home 123 4 247 3 70
h b 578 1 188 3 83
h i 765 2 225 2 100
g i 733 3 119 1 75
i c 119 2 98 2 45
f c 659 1 275 9 57
f d 385 1 113 9 61
1
home exam
2
home exam
3
f g
4
h i 500
1
home exam
5
```
