///////////////////////////////////////////////////////////
//  Recipe.cpp
//  Implementation of the Class Recipe
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "Recipe.h"

Recipe::Recipe(std::string title)
    : AbsIngredient(title,0), m_steps("Steps:")
{
}

Recipe::Recipe(const Recipe& mdd)
    : AbsIngredient(mdd), m_steps(mdd.m_steps)
{
	for (auto component = mdd.cbegin(); component != mdd.cend(); component++)
	{
		addRecipeComponent(*component);
	}
}

Recipe* Recipe::clone() const
{
	return new Recipe(*this);
}

AbsRecipeComponent& Recipe::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsIngredient& ingredient = dynamic_cast<const AbsIngredient&>(member);
	return addIngredient(ingredient);
}

AbsRecipeComponent& Recipe::addIngredient(const AbsRecipeComponent& member)
{
	const AbsIngredient& ingredient = dynamic_cast<const AbsIngredient&>(member);
	return addIngredient(ingredient);
}

AbsRecipeComponent& Recipe::addIngredient(const AbsIngredient& ingredient)
{
	m_ingredients.push_back(std::unique_ptr<AbsRecipeComponent>(ingredient.clone()));
	return *m_ingredients.back();
}

AbsRecipeComponent& Recipe::addStep(const AbsStep& step)
{
	return m_steps.addRecipeComponent(step);
}

RecipeComponentIterator Recipe::begin(){

	return m_ingredients.begin();
}


RecipeComponentIterator_const Recipe::cbegin() const
{
	return m_ingredients.cbegin();
}


RecipeComponentIterator_const Recipe::cend() const
{
	return m_ingredients.cend();
}

RecipeComponentIterator Recipe::end()
{
	return m_ingredients.end();
}

RecipeComponentIterator Recipe::begin_step()
{
	return m_steps.begin();
}

RecipeComponentIterator_const Recipe::cbegin_step() const
{
	return m_steps.cbegin();
}

RecipeComponentIterator_const Recipe::cend_step() const
{
	return m_steps.cend();
}

RecipeComponentIterator Recipe::end_step()
{
	return m_steps.end();
}


void Recipe::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	m_ingredients.erase(child);
}

void Recipe::deleteIngredient(RecipeComponentIterator_const ingredient)
{
	m_ingredients.erase(ingredient);
}

void Recipe::deleteStep(RecipeComponentIterator_const step)
{
	m_steps.deleteRecipeComponent(step);
}

void Recipe::deleteAllComponents()
{
	m_ingredients.clear();
	m_steps.deleteAllComponents();
}

std::ostream& Recipe::printToStream(std::ostream& o) const 
{
	o << "Recipe: " << m_description << std::endl;
	indent(o);
	o << "Ingredients: " << std::endl;
	m_indent++;
	for (auto it = m_ingredients.cbegin(); it != m_ingredients.cend(); it++) {
		indent(o);
		o << *it->get();
	}
	m_indent--;
	indent(o);
	o << "Steps:" << std::endl;
	m_indent++;
	int stepNb = 1;
	for (auto it = m_steps.cbegin(); it != m_steps.cend(); it++) {
		indent(o);
		o << stepNb << " " << *it;
		stepNb++;
	}
	m_indent--;
	return o;
}