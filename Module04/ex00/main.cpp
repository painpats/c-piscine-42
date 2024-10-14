#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "ANIMALS" << std::endl;
	std::cout << "-------" << std::endl;
	const Animal* meta = new Animal("yeah");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	std::cout << "\nWRONG ANIMALS" << std::endl;
	std::cout << "-------------" << std::endl;
	const WrongAnimal* gamma = new WrongAnimal("yeah");
	const WrongAnimal* b = new WrongCat();
	std::cout << b->getType() << " " << std::endl;
	b->makeSound(); //will output the cat sound!
	gamma->makeSound();
	delete b;
	delete gamma;
	return 0;
}
