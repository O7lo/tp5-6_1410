#include <string>

#include "Category.h"
#include "AbsProduct.h"

int Category::m_indent = 0;

Category::Category(std::string name)
	: AbsCatalogComponent(name)
{
}

Category::Category(const Category & mdd)
	: AbsCatalogComponent(mdd.m_name)
{
	for (CatalogComponentIterator_const component = Category::cbegin();
		component != Category::cend();
		component++) 
	{
		addCatalogComponent(*component);
	}
}

Category * Category::clone(void) const
{
	Category* cloneCategory = new Category(*this);
	return cloneCategory;
}

AbsCatalogComponent& Category::addCatalogComponent(const AbsCatalogComponent & member)
{
	std::unique_ptr<AbsCatalogComponent> cloneComponent (member.clone());
	m_products.push_back(move(cloneComponent));
	return *m_products.back();
}

CatalogComponentIterator Category::begin()
{
	return m_products.begin();
}

CatalogComponentIterator_const Category::cbegin() const
{
	return m_products.cbegin();
}

CatalogComponentIterator_const Category::cend() const
{
	return m_products.cend();
}

CatalogComponentIterator Category::end()
{
	return m_products.end();
}

void Category::deleteCatalogComponent(CatalogComponentIterator_const child)
{
	// � compl�ter pour �liminer de la cat�gorie l'�l�ment auquel r�f�re l'it�rateur
}

void Category::deleteAllComponents(void)
{
	// � compl�ter pour �liminer tous les �l�ments de la cat�gorie
}

const AbsProduct* Category::findProduct(std::string productName) const
{
	// � compl�ter pour it�rer sur les �l�ments contenus dans la cat�gorie � la recherche d'un produit
	// portant le nom re�u en argument. Si aucun produit n'est trouv� on retourne nullptr
	const AbsProduct* foundProduct = nullptr;

	// � compl�ter

	return foundProduct;
}

std::ostream & Category::printToStream(std::ostream & o) const
{
	// � compl�ter pour imprimer sur un stream une cat�gorie et ses produits
	return o;
}

std::ostream & Category::indent(std::ostream & o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
