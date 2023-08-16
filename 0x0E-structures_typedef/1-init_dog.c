#ifndef DOG_H
#define DOG_H

/**
 * init_dog - initializes a dog 
 * @d: the dog to init 
 * @name: the dog's name
 * @owner: owner's name
 *
 * Return: void.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
         if (d)
         {
                 d->name = name;
                 d->age = age;
                 d->owner = name;
          }
}
