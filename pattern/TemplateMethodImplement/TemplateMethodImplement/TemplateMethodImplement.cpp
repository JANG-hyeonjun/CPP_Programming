// TemplateMethodImplement.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

namespace RamenRecipe
{
	class BasicRamenRecipe
	{
	public:
		virtual void cookRamen()
		{
			boilwater();
			addRamen();
			addons();
			wait();
		}
	protected:
		virtual void boilwater()
		{
			std::cout << "boil 550ml of water" << std::endl;
		}
		virtual void addRamen()
		{
			std::cout << "add noodles, soup Base, flakes" << std::endl;
		}
		virtual void addons() 
		{
			//to do nothing.....
		}
		virtual void wait()
		{
			std::cout << "cook for 4min 30s" << std::endl;
		}
	};

	class NocopeRecipe : public BasicRamenRecipe
	{
	protected:
		virtual void addons() override
		{
			std::cout << "add onions" << std::endl;
		}
	};

	class GrandmaRecipe : public BasicRamenRecipe
	{
	protected:
		virtual void boilwater() override
		{
			std::cout << "boil 1000ml of water" << std::endl;
		}

		virtual void wait() override
		{
			std::cout << "cook for 10min" << std::endl;
		}
	};
}

int main()
{
	RamenRecipe::BasicRamenRecipe* basiceRecipe = new RamenRecipe::BasicRamenRecipe;
	basiceRecipe->cookRamen();

	std::cout << "next Recipe method" << std::endl << std::endl;

	RamenRecipe::NocopeRecipe* nocopeRecipe = new RamenRecipe::NocopeRecipe;
	nocopeRecipe->cookRamen();

	std::cout << "next Recipe method" << std::endl << std::endl;

	RamenRecipe::GrandmaRecipe* grandmaRecipe = new RamenRecipe::GrandmaRecipe;
	grandmaRecipe->cookRamen();

	return EXIT_SUCCESS;
}

