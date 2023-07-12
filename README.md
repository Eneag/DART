# DART
Source code for DART rockets


Naming conventions:
 - Variables: camelCase 	(first word lower case, all other upper case, no spaces)
 - Functions: camelCase() 	(see above)
 - Constants: UPPER_CASE 	(all upper case and different words connected by '_' )
 - Tabs: C_Tab_Name		(letter in alphabetical order followed by name of the tab es:_Tab_Name)

Other conventions:
 - Avoid String class

States:
 - 0: detect liftoff
 - 1: flight
 - 2: prarachute ejection
 - 3: descent
 - 4: landed
