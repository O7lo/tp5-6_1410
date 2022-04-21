///////////////////////////////////////////////////////////
//  ComputeTimeVisitor.cpp
//  Implementation of the Class ComputeTimeVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#include "ComputeTimeVisitor.h"
#include "CompositeStep.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "SingleStep.h"

ComputeTimeVisitor::ComputeTimeVisitor()
	: m_preparationTime(0), m_realizationTime(0)
{
}

void ComputeTimeVisitor::processCompositeStep(CompositeStep& composite)
{
	// � compl�ter: it�rer sur les enfants du composite et appliquer le visiteur � chaque enfant
}

void ComputeTimeVisitor::processIngredient(Ingredient& ingredient)
{
	// � compl�ter: ajouter la dur�e de pr�paration de l'ingr�dient au temps total de pr�paration
}

void ComputeTimeVisitor::processRecipe(Recipe& recipe)
{
	// � compl�ter: it�rer sur les ingr�dients et appliquer le visiteur � chaque enfant
	//              it�rer sur chaque �tape et appliquer le visiteur � chaque �tape
}

void ComputeTimeVisitor::processSingleStep(SingleStep& step)
{
	// � compl�ter: ajouter la dur�e de r�alisation de l'�tape au temps total de r�alisation
}
