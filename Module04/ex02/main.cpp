#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "CREATION OF ANIMALS" << std::endl;
	std::cout << "-------------------" << std::endl;
	const AAnimal*	aanimal[4];
	for (int i=0 ; i<4 ; i++)
	{
		if (i < 2)
			aanimal[i] = new Dog();
		else if (i >= 2)
			aanimal[i] = new Cat();
	}
	//const AAnimal animal;
	std::cout << "\nANIMALS HAVE BRAIN !" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i=0 ; i<4 ; i++)
	{
		if (aanimal[i]->getType().compare("Dog") == 0)
		{
			aanimal[i]->getBrain().setIdea("Bone bone bone");
			aanimal[i]->getBrain().showIdea(0);
		}		
		if (aanimal[i]->getType().compare("Cat") == 0)
		{
			aanimal[i]->getBrain().setIdea("Murder murder murder");
			aanimal[i]->getBrain().showIdea(0);
		}
	}

	std::cout << "\nTCHAO ANIMALS" << std::endl;
	std::cout << "-------------" << std::endl;
	for (int i=0 ; i<4 ; i++) {
		delete aanimal[i];
	}

	return 0;
}
