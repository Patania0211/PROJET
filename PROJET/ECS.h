#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "ECS.h"
#include "components.h"

#define MAX_ENTITIES 700

class Entity 
{
public:
	virtual ~Entity() = default;
};
template<typename T>
class ComponentManager 
{
public:

	template <typename T>
	bool AddComponent(const T& component, const std::string& ID) {
		// Check if the component with the given ID already exists
		for (const auto& pair : componentArr) {
			if (pair.first == ID) {
				std::cout << "Component with ID: " << ID << " already exists." << std::endl;
				return false;
			}
		}
		// If ID does not exist, add the new component
		componentArr.emplace_back(ID, std::make_unique<T>(component));
		std::cout << "Component added with ID: " << ID << std::endl;
		return true; // Successfully added component
	}
	template <typename T>
	T GetComponent(const std::vector<std::pair<std::string, T>>& componentArr, const std::string& ID) {
		for (const auto& pair : componentArr) {
			if (pair.first == ID) {
				return pair.second;
			}
		}
		std::cout << "Component not in array" << std::endl;
		return T();  // Return a default-constructed T if not found
	}

	template<typename T>
	bool DeleteComponent(std::vector<std::pair<std::string, T>>& componentArr, const std::string& ID) {
		for (auto it = componentArr.begin(); it != componentArr.end(); ++it) {
			if (it->first == ID) {
				componentArr.erase(it);
				std::cout << "Component with ID: " << ID << " deleted." << std::endl;
				return true; // Successfully deleted component
			}
		}
		std::cout << "Component with ID: " << ID << " not found." << std::endl;
		return false; // Failed to delete component
	}

private:
	std::vector<std::pair<std::string, std::unique_ptr<Component>>> componentArr;
};
