# Organized
An EPITECH project about linked lists, sorting algorithms and optimization

# Usage

First, clone the project
```bash
git clone --dephth 1 git@github.com:inkurey-22/organized.git
```

Then, go to the project directory
```bash
cd organized
```

You can now compile and run the project
```bash
make
./organized or ./organize_bonus
```

# Features

You have 4 commands in this shell :
- `add [TYPE] [name]` : Add a new element to the list
- `del [ID]` : Delete an element from the list
- `disp` : Display the list
- `sort [criteria]` : Sort the list by the criteria

Available types are :
- WIRE
- ACTUATOR
- DEVICE
- PROCESSOR
- SENSOR
These types are the only one that can be assigned to a new element.
An unknown element will trigger an error and exit the program with code 84.

Available criteria are :
- ID
- TYPE
- NAME
Each criteria can be assigned the -r flag to reverse the sorting order.
Again, any unknown criteria will trigger an error and exit the program with code 84.