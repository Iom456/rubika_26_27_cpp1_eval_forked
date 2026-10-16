# Theorical questions

[Back to main README](../README.md)

1. What are the steps involved in the compilation process?

> -The Linker : create dll and libraries for all the link between the .obj 

2. What is the difference between a declaration and a definition?

> -The difference is that a declaration simply indicates the existence of a variable so that it can be used, while a definition allows the script to directly replace the “word” with the method that defines it.

3. What is the difference between passing a parameter by value, by reference, and by pointer?

> -Voici ce que fait chauqe terme :
> - passer une valeur : celle ci est copié et n'est pas directement utilisée dans la fonction
> - passer une reference : pas de copie, on manipule directement la variable passée, qui continuera d'exister hors du scope de la fonction
> - passer un pointeur : on passe l'adresse mémoire de la variable, on pourra donc l'utiliser comme une reference ou directement modifier son adresse

4. What is the difference between the stack and the heap?

> - The heap is used to store variables that the program is not aware of at compile time (variable creation, dynamic allocation, lists, etc.); unlike the stack, const variables are a good example of this.

5. What is the difference between struct and class in C++?

> -In the struct, all the fields are automatically public, it's the opposite for the class;

6. What is the difference between the public, protected, and private access specifiers?

> - public : other classes and child can use what's inside
> - protected : only the children can use them
> - private : only this class can use them

7. What is a pure virtual function? What effect does it have on a class?

> - It's a function with no implementation, the objective is to be overrided by the inheritor. Moslty used in abstract class. 

8. Briefly explain the diamond problem in multiple inheritance.

> - 

9. Name the different containers studied in class and describe the strengths and weaknesses of each.

> - Vector :
>  + positive : flexible, allows for advance allocation to a specific order
>  + negative : costly expansion
> - Array :
>  + positive : stable, fast
>  + negative : not very flexible, the size need to be known at compilation
> - List :
>  + positive : super flexible
>  + negative : the slowest container
> - Dictionary :
>  + positive : have fast acces o(1), can associate key and value
>  + negative : need key and a value
> - Queue :
>  + positive : stable
>  + negative : the order matter and it's not flexible
> - Stack :
>  + positive : stable
>  + negative : the order matter and it's not flexible
> - Hashset :
>  + positive :have the fastest acces
>  + negative : no order

10. For each of the following scenarios, identify the most appropriate container and justify your choice.
- You need to store the top ten scores in a game. The number of elements is known and will never change.
> - It depend of the score need to be associated with the player, if it's the case, we can use a dictionary and reserve the memory needed for 10 top score. If we don't need the player, we can just use an array.
- You need to manage a queue of tasks that must be executed in the order they arrive.
> - We can use a Queue, first in, fist out.
- You frequently need to insert and remove elements in the middle of a sequence.
> - This action is expensive, I think the best container is vector, but we can do that in list to.
- You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter.
> - A Hashset  seem like the best option, it does not have order and the access linear.
- You need to keep track of actions so that the most recent action can be undone before earlier actions.
> - A stack look like the good choice here, first in, last out.
- You need to manage a collection of players whose number can change over time, with frequent read and traversal operations.
> - A vector can be used here, 
- You need to associate each student ID with a grade and retrieve a grade quickly using the student ID.
> - For this, a dictionary seems to be the right choice, the key will be the student ID, and the value will be the student.