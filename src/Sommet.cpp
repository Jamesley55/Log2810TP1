#include "Sommet.h"

Sommet::Sommet() : identifiant_(""), type_(Constante::Type::Rien)

{
}

Sommet::Sommet(std::string identifiant, Constante::Type type) : identifiant_(identifiant), type_(type)

{
}

Sommet::Sommet(std::string identifiant, std::string type)

{
    identifiant_ = identifiant;
    if (type == "hybrid")
    {
        type_ = Constante::Type::Hybride;
    }
    else if (type == "electrique")
    {
        type_ = Constante::Type::Electrique;
    }
    else if (type == "essence")
    {
        type_ = Constante::Type::Essence;
    }
    else
    {
        type_ = Constante::Type::Rien;
    }
}
Sommet::Sommet(const Sommet &sommet)

{
    identifiant_ = sommet.identifiant_;
    type_ = sommet.type_;
}

Constante::Type Sommet::getTypeEnumeration() const
{
    return type_;
}

std::string Sommet::getType() const
{
    switch (type_)
    {
    case Constante::Type::Hybride:
        return "Hybride";
    case Constante::Type::Electrique:
        return "Electrique";
    case Constante::Type::Essence:
        return "Essence";

    default:
        return "Rien";
    }
}

std::string Sommet::getIdentifiant() const
{
    return identifiant_;
}

std::ostream &operator<<(std::ostream &os, const Sommet &sommet)
{
    os << "station: " << sommet.getIdentifiant() << ", type: " << sommet.getType() << ", ";
    return os;
}

bool Sommet::operator==(const Sommet &sommet) const
{
    return (identifiant_ == sommet.identifiant_) && (type_ == sommet.type_);
}

bool Sommet::operator!=(const Sommet &sommet) const
{
    return !operator==(sommet);
}

bool Sommet::operator<(const Sommet &sommet) const
{
    return (identifiant_ < sommet.identifiant_);
}