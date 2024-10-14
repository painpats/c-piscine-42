#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "CREATION OF ANIMALS" << std::endl;
	std::cout << "-------------------" << std::endl;
	const Animal*	animal[4];
	for (int i=0 ; i<4 ; i++)
	{
		if (i < 2)
			animal[i] = new Dog();
		else if (i >= 2)
			animal[i] = new Cat();
	}

	std::cout << "\nTCHAO ANIMALS" << std::endl;
	std::cout << "-------------" << std::endl;
	for (int i=0 ; i<4 ; i++) {
		delete animal[i];
	}

	std::cout << "\nMORE DOGGO COMING" << std::endl;
	std::cout << "-----------------" << std::endl;
	Dog*	snoop = new Dog();
	snoop->getBrain().showIdea(0);
	snoop->getBrain().setIdea("A T-Bone !");
	snoop->getBrain().showIdea(0);
	snoop->getBrain().showIdea(1);
	Dog*	dog = new Dog(*snoop);
	dog->getBrain().setIdea("Ooh a bee :o");
	dog->getBrain().showIdea(0);
	dog->getBrain().showIdea(1);
	snoop->getBrain().showIdea(1);
	delete dog;
	delete snoop;

	return 0;
}
