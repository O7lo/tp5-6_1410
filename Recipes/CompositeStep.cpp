///////////////////////////////////////////////////////////
//  CompositeStep.cpp
//  Implementation of the Class CompositeStep
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#include "CompositeStep.h"

CompositeStep::CompositeStep(std::string title)
	: AbsStep(title, 0)
{
}

CompositeStep::CompositeStep(const CompositeStep& mdd)
	: AbsStep(mdd)
{
	for (auto component = mdd.cbegin(); component != mdd.cend(); component++)
	{
		addRecipeComponent(*component);
	}
}

CompositeStep* CompositeStep::clone() const
{
	return new CompositeStep(*this);
}

RecipeComponentIterator CompositeStep::begin() {

	return m_stepsContainer.begin();
}


RecipeComponentIterator_const CompositeStep::cbegin() const {

	return m_stepsContainer.cbegin();
}


RecipeComponentIterator_const CompositeStep::cend() const 
{
	return m_stepsContainer.cend();
}

RecipeComponentIterator CompositeStep::end() 
{
	return  m_stepsContainer.end();
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsStep& step = dynamic_cast<const AbsStep&>(member);
	return addRecipeComponent(step);
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsStep& member)
{
	m_stepsContainer.push_back(std::unique_ptr<AbsRecipeComponent> (member.clone()));
	return *m_stepsContainer.back();
}

void CompositeStep::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	m_stepsContainer.erase(child);
}

void CompositeStep::deleteAllComponents(void)
{
	m_stepsContainer.clear();
}

int CompositeStep::getDuration() const
{
	int duration = m_duration;
	for (auto it = m_stepsContainer.cbegin(); it != m_stepsContainer.cend(); it++) {
		duration += (*it)->getDuration();
	}
	return duration;
}

std::ostream& CompositeStep::printToStream(std::ostream& o) const 
{
	o << "Category: " << getDescription() << std::endl;
	m_indent++;
	int stepNb = 1;
	for (auto it = m_stepsContainer.cbegin(); it != m_stepsContainer.cend(); it++) {
		indent(o);
		o << stepNb << " " << *it << std::endl;
		stepNb++;
	}
	m_indent--;
	return o;
}
