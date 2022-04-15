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
	for (auto component = mdd.cbegin(); component != mdd.cend(); component++) 
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
	m_products.erase(child);
}

void Category::deleteAllComponents(void)
{
	m_products.clear();
}

const AbsProduct* Category::findProduct(std::string productName) const
{
	// itérer sur les éléments contenus dans la catégorie à la recherche d'un produit
	// portant le nom reçu en argument. Si aucun produit n'est trouvé on retourne nullptr
	const AbsProduct* foundProduct = nullptr;

	for (auto it = m_products.cbegin(); it != m_products.cend(); it++) {
		foundProduct = (*it)->findProduct(productName);
	}

	return foundProduct;
}

std::ostream & Category::printToStream(std::ostream & o) const
{
	// imprimer sur un stream une catégorie et ses produits
	o << "Category: " << getName() << std::endl;
	m_indent++;
	for (auto it = m_products.cbegin(); it != m_products.cend(); it++) {
		indent(o);
		o << *it << std::endl;
	}
	m_indent--;
	return o;
}

std::ostream & Category::indent(std::ostream & o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
