#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>


#define MAX_ENTITIES 700

class Entity 
{
public:

	Entity() = default;

private:

	
};
class Component 
{
	Component(std::string ID) 
	{
		
	}
};
//template<typename T>
class ComponentManager 
{
public:

	template <typename T>
	void AddComponent(std::unordered_map<std::string, T>& componentArr, const T& component, const std::string& ID)
	{
		// Check if the component already exists in the array
		if (componentArr.find(ID) != componentArr.end())
		{
			std::cout << "Component already in array" << std::endl;
			return;
		}

		// Add the component to the map
		componentArr.emplace(ID, component);
		std::cout << "Component added with ID: " << ID << std::endl;
	}
	template <typename T>
	T GetComponent(std::unordered_map<std::string, T>& componentArr, const std::string& ID)
	{
		// Check if the component exists in the map
		auto it = componentArr.find(ID);
		if (it == componentArr.end())
		{
			std::cout << "Component not in array" << std::endl;
			return T();  // Return a default-constructed T if not found
		}

		// Return the component
		return it->second;
	}
	template<typename T>
	void DeleteComponent(std::unordered_map<std::string, T>& componentArr, const std::string& ID)
	{
		// Check if the component exists in the array
		auto it = componentArr.find(ID);
		if (it != componentArr.end())
		{
			// Remove the component
			componentArr.erase(it);
			std::cout << "Component with ID: " << ID << " has been deleted." << std::endl;
		}
		else
		{
			std::cout << "Component with ID: " << ID << " not found." << std::endl;
		}
	}
};
